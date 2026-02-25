module ID_EX(
    input           clk,
                    rst,

    input  [31:0]   pc_i,
    input  [ 5:0]   fun_i,
    input  [ 3:0]   src_sel_i,
    input  [63:0]   rdata_i,
    input  [ 8:0]   lsu_data_i,
    input  [ 9:0]   wbu_data_i,
    input  [31:0]   wbu_csr_rdata_i,
    input  [ 2:0]   wbu_csr_func3_i,
    input  [11:0]   wbu_csr_waddr_i,
    input           wbu_csr_we_i,
    input  [ 3:0]   pc_src_sel_i,
    input  [31:0]   imm_res_i,
    output [31:0]   pc_o,
    output [ 5:0]   fun_o,
    output [ 3:0]   src_sel_o,
    output [63:0]   rdata_o,
    output [ 8:0]   lsu_data_o,
    output [ 9:0]   wbu_data_o,
    output [31:0]   wbu_csr_rdata_o,
    output [ 2:0]   wbu_csr_func3_o,
    output [11:0]   wbu_csr_waddr_o,
    output          wbu_csr_we_o,
    output [ 3:0]   pc_src_sel_o,
    output [31:0]   imm_res_o,

    input           id_idex_valid_i,
    output          id_idex_ready_o,
    output          idex_ex_valid_o,
    input           idex_ex_ready_i
);

assign id_idex_ready_o = id_idex_valid_i & state == S_IDLE;
assign idex_ex_valid_o = state == S_BUSY;

reg [31:0] pc_r;
reg [ 5:0] fun_r;
reg [ 3:0] src_sel_r;
reg [63:0] rdata_r;
reg [ 8:0] lsu_data_r;
reg [ 9:0] wbu_data_r;
reg [31:0] wbu_csr_rdata_r;
reg [ 2:0] wbu_csr_func3_r;
reg [11:0] wbu_csr_waddr_r;
reg        wbu_csr_we_r;
reg [ 3:0] pc_src_sel_r;
reg [31:0] imm_res_r;

assign pc_o = pc_r;
assign fun_o = fun_r;
assign src_sel_o = src_sel_r;
assign rdata_o = rdata_r;
assign lsu_data_o = lsu_data_r;
assign wbu_data_o = wbu_data_r;
assign wbu_csr_rdata_o = wbu_csr_rdata_r;
assign wbu_csr_func3_o = wbu_csr_func3_r;
assign wbu_csr_waddr_o = wbu_csr_waddr_r;
assign wbu_csr_we_o = wbu_csr_we_r;
assign pc_src_sel_o = pc_src_sel_r;
assign imm_res_o = imm_res_r;

always @(posedge clk) begin
    if (rst) begin
        pc_r <= 'b0;
        fun_r <= 'b0;
        src_sel_r <= 'b0;
        rdata_r <= 'b0;
        lsu_data_r <= 'b0;
        wbu_data_r <= 'b0;
        wbu_csr_rdata_r <= 'b0;
        wbu_csr_func3_r <= 'b0;
        wbu_csr_waddr_r <= 'b0;
        wbu_csr_we_r <= 'b0;
        pc_src_sel_r <= 'b0;
        imm_res_r <= 'b0;
    end else begin
        pc_r <= pc_i;
        fun_r <= fun_i;
        src_sel_r <= src_sel_i;
        rdata_r <= rdata_i;
        lsu_data_r <= lsu_data_i;
        wbu_data_r <= wbu_data_i;
        wbu_csr_rdata_r <= wbu_csr_rdata_i;
        wbu_csr_func3_r <= wbu_csr_func3_i;
        wbu_csr_waddr_r <= wbu_csr_waddr_i;
        wbu_csr_we_r <= wbu_csr_we_i;
        pc_src_sel_r <= pc_src_sel_i;
        imm_res_r <= imm_res_i;
    end
end

localparam S_W    = 2;
localparam S_IDLE = 2'd0;
localparam S_BUSY = 2'd1;

reg [S_W-1:0] state;

always @(posedge clk) begin
    if (rst) begin
        state <= S_IDLE;
    end else begin
        case (state)
            S_IDLE: begin
                if (id_idex_valid_i & id_idex_ready_o) state <= S_BUSY;
            end
            S_BUSY: begin
                if (idex_ex_valid_o & idex_ex_ready_i) state <= S_IDLE;
            end
            default: begin
                state <= S_IDLE;
            end
        endcase
    end
end

endmodule
