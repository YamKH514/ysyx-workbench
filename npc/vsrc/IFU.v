`include "common.vh"

module IFU(
    // input               rst,
    // input               clk,
    input       [31:0]  ifu_current_pc_in,
    output  reg [31:0]  ifu_req_addr_out,
    input       [31:0]  ifu_req_inst_in,
    output  reg [31:0]  ifu_inst_out

    // input               inst_sram_ready_in,
    // output  reg         inst_sram_valid_out,

    // input               idu_ready_in,
    // output  reg         idu_valid_out,

    // input               pc_cnt_ready_in
);

assign ifu_req_addr_out = ifu_current_pc_in;
assign ifu_inst_out = ifu_req_inst_in;

// reg         inst_sram_valid_r;
// reg         idu_valid_r;
// reg [31:0]  req_addr_r;
// reg [31:0]  req_inst_r;

// reg [1:0]   state;
// reg [1:0]   next_state;

// always @(posedge clk) begin
//     if (rst) begin
//         state <= `IFU_S_IDLE;
//     end else begin
//         state <= next_state;
//     end
// end

// always @(*) begin
//     next_state = state;
//     case (state)
//         `IFU_S_IDLE: begin
//             if (pc_cnt_ready_in) begin
//                 next_state = `IFU_S_WAIT_SRAM;
//                 inst_sram_valid_out = 1'b1;
//                 ifu_req_addr_out = ifu_current_pc_in;
//             end
//         end
//         `IFU_S_WAIT_SRAM: begin
//             if (inst_sram_ready_in) begin
//                 next_state = `IFU_S_WAIT_IDU;
//                 inst_sram_valid_out = 1'b0;
//                 idu_valid_out = 1'b1;
//                 ifu_inst_out = ifu_req_inst_in;
//             end
//         end
//         `IFU_S_WAIT_IDU: begin
//             if (idu_ready_in) begin
//                 next_state = `IFU_S_IDLE;
//                 inst_sram_valid_out = 1'b0;
//                 idu_valid_out = 1'b0;
//             end
//         end
//         default: begin
//             next_state = `IFU_S_IDLE;
//         end
//     endcase
// end

// assign inst_sram_valid_out = inst_sram_valid_r;
// assign idu_valid_out = idu_valid_r;
// assign ifu_req_addr_out = req_addr_r;
// assign ifu_inst_out = req_inst_r;

// always @(posedge clk) begin
//     if (rst) begin
//         inst_sram_valid_r <= 1'b0;
//         idu_valid_r <= 1'b0;
//         req_addr_r <= 32'b0;
//         req_inst_r <= 32'b0;
//     end else begin
//         case (state)
//             `IFU_S_IDLE: begin
//                 inst_sram_valid_r <= 1'b0;
//                 idu_valid_r <= 1'b0;
//                 // if (pc_cnt_ready_in) begin
//                     req_addr_r <= ifu_current_pc_in;
//                 // end
//             end
//             `IFU_S_WAIT_SRAM: begin
//                 inst_sram_valid_r <= 1'b1;
//                 idu_valid_r <= 1'b0;
//                 if (inst_sram_ready_in) begin
//                     req_inst_r <= ifu_req_inst_in;
//                 end
//             end
//             `IFU_S_WAIT_IDU: begin
//                 inst_sram_valid_r <= 1'b0;
//                 idu_valid_r <= 1'b1;
//             end
//             default: begin
//                 inst_sram_valid_r <= 1'b0;
//                 idu_valid_r <= 1'b0;
//             end
//         endcase
//     end
// end

endmodule
