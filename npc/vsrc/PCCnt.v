module PCCnt(
    input clk,
    input rst,
    input [31:0] ReadData1,
    input [31:0] ImmExt,
    input [1:0] NPCSrcSel,
    output reg [31:0] PC
);

wire [31:0] NPC = ((NPCSrcSel[0] == 1'b0) ? PC : ReadData1) + ((NPCSrcSel[1] == 1'b0) ? 32'd4 : ImmExt);

always @(posedge clk) begin
    if(rst) PC <= 32'h80000000;
    else PC <= NPC;
end

endmodule
