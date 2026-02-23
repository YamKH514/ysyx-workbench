module GPR(
    input               clk,
    input               gpr_we_i,
    input       [4:0]   gpr_waddr_i,
    input       [31:0]  gpr_wdata_i,
    input       [4:0]   gpr_raddr1_i,
    input       [4:0]   gpr_raddr2_i,
    output  reg [31:0]  gpr_rdata1_o,
    output  reg [31:0]  gpr_rdata2_o
);

reg [31:0] rf [16];

always @(posedge clk) begin
    if (gpr_we_i & gpr_waddr_i != 5'b0) rf[gpr_waddr_i[3:0]] <= gpr_wdata_i;
end

assign gpr_rdata1_o = rf[gpr_raddr1_i[3:0]];
assign gpr_rdata2_o = rf[gpr_raddr2_i[3:0]];

export "DPI-C" function get_gpr;
function void get_gpr(output int out_gpr[16]);
    out_gpr[0] = 0;
    for (int i = 1; i < 16; i++) begin
        out_gpr[i] = rf[i];
    end
endfunction

endmodule
