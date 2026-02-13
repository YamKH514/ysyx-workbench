module RegisterFile (
    input clk,
    input [ADDR_WIDTH-1:0] ReadAddr1,
    input [ADDR_WIDTH-1:0] ReadAddr2,
    input [ADDR_WIDTH-1:0] WriteAddr,
    input [DATA_WIDTH-1:0] WriteData,
    input RegWrite,
    output [DATA_WIDTH-1:0] ReadData1,
    output [DATA_WIDTH-1:0] ReadData2
);

parameter ADDR_WIDTH = 1;
parameter DATA_WIDTH = 1;

reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

always @(posedge clk) begin
    if (RegWrite)
        rf[WriteAddr] <= WriteData;
end

assign ReadData1 = {DATA_WIDTH{ReadAddr1}} & rf[ReadAddr1];
assign ReadData2 = {DATA_WIDTH{ReadAddr2}} & rf[ReadAddr2];

export "DPI-C" function get_gpr;
function void get_gpr(output int out_gpr[16]);
    out_gpr[0] = 0;
    for (int i = 1; i < 16; i++) begin
        out_gpr[i] = rf[i];
    end
endfunction

endmodule
