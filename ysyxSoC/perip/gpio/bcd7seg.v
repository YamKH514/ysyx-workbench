module bcd7seg(
        input [3:0] b,
        input en,
        output reg [7:0] h
    );

    always @(*) begin
        if(en) begin
            case (b)
                0:  h = 8'b1100000_0;
                1:  h = 8'b1001111_1;
                2:  h = 8'b1010010_0;
                3:  h = 8'b1011000_0;
                4:  h = 8'b1001100_1;
                5:  h = 8'b1001001_0;
                6:  h = 8'b1000001_0;
                7:  h = 8'b1111100_0;
                8:  h = 8'b1000000_0;
                9:  h = 8'b1001000_0;
                10: h = 8'b1000100_0;
                11: h = 8'b1000001_1;
                12: h = 8'b1100011_0;
                13: h = 8'b1010000_1;
                14: h = 8'b1000011_0;
                15: h = 8'b1000111_0;
                default: h = 8'b1_1111111;
            endcase
        end
        else begin
            h = 8'b1_1111111;
        end
    end

endmodule
