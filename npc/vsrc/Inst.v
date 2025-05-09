module Inst(
    input [31:0] PC,
    output [31:0] inst
);

initial $display("Inst, PC = 0x%08x\n", PC);

import "DPI-C" function int get_inst(input int pc);
assign inst = get_inst(PC);

endmodule
