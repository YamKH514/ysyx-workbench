module CSR(
    input           clk,
    input           CSRWriteEn,
    input   [31:0]  CSRWriteAddr,
    input   [31:0]  CSRWriteData,
    input   [31:0]  CSRReadAddr,
    output  [31:0]  CSRReadData
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

always @(posedge clk) begin
    if(mepcWriteEn) begin
        mepc <= CSRWriteData;
    end
end

always @(posedge clk) begin
    if(mcauseWriteEn) begin
        mcause <= CSRWriteData;
    end
end

always @(posedge clk) begin
    if(mtvecWriteEn) begin
        mtvec <= CSRWriteData;
    end
end

always @(posedge clk) begin
    if(mstatusWriteEn) begin
        mstatus <= CSRWriteData;
    end
end

endmodule
