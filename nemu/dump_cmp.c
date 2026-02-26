#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    printf("START\n");
    FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7;
    uint8_t *mem1, *mem2, *mem3, *mem4, *mem5, *mem6, *mem7;
    mem1 = (char *)malloc(sizeof(uint8_t) * 0x8000000);
    mem2 = (char *)malloc(sizeof(uint8_t) * 0x8000000);
    mem3 = (char *)malloc(sizeof(uint8_t) * 0x8000000);
    mem4 = (char *)malloc(sizeof(uint8_t) * 0x8000000);
    mem5 = (char *)malloc(sizeof(uint8_t) * 0x8000000);
    mem6 = (char *)malloc(sizeof(uint8_t) * 0x8000000);
    mem7 = (char *)malloc(sizeof(uint8_t) * 0x8000000);

    fp1 = fopen("./mem_dump1.bin", "rb");
    fp2 = fopen("./mem_dump2.bin", "rb");
    fp3 = fopen("./mem_dump3.bin", "rb");
    fp4 = fopen("./mem_dump4.bin", "rb");
    fp5 = fopen("./mem_dump5.bin", "rb");
    fp6 = fopen("./mem_dump6.bin", "rb");
    fp7 = fopen("./mem_dump7.bin", "rb");
    fread(mem1, sizeof(uint8_t), 0x8000000, fp1);
    fread(mem2, sizeof(uint8_t), 0x8000000, fp2);
    fread(mem3, sizeof(uint8_t), 0x8000000, fp3);
    fread(mem4, sizeof(uint8_t), 0x8000000, fp4);
    fread(mem5, sizeof(uint8_t), 0x8000000, fp5);
    fread(mem6, sizeof(uint8_t), 0x8000000, fp6);
    fread(mem7, sizeof(uint8_t), 0x8000000, fp7);
    printf("bin files readed\n");

    for(int i = 0; i <= 0x8000000; i++) {
        if (mem1[i] == 0 & mem2[i] == 0 & mem3[i] == 0 & mem4[i] > 0 & mem4[i] > mem5[i] & mem5[i] > mem6[i] & mem7[i] == 0) {
            printf("Addr: 0x%08x\n",
                i + 0x80000000);
        }
    }
    free(mem1);
    free(mem2);
    free(mem3);

    return 0;
}
