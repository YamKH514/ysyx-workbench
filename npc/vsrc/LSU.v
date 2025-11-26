`include "common.vh"

module LSU(
    // idu_to_lsu_data_in lsu_we[0], lsu_w_mask[8:1], lsu_re[9], lsu_r_func[12:10]
    input       [12:0]  idu_to_lsu_data_in,
    input       [31:0]  lsu_r_addr_in,
    output  reg [31:0]  lsu_r_data_out,
    input       [31:0]  lsu_w_addr_in,
    input       [31:0]  lsu_w_data_in,

    output              sram_re_out,
    output      [31:0]  sram_r_addr_out,
    input       [31:0]  sram_r_data_in,
    output              sram_we_out,
    output      [31:0]  sram_w_addr_out,
    output      [31:0]  sram_w_data_out,
    output      [7:0]   sram_w_mask_out
);

reg         lsu_we_r;
reg [7:0]   lsu_w_mask_r;
reg         lsu_re_r;
reg [2:0]   lsu_r_func_r;
assign {lsu_r_func_r, lsu_re_r, lsu_w_mask_r, lsu_we_r} = idu_to_lsu_data_in;

reg     [31:0]  read_data_r;
reg     [1:0]   byte_off_r;
wire    [7:0]   data_b;
wire    [15:0]  data_h;

assign sram_re_out = lsu_re_r;
assign sram_r_addr_out = lsu_r_addr_in;
assign read_data_r = sram_r_data_in;
assign sram_we_out = lsu_we_r;
assign sram_w_addr_out = lsu_w_addr_in;
assign sram_w_data_out = lsu_w_data_in;
assign sram_w_mask_out = lsu_w_mask_r;

assign byte_off_r = lsu_r_addr_in[1:0];

assign data_b = {8{byte_off_r == 2'b00}} & read_data_r[7:0]  |
                {8{byte_off_r == 2'b01}} & read_data_r[15:8] |
                {8{byte_off_r == 2'b10}} & read_data_r[23:16]|
                {8{byte_off_r == 2'b11}} & read_data_r[31:24];

assign data_h = byte_off_r[1] == 1'b0 ? read_data_r[15:0] : read_data_r[31:16];

assign lsu_r_data_out = {32{lsu_r_func_r == `MEM_READ_FUNC_LBU}} & {24'b0, data_b[7:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LB}}  & {{24{data_b[7]}}, data_b[7:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LHU}} & {16'b0, data_h[15:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LH}}  & {{16{data_h[15]}}, data_h[15:0]} |
                        {32{lsu_r_func_r == `MEM_READ_FUNC_LW}}  & read_data_r ;

endmodule
