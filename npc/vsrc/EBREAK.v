module EBREAK(
    input ebreak_en,
    input clk
);

    import "DPI-C" function void ebreak_trigger();

    always @(posedge clk) begin
        if(ebreak_en) begin
            ebreak_trigger();
        end
    end

endmodule
