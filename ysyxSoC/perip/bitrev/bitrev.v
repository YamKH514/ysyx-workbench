module bitrev (
  input  sck,
  input  ss,
  input  mosi,
  output miso
);

reg [7:0] data_r;
reg [2:0] bit_cnt;
reg       miso_r;
reg       mode; // RX = 0, TX = 1

assign miso = !ss ? miso_r : 1'b1;

always @(posedge sck or posedge ss) begin
  if (ss) begin
    data_r <= 8'b0;
    bit_cnt <= 3'b0;
    mode <= 1'b0;
  end else begin
    if (!mode) begin // RX
      data_r <= {data_r[6:0], mosi};
      bit_cnt <= bit_cnt + 1;
      if (bit_cnt == 3'd7) begin
        bit_cnt <= 3'b0;
        mode <= 1'b1;
      end
    end else begin // TX
      miso_r <= data_r[bit_cnt];
      bit_cnt <= bit_cnt + 1;
      if (bit_cnt == 3'd7) begin
        bit_cnt <= 3'b0;
        mode <= 1'b0;
      end
    end
  end
end

endmodule
