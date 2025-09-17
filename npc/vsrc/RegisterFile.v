module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
    input clk,
    input [ADDR_WIDTH-1:0] ReadAddr1,
    input [ADDR_WIDTH-1:0] ReadAddr2,
    input [ADDR_WIDTH-1:0] WriteAddr,
    input [DATA_WIDTH-1:0] WriteData,
    input RegWrite,
    output [DATA_WIDTH-1:0] ReadData1,
    output [DATA_WIDTH-1:0] ReadData2,
    output [DATA_WIDTH-1:0] ReadData_a0
);
reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

always @(posedge clk) begin
    if (RegWrite)
     `   rf[WriteAddr] <= WriteData;
end

assign ReadData1 = (ReadAddr1 == 0) ? 0 : rf[ReadAddr1];
assign ReadData2 = (ReadAddr2 == 0) ? 0 : rf[ReadAddr2];
assign ReadData_a0 = rf[10];

export "DPI-C" function get_gpr;
function void get_gpr(output int out_gpr[16]);
    out_gpr[0] = 0;
    for (int i = 1; i < 16; i++) begin
        out_gpr[i] = rf[i];
    end
endfunction

endmodule
