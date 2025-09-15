module Memory(
    input       [31:0] raddr,
    input       [31:0] waddr,
    input       [31:0] wdata,
    input       [7:0]  wmask,
    input              MemValid,
    input              MemWrite,
    output  reg [31:0] rdata
);

import "DPI-C" function int paddr_read(input int raddr);
import "DPI-C" function void paddr_write(
    input int waddr, input int wdata, input byte wmask);
always @(*) begin
    rdata = 0;
    if (MemValid) begin // 有读写请求时
        if (MemWrite) begin // 有写请求时
            paddr_write(waddr, wdata, wmask);
        end
        else begin
            rdata = paddr_read(raddr);
        end
    end
end

endmodule
