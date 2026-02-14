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

reg [31:0] rf [16];

always @(posedge clk) begin
    if (gpr_we_in & gpr_w_addr_in != 5'b0) rf[gpr_w_addr_in[3:0]] <= gpr_w_data_in;
end

assign gpr_r_data1_out = rf[gpr_r_addr1_in[3:0]];
assign gpr_r_data2_out = rf[gpr_r_addr2_in[3:0]];

export "DPI-C" function get_gpr;
function void get_gpr(output int out_gpr[16]);
    out_gpr[0] = 0;
    for (int i = 1; i < 16; i++) begin
        out_gpr[i] = rf[i];
    end
endfunction

endmodule
