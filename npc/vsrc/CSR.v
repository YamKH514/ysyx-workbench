module CSR(
    input           clk,
    input           rst,
    input           is_ecall,
    input           is_mret,
    input   [2:0]   csr_func3_i,
    input           csr_we_i,
    input   [11:0]  csr_raddr_i,
    output  [31:0]  csr_rdata_o,
    input   [11:0]  csr_waddr_i,
    input   [31:0]  csr_wdata_i,
    input   [31:0]  csr_w_mepc_i,
    output  [31:0]  csr_r_mtvec_o,
    output  [31:0]  csr_r_mepc_o
);

reg [31:0]  mepc_r;
reg [31:0]  mcause_r;
reg [31:0]  mtvec_r;
reg [31:0]  mstatus_r;
reg [31:0]  mvendorid_r = 32'h79737978;
reg [31:0]  marchid_r = 32'h17F4E28;

wire        mepc_we      = csr_we_i & (csr_waddr_i == 12'h341);
wire        mcause_we    = csr_we_i & (csr_waddr_i == 12'h342);
wire        mtvec_we     = csr_we_i & (csr_waddr_i == 12'h305);
wire        mstatus_we   = csr_we_i & (csr_waddr_i == 12'h300);
wire [31:0] csr_old_data = csr_rdata_o;
wire [31:0] csr_r_data   =  {32{csr_func3_i == 3'b001}} & csr_wdata_i |
                            {32{csr_func3_i == 3'b010}} & (csr_old_data | csr_wdata_i);

assign csr_rdata_o =    {32{csr_raddr_i == 12'h341}} & mepc_r |
                        {32{csr_raddr_i == 12'h342}} & mcause_r |
                        {32{csr_raddr_i == 12'h305}} & mtvec_r |
                        {32{csr_raddr_i == 12'h300}} & mstatus_r |
                        {32{csr_raddr_i == 12'hF11}} & mvendorid_r |
                        {32{csr_raddr_i == 12'hF12}} & marchid_r;

assign csr_r_mtvec_o = mtvec_r;
assign csr_r_mepc_o  = mepc_r;

always @(posedge clk) begin
    if(rst) begin
        mepc_r    <= 32'b0;
        mcause_r  <= 32'b0;
        mtvec_r   <= 32'b0;
        mstatus_r <= 32'h00001800;
    end
    else begin
        if(is_ecall) begin
            mstatus_r[12:11]  <= 2'b11;
            mstatus_r[7]      <= mstatus_r[3];
            mstatus_r[3]      <= 1'b0;
            mcause_r          <= 32'd11;
            mepc_r            <= csr_w_mepc_i;
        end
        else if(is_mret) begin
            mstatus_r[12:11]  <= 2'b0;
            mstatus_r[3]      <= mstatus_r[7];
            mstatus_r[7]      <= 1'b1;
        end
        else begin
            if(mepc_we) begin
                mepc_r <= csr_r_data;
            end
            if(mcause_we) begin
                mcause_r <= csr_r_data;
            end
            if(mtvec_we) begin
                mtvec_r <= csr_r_data;
            end
            if(mstatus_we) begin
                mstatus_r <= csr_r_data;
            end
        end
    end
end

export "DPI-C" function get_csr;
function void get_csr(output int csr[6]);
    csr[0] = mepc_r;
    csr[1] = mcause_r;
    csr[2] = mtvec_r;
    csr[3] = mstatus_r;
    csr[4] = mvendorid_r;
    csr[5] = marchid_r;
endfunction

endmodule
