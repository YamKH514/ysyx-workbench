module PCCnt(
    input clk,
    input rst,
    input CMPRes,
    input [31:0] ReadData1,
    input [31:0] ImmExt,
    input [3:0] NPCSrcSel, // npc = pc+4(0-00) pc+imm(0-01) src1+imm(0-11) res=0,jump(100-) res=1,jump(110-)
    input [2:0] InstType, // I(0) S(1) B(2) U(3) J(4) R(5)
    output reg [31:0] PC,
    output reg [31:0] NPC
);

assign NPC =    ((NPCSrcSel[1] == 1'b0) ? PC : ReadData1) + 
                {32{~NPCSrcSel[3]}} & ((NPCSrcSel[0] == 1'b0) ? 32'd4 : ImmExt) | {32{NPCSrcSel[3]}} & ((NPCSrcSel[2] == CMPRes) ? ImmExt : 32'd4);

always @(posedge clk) begin
    if(rst) PC <= 32'h80000000;
    else PC <= NPC;
end

endmodule
