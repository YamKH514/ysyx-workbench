module psram(
  input sck,
  input ce_n,
  inout [3:0] dio
);

import "DPI-C" function void psram_read(input int addr, output int data);
import "DPI-C" function void psram_write(input int addr, input int data,input int mask);

`define INST_READ 8'hEB
`define INST_WRITE 8'h38
`define INST_QPI 8'h35

localparam S_INST = 3'd1;
localparam S_ADDR = 3'd2;
localparam S_DATA = 3'd3;
localparam S_WAIT = 3'd4;
reg [2:0]   state;

reg         qpi_mode = 0;
reg [7:0]   inst;
reg [23:0]  addr;
reg [31:0]  r_data;
reg [31:0]  data;
reg [7:0]   counter;

wire [3:0] din, dout, douten;
assign dio[0] = douten[0] ? dout[0] : 1'bz;
assign dio[1] = douten[1] ? dout[1] : 1'bz;
assign dio[2] = douten[2] ? dout[2] : 1'bz;
assign dio[3] = douten[3] ? dout[3] : 1'bz;
assign din = (douten == 'b0) ? dio : 4'b0;

assign douten = (state == S_DATA | state == S_WAIT) && inst == `INST_READ ? 4'b1111 : 4'd0;
assign dout = {(state == S_DATA && counter == 'd0) ? data_swap : data}[31:28];

// inst
always@(posedge sck or posedge ce_n) begin
  if (ce_n) begin
    inst <= 8'd0;
  end else if (state == S_INST)begin
    inst <= (qpi_mode) ? {inst[3:0], din} : {inst[6:0], din[0]};
  end 
end

// addr
always@(posedge sck or posedge ce_n) begin
  if (ce_n) begin
    addr <= 24'd0;
  end else if (state == S_ADDR && counter < 'd6) begin
    addr <= {addr[19:0], din[3:0]};
  end
end

// data
wire [31:0] data_swap = {r_data[7:0], r_data[15:8], r_data[23:16], r_data[31:24]};
always@(posedge sck or posedge ce_n) begin
  if (ce_n) begin
    data <= 32'd0;
  end else if (state == S_DATA && inst == `INST_READ) begin
    data <= { {counter == 'd0 ? data_swap : data}[27:0], 4'b0000 };
  end else if (state == S_DATA && inst == `INST_WRITE) begin
    data <= {data[27:0], din[3:0]};
  end
end

always @(posedge sck)begin
  if((state == S_WAIT) && (counter == 'd0) && (inst == `INST_READ))begin
    psram_read({8'd0, addr}, r_data);
  end
end

wire [31:0] w_data = {data[7:0], data[15:8], data[23:16], data[31:24]};
always@(posedge ce_n) begin
  if(inst == `INST_WRITE)begin
    psram_write({8'd0, addr}, w_data, {24'd0, counter});
  end
end

// qpi mode set
always @(posedge ce_n) begin
  if (inst == `INST_QPI) qpi_mode <= 1'b1;
end

always @(posedge sck or posedge ce_n) begin
  if(ce_n)begin
    counter <= 0;
    state   <= S_INST;
  end
  else begin
    case(state)
      S_INST:begin
        if (qpi_mode) begin
          counter <= (counter < 'd1 ) ? counter + 8'd1 : 8'd0;
          state <= (counter == 'd1 ) ? S_ADDR : state;
        end else begin
          counter <= (counter < 'd7 ) ? counter + 8'd1 : 8'd0;
          state <= (counter == 'd7 ) ? S_ADDR : state;
        end
      end
      S_ADDR:begin
        counter <= (counter < 'd5) ? counter + 8'd1 : 8'd0;
        state  <= (counter == 'd5) ? (inst == `INST_READ ? S_WAIT : (inst == `INST_WRITE ? S_DATA : 3'd7)) : state;
      end
      S_DATA:begin
        counter <= counter + 8'd1;
        state <= state;
      end
      S_WAIT:begin
        counter <= (counter < 'd6) ? counter + 8'd1 : 8'd0;
        state  <= (counter == 'd6) ? S_DATA  : state;
      end
      default: begin
        $display("Assertion failed: Unsupported command `%xh`, only support `EBh,38H` read command\n", inst);
        $fatal;
      end
    endcase
  end
end

endmodule
