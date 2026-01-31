module bcd7seg(
        input [3:0] b,
        input en,
        output reg [7:0] h
    );

    always @(*) begin
        if(en) begin
            case (b)
                0:  h = 8'b0_1000000;
                1:  h = 8'b0_1111001;
                2:  h = 8'b0_0100100;
                3:  h = 8'b0_0110000;
                4:  h = 8'b0_0011001;
                5:  h = 8'b0_0010010;
                6:  h = 8'b0_0000010;
                7:  h = 8'b0_1111000;
                8:  h = 8'b0_0000000;
                9:  h = 8'b0_0010000;
                10: h = 8'b0_0001000;
                11: h = 8'b0_0000011;
                12: h = 8'b0_1000110;
                13: h = 8'b0_0100001;
                14: h = 8'b0_0000110;
                15: h = 8'b0_0001110;
                default: h = 8'b1_1111111;
            endcase
        end
        else begin
            h = 8'b1_1111111;
        end
    end

endmodule
