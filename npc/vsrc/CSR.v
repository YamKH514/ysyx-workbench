module CSR(
    input           clk,
    input           rst,
    input           is_ecall,
    input           is_mret,
    input   [2:0]   CSRFunc3,
    input           CSRWriteEn,
    input   [11:0]  CSRRWAddr,
    input   [31:0]  CSRWriteData,
    input   [31:0]  CSRWriteData_mcause,
    input   [31:0]  CSRWriteData_mepc,
    output  [31:0]  CSRReadData,
    output  [31:0]  CSRReadData_mtvec,
    output  [31:0]  CSRReadData_mepc
);

reg [31:0]  mepc;
reg [31:0]  mcause;
reg [31:0]  mtvec;
reg [31:0]  mstatus;
reg [31:0] next_mstatus;

wire        mepcWriteEn    = CSRWriteEn & (CSRRWAddr == 12'h341);
wire        mcauseWriteEn  = CSRWriteEn & (CSRRWAddr == 12'h342);
wire        mtvecWriteEn   = CSRWriteEn & (CSRRWAddr == 12'h305);
wire        mstatusWriteEn = CSRWriteEn & (CSRRWAddr == 12'h300);
wire [31:0] CSROldData     = CSRReadData;
wire [31:0] WriteData      =    {32{CSRFunc3 == 3'b001}} & CSRWriteData |
                                {32{CSRFunc3 == 3'b010}} & (CSROldData | CSRWriteData);

assign CSRReadData =    {32{CSRRWAddr == 12'h341}} & mepc |
                        {32{CSRRWAddr == 12'h342}} & mcause |
                        {32{CSRRWAddr == 12'h305}} & mtvec |
                        {32{CSRRWAddr == 12'h300}} & mstatus;

assign CSRReadData_mtvec = mtvec;
assign CSRReadData_mepc  = mepc;

always @(posedge clk) begin
    if(rst) begin
        mepc    <= 32'b0;
        mcause  <= 32'b0;
        mtvec   <= 32'b0;
        mstatus <= 32'h00001800;
    end
    else begin
        next_mstatus <= mstatus;
        if(is_ecall) begin
            next_mstatus[12:11]  <= 2'b11;
            next_mstatus[7]      <= mstatus[3];
            next_mstatus[3]      <= 1'b0;
            mcause          <= CSRWriteData_mcause;
            mepc            <= CSRWriteData_mepc;
        end
        else if(is_mret) begin
            next_mstatus[12:11]  <= 2'b0;
            next_mstatus[3]      <= mstatus[7];
            next_mstatus[7]      <= 1'b1;
        end
        else begin
            if(mepcWriteEn) begin
                mepc <= WriteData;
            end
            if(mcauseWriteEn) begin
                mcause <= WriteData;
            end
            if(mtvecWriteEn) begin
                mtvec <= WriteData;
            end
            if(mstatusWriteEn) begin
                next_mstatus <= WriteData;
            end
        end
        mstatus <= next_mstatus;
    end
end

export "DPI-C" function get_csr;
function void get_csr(output int csr[4]);
    csr[0] = mepc;
    csr[1] = mcause;
    csr[2] = mtvec;
    csr[3] = mstatus;
endfunction

endmodule
