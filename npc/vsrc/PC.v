module PC(
    input clk,
    input rst,
    input next,
    output [31:0] pc_out
);
    reg [31:0] pc;
    always @(posedge clk) begin
        if(rst) pc <= 32'h80000000;
        else if(next) pc <= pc + 4;
    end

    assign pc_out = pc;

endmodule
