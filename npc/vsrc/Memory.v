module Memory(
    input       [31:0] raddr,
    input       [31:0] waddr,
    input       [31:0] wdata,
    input       [7:0]  wmask,
    input              MemValid,
    input              MemWrite,
    input       [2:0]  MemReadFunc, // unsigned(0--) signed(1--) lb(-01) lh(-10) lw(-11)
    output      [31:0] rdata
);

reg [31:0] data;

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);
always @(*) begin
    data = 0;
    if (MemValid) begin // 有读写请求时
        if (MemWrite) begin // 有写请求时
            paddr_write(waddr, wdata, wmask);
        end
        else begin
            data = paddr_read(raddr);
        end
    end
end

assign rdata =  {32{MemReadFunc == 3'b001}} & {24'b0, data[7:0]} | // lbu
                {32{MemReadFunc == 3'b101}} & {{24{data[7]}}, data[7:0]} | // lbu
                {32{MemReadFunc == 3'b010}} & {16'b0, data[15:0]} | // lhu
                {32{MemReadFunc == 3'b110}} & {{16{data[15]}}, data[15:0]} | // lhu
                {32{MemReadFunc[1:0] == 2'b11}} & data ; // lw

endmodule
