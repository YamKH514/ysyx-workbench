module GPR(
  input clk, wen,
  input [4:0] waddr, raddr,
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

module RegisterFile #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr, raddr,
  input wen,
  output [DATA_WIDTH-1:0] rdata
);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
  reg [DATA_WIDTH-1:0] get_reg_value = rf[raddr];

  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end

  assign rdata = get_reg_value;

endmodule
