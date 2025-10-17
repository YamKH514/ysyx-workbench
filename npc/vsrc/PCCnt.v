module PCCnt(
    input clk,
    input rst,
    input CMPRes,
    input [31:0] ReadData1,
    input [31:0] ImmExt,
    input [3:0] NPCSrcSel, // npc = pc+4(0000) pc+imm(0001) src1+imm(0011) trap_npc(0100) res=0,jump(10--) res=1,jump(11--)
    input [31:0] TrapNPC,
    output reg [31:0] PC,
    output reg [31:0] NPC
);

assign NPC =    (NPCSrcSel[3] == 1'b0) ?
                (NPCSrcSel[2] == 1'b1 ? TrapNPC : (((NPCSrcSel[1] == 1'b0) ? PC : ReadData1) + ((NPCSrcSel[0] == 1'b0) ? 32'd4 : ImmExt))) :
                (PC + ((NPCSrcSel[2] == CMPRes) ? ImmExt : 4));


always @(posedge clk) begin
    if(rst) PC <= 32'h80000000;
    else PC <= NPC;
end

endmodule
