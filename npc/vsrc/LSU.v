// `include "common.vh"

// module LSU(
    // input               clk,
    // input               rst,
    // input               lsu_re_in,
    // input       [31:0]  lsu_r_addr_in,
    // output  reg [31:0]  lsu_r_data_out,
    // input       [2:0]   lsu_r_func_in,
    // input               lsu_we_in,
    // input       [31:0]  lsu_w_addr_in,
    // input       [31:0]  lsu_w_data_in,
    // input       [7:0]   lsu_w_mask_in

    // input               lsu_valid_in,
    // output  reg         lsu_ready_out,

    // output  reg         mem_valid_out,
    // input               mem_ready_in,

    // output  reg         lsu_wbu_valid_out,
    // input               wbu_ready_in
// );

// reg [1:0]   state;
// reg [1:0]   next_state;

// always @(posedge lsu_clk_in) begin
//     if (lsu_rst_in) begin
//         state <= `LSU_S_IDLE;
//     end else begin
//         state <= next_state;
//     end
// end

// always @(*) begin
//     next_state = state;
//     lsu_ready_out = 1'b0;
//     mem_valid_out = 1'b0;
//     lsu_wbu_valid_out = 1'b0;
//     case (state)
//         `LSU_S_IDLE: begin
//             lsu_ready_out = 1'b1;
//             if (lsu_valid_in) begin
//                 mem_valid_out = 1'b1;
//                 if (mem_re_in) begin
//                     next_state = `LSU_S_WAIT_LOAD;
//                 end else if (mem_we_in) begin
//                     next_state = `LSU_S_WAIT_STORE;
//                 end
//             end
//         end
//         `LSU_S_WAIT_LOAD: begin
//             mem_valid_out = 1'b1;
//             if (mem_ready_in) begin
//                 lsu_wbu_valid_out = 1'b1;
//                 next_state = `LSU_S_WAIT_WB;
//             end
//         end
//         `LSU_S_WAIT_STORE: begin
//             mem_valid_out = 1'b1;
//             if (mem_ready_in) begin
//                 next_state = `LSU_S_IDLE;
//             end
//         end
//         `LSU_S_WAIT_WB: begin
//             lsu_wbu_valid_out = 1'b1;
//             if (wbu_ready_in) begin
//                 next_state = `LSU_S_IDLE;
//             end
//         end
//     endcase
// end

// endmodule
