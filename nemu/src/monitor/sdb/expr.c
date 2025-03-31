/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory/vaddr.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_LEFT_BRACKET, TK_RIGHT_BRACKET, TK_NUM, TK_HEX_NUM, TK_REG, TK_NOT_EQ, TK_AND, TK_POINTER,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"0x[0-9a-fA-F]+", TK_HEX_NUM},
  {"$[a-zA-Z0-9]+", TK_REG},
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\-", '-'},         // sub
  {"\\*", '*'},         // mul
  {"\\/", '/'},         // div
  {"==", TK_EQ},        // equal
  {"!=", TK_NOT_EQ},
  {"&&", TK_AND},
  {"\\(", TK_LEFT_BRACKET},
  {"\\)", TK_RIGHT_BRACKET},
  {"[0-9]+", TK_NUM},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

word_t expr(char *e, bool *success);

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[1000] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case '+': case '-': case '*': case '/': case TK_LEFT_BRACKET: case TK_RIGHT_BRACKET: case TK_EQ: case TK_NOT_EQ: case TK_AND:
            tokens[nr_token].type = rules[i].token_type;
            nr_token ++;
            break;
          case TK_NUM: case TK_HEX_NUM: case TK_REG:
            assert(substr_len < 32);
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token ++;
            break;
          case TK_NOTYPE:
            break;
          default:
            printf("Unknow token type at position %d\n", position);
            return false;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

bool check_parentheses(int p, int q) {
  if (tokens[p].type != TK_LEFT_BRACKET || tokens[q].type != TK_RIGHT_BRACKET) {
    return false;
  }

  int cnt = 0;

  for(int i = p; i <= q; i++) {
    if(tokens[i].type == TK_LEFT_BRACKET) cnt ++;
    if(tokens[i].type == TK_RIGHT_BRACKET) cnt --;

    if(cnt == 0 && i < q) return false;
    if(cnt < 0) return false;
  }

  return cnt == 0;
}

int get_priority(int type) {
  switch(type) {
    case TK_AND: return 5;
    case TK_EQ: case TK_NOT_EQ: return 6;
    case '+': case '-': return 7;
    case '*': case '/': return 8;
    case TK_POINTER: return 9;
    default: return 10;
  }
}

word_t eval(int p, int q, bool *success) {
  *success = true;
  if (p > q) {
    printf("Bad expression.\n");
    *success = false;
    return 0;
  }
  else if (p == q) {
    if(tokens[p].type == TK_NUM) {
      return atoi(tokens[p].str);
    }
    else if(tokens[p].type == TK_HEX_NUM) {
      return strtoul(tokens[p].str, NULL, 16);
    }
    else if(tokens[p].type == TK_REG) {
      char reg[32];
      strcpy(reg, tokens[p].str + 1);
      return isa_reg_str2val(reg, success);
    }
    else {
      printf("Unknow Token Type.\n");
      *success = false;
      return 0;
    }
  }
  else if (check_parentheses(p, q) == true) {
    return eval(p + 1, q - 1, success);
  }
  else {
    int op = -1, lowest_priority = 10;
    int cnt = 0;

    for(int i = p; i <= q; i++) {
      if(tokens[i].type == TK_LEFT_BRACKET) cnt ++;
      if(tokens[i].type == TK_RIGHT_BRACKET) cnt --;

      if(cnt == 0) {
        int priority = get_priority(tokens[i].type);
        if(priority <= lowest_priority) {
          lowest_priority = priority;
          op = i;
        }
      }
    }

    if(op == -1) {
      printf("Cannot find out principal operator.\n");
      *success = false;
      return 0;
    }

    int val1 = 0;
    if(op != 0) val1 = eval(p, op - 1, success);
    int val2 = eval(op + 1, q, success);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/': 
        if(val2 == 0) {
          printf("ERROR: Not divisible by zero\n");
          *success = false;
          return 0;
        }
        return val1 / val2;
      case TK_EQ: return val1 == val2;
      case TK_NOT_EQ: return val1 != val2;
      case TK_AND: return val1 && val2;
      case TK_POINTER: return vaddr_read(val2, 4);
      default: assert(0);
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type == TK_LEFT_BRACKET || 
                                    tokens[i - 1].type == TK_EQ || tokens[i - 1].type == TK_NOT_EQ || 
                                    tokens[i - 1].type == TK_AND || tokens[i - 1].type == '+' || 
                                    tokens[i - 1].type == '-' || tokens[i - 1].type == '*' || 
                                    tokens[i - 1].type == '/')) {
        tokens[i].type = TK_POINTER;
    }
}

  return eval(0, nr_token - 1, success);
}
