module GPR(
    input clk,
    input RegWrite,
    input [4:0] ReadAddr1,
    input [4:0] ReadAddr2,
    input [4:0] WriteAddr,
    input [31:0] WriteData,
    output [31:0] ReadData1,
    output [31:0] ReadData2,
    output [31:0] ReadData_a0,
    output [31:0] ReadData_a5
);

RegisterFile #(5, 32) u_RegisterFile
(
    .clk         	(clk          ),
    .ReadAddr1   	(ReadAddr1    ),
    .ReadAddr2   	(ReadAddr2    ),
    .WriteAddr   	(WriteAddr    ),
    .WriteData   	(WriteData    ),
    .RegWrite    	(RegWrite     ),
    .ReadData1   	(ReadData1    ),
    .ReadData2   	(ReadData2    ),
    .ReadData_a0 	(ReadData_a0  ),
    .ReadData_a5    (ReadData_a5  )
);

endmodule
