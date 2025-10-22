module Memory(
    input              clk,
    input       [31:0] pc,
    input       [31:0] raddr,
    input       [31:0] waddr,
    input       [31:0] wdata,
    input       [7:0]  wmask,
    input              MemValid,
    input              MemWrite,
    input       [2:0]  MemReadFunc, // unsigned(0--) signed(1--) lb(-01) lh(-10) lw(011)
    output      [31:0] rdata
);

reg     [31:0]  Data;
wire    [1:0]   ByteOff;
wire    [7:0]   DataB;
wire    [15:0]  DataH;

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);
`ifdef CONFIG_DIFFTEST
import "DPI-C" function void difftest_skip_ref(int pc);
`endif
always @(*) begin
    Data = 0;
    if (MemValid) begin // 有读写请求时
        Data = paddr_read(raddr);
    end
end
always @(posedge clk) begin
    if (MemValid && MemWrite) begin // 有读写请求时
        paddr_write(waddr, wdata, wmask);
    end
`ifdef CONFIG_DIFFTEST
    if ((raddr == 32'ha0000048) | (raddr == 32'ha0000048 + 32'h4) | (waddr == 32'ha00003f8)) begin
        difftest_skip_ref(pc); // Difftest跳过读写设备
    end
`endif
end

assign ByteOff = raddr[1:0];

assign DataB =  {8{ByteOff == 2'b00}} & Data[7:0] |
                {8{ByteOff == 2'b01}} & Data[15:8] |
                {8{ByteOff == 2'b10}} & Data[23:16] |
                {8{ByteOff == 2'b11}} & Data[31:24];

assign DataH = ByteOff[1] == 1'b0 ? Data[15:0] : Data[31:16];

assign rdata =  {32{MemReadFunc == 3'b001}} & {24'b0, DataB[7:0]} | // lbu
                {32{MemReadFunc == 3'b101}} & {{24{DataB[7]}}, DataB[7:0]} | // lb
                {32{MemReadFunc == 3'b010}} & {16'b0, DataH[15:0]} | // lhu
                {32{MemReadFunc == 3'b110}} & {{16{DataH[15]}}, DataH[15:0]} | // lh
                {32{MemReadFunc == 3'b011}} & Data ; // lw

endmodule
