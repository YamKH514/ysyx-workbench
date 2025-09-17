module Shifter(
    input   [31:0]  Src,
    input   [4:0]   Shamt,
    input   [1:0]   ShifterFunc, // SLL(00) SRL(01) SRA(11)
    output  [31:0]  ShifterRes
);

wire [31:0] LeftShifterRes;
wire [31:0] RightShifterRes;

assign ShifterRes = ShifterFunc[0] ? RightShifterRes : LeftShifterRes;

BarrelShifterLeft u_BarrelShifterLeft(
    .Src        (Src),
    .Shamt      (Shamt),
    .ShifterRes (LeftShifterRes)
);

BarrelShifterRight u_BarrelShifterRight(
    .Src        (Src),
    .Shamt      (Shamt),
    .LASel      (ShifterFunc[1]),
    .ShifterRes (RightShifterRes)
);

endmodule

/* verilator lint_off DECLFILENAME */
module BarrelShifterLeft(
    input   [31:0]  Src,
    input   [4:0]   Shamt,
    output  [31:0]  ShifterRes
);

reg [31:0] s0, s1, s2, s3;

assign s0         = Shamt[0] ? {Src[31 -  1 : 0], 1'b0}  : Src;
assign s1         = Shamt[1] ? {s0 [31 -  2 : 0], 2'b0}  : s0;
assign s2         = Shamt[2] ? {s1 [31 -  4 : 0], 4'b0}  : s1;
assign s3         = Shamt[3] ? {s2 [31 -  8 : 0], 8'b0}  : s2;
assign ShifterRes = Shamt[4] ? {s3 [31 - 16 : 0], 16'b0} : s3;

endmodule

/* verilator lint_off DECLFILENAME */
module BarrelShifterRight(
    input   [31:0]  Src,
    input   [4:0]   Shamt,
    input           LASel, // Logical(0) Arithmetic(1)
    output  [31:0]  ShifterRes
);

reg [31:0] s0, s1, s2, s3;
wire msb = LASel ? Src[31] : 1'b0;

assign s0         = Shamt[0] ? {{ 1{msb}}, Src[31 : 1]}  : Src;
assign s1         = Shamt[1] ? {{ 2{msb}}, s0 [31 : 2]}  : s0;
assign s2         = Shamt[2] ? {{ 4{msb}}, s1 [31 : 4]}  : s1;
assign s3         = Shamt[3] ? {{ 8{msb}}, s2 [31 : 8]}  : s2;
assign ShifterRes = Shamt[4] ? {{16{msb}}, s3 [31 : 16]} : s3;

endmodule
