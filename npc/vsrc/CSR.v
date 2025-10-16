module CSR(
    input           clk,
    input           rst,
    input           is_ecall,
    input           CSRWriteEn,
    input   [31:0]  CSRWriteAddr,
    input   [31:0]  CSRWriteData,
    input   [31:0]  CSRWriteData_mcause,
    input   [31:0]  CSRWriteData_mepc,
    input   [31:0]  CSRReadAddr,
    output  [31:0]  CSRReadData,
    output  [31:0]  CSRReadData_mtvec
);

reg [31:0]  mepc;
reg [31:0]  mcause;
reg [31:0]  mtvec;
reg [31:0]  mstatus;

wire mepcWriteEn    = CSRWriteEn & (CSRWriteAddr == 32'h341);
wire mcauseWriteEn  = CSRWriteEn & (CSRWriteAddr == 32'h342);
wire mtvecWriteEn   = CSRWriteEn & (CSRWriteAddr == 32'h305);
wire mstatusWriteEn = CSRWriteEn & (CSRWriteAddr == 32'h300);

assign CSRReadData =    {32{CSRReadAddr == 32'h341}} & mepc |
                        {32{CSRReadAddr == 32'h342}} & mcause |
                        {32{CSRReadAddr == 32'h305}} & mtvec |
                        {32{CSRReadAddr == 32'h300}} & mstatus;

assign CSRReadData_mtvec = mtvec;

always @(posedge clk) begin
    if(rst) begin
        mepc    <= 32'b0;
        mcause  <= 32'b0;
        mtvec   <= 32'b0;
        mstatus <= 32'b0;
    end
    else if(is_ecall) begin
        mstatus[12:11]  <= 2'b11;
        mstatus[7]      <= mstatus[3];
        mstatus[3]      <= 1'b0;
        mcause          <= CSRWriteData_mcause;
        mepc            <= CSRWriteData_mepc;
    end
    else begin
        if(mepcWriteEn) begin
            mepc <= CSRWriteData;
        end
        if(mcauseWriteEn) begin
            mcause <= CSRWriteData;
        end
        if(mtvecWriteEn) begin
            mtvec <= CSRWriteData;
        end
        if(mstatusWriteEn) begin
            mstatus <= CSRWriteData;
        end
    end
end

endmodule
