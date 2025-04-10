module adder1(
        input Cin, a, b,
        output Cout, sum
    );

    assign sum = a + b + Cin;
    assign Cout = (a & b) | (a & Cin) | (b & Cin);

endmodule
