module GPR(
  input clk,
  input wen,
  input [4:0] waddr,
  input [4:0] raddr,
  input [31:0] wdata,
  output [31:0] rdata
);

    RegisterFile #(5, 32) general_reg
    (
        .clk   	(clk    ),
        .wdata 	(wdata  ),
        .waddr 	(waddr  ),
        .wen   	(wen    ),
        .rdata  (rdata  ),
        .raddr  (raddr  )
    );

endmodule
