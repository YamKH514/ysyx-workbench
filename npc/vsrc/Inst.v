module Inst(
    input [31:0] PC,
    output [31:0] inst
);

import "DPI-C" function int get_inst(input int pc);
assign inst = get_inst(PC);

endmodule
