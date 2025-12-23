module GPR(
    input               clk,
    input               gpr_we_in,
    input       [4:0]   gpr_w_addr_in,
    input       [31:0]  gpr_w_data_in,
    input       [4:0]   gpr_r_addr1_in,
    input       [4:0]   gpr_r_addr2_in,
    output  reg [31:0]  gpr_r_data1_out,
    output  reg [31:0]  gpr_r_data2_out
);

RegisterFile #(5, 32) u_RegisterFile
(
    .clk         	(clk            ),
    .ReadAddr1   	(gpr_r_addr1_in ),
    .ReadAddr2   	(gpr_r_addr2_in ),
    .WriteAddr   	(gpr_w_addr_in  ),
    .WriteData   	(gpr_w_data_in  ),
    .RegWrite    	(gpr_we_in      ),
    .ReadData1   	(gpr_r_data1_out),
    .ReadData2   	(gpr_r_data2_out)
);

endmodule
