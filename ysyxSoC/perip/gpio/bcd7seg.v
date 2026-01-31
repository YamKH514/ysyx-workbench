module bcd7seg(
        input [3:0] b,
        input en,
        output reg [7:0] h
    );

    always @(*) begin
        if(en) begin
            case (b)
                //         ABCDEFG_DP
                0:  h = 8'b0000001_1;
                1:  h = 8'b1001111_1;
                2:  h = 8'b0010010_1;
                3:  h = 8'b0000110_1;
                4:  h = 8'b1001100_1;
                5:  h = 8'b0100100_1;
                6:  h = 8'b0100000_1;
                7:  h = 8'b0001111_1;
                8:  h = 8'b0000000_1;
                9:  h = 8'b0000100_1;
                10: h = 8'b0001000_1;
                11: h = 8'b1100000_1;
                12: h = 8'b0110001_1;
                13: h = 8'b1000010_1;
                14: h = 8'b0110000_1;
                15: h = 8'b0111000_1;
                default: h = 8'b1111111_1;
            endcase
        end
        else begin
            h = 8'b1111111_1;
        end
    end

endmodule
