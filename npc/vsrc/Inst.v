module Inst(
    input [31:0] PC,
    output [31:0] inst
);

import "DPI-C" function int get_inst(input int pc);
assign inst = get_inst(PC);

// InstMem #(
//     .ADDR_WIDTH(8),
//     .DATA_WIDTH(32)
// ) u_instmem (
//     .ReadAddr(PC[7:0]),
//     .ReadData(inst)
// );

endmodule

// module InstMem #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
//     input [ADDR_WIDTH-1:0] ReadAddr,
//     output [DATA_WIDTH-1:0] ReadData
// );
// reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

// assign ReadData = rf[ReadAddr];

// endmodule
