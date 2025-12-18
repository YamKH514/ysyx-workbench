module TestSRAM(
    /* verilator lint_off UNUSEDSIGNAL */
    input               clk,
    input               rstn,

    // AR
    input       [31:0]  araddr_in,
    input               arvalid_in,
    output  reg         arready_out,

    // R
    output  reg [31:0]  rdata_out,
    output  reg [1:0]   rresp_out,
    output  reg         rvalid_out,
    input               rready_in,

    // AW
    input       [31:0]  awaddr_in,
    input               awvalid_in,
    output  reg         awready_out,

    // W
    input       [31:0]  wdata_in,
    input       [3:0]   wstrb_in,
    input               wvalid_in,
    output  reg         wready_out,

    // B
    output  reg [1:0]   bresp_out,
    output  reg         bvalid_out,
    input               bready_in
);

reg [7:0] ReadAddr1;
reg [31:0] ReadData1;
reg [7:0] WriteAddr;
reg [31:0] WriteData;
reg [3:0] WriteMask;
reg RegWrite;

parameter S_IDLE   = 3'd0;
parameter S_GET_AR = 3'd1;
parameter S_SEND_R = 3'd2;
parameter S_GET_WR = 3'd3;
parameter S_GET_WD = 3'd4;
parameter S_SEND_B = 3'd5;

reg [2:0]   r_state, r_next_state;
reg [2:0]   w_state, w_next_state;

always @(posedge clk) begin
    if (!rstn) begin
        r_state <= S_IDLE;
        w_state <= S_IDLE;
    end else begin
        r_state <= r_next_state;
        w_state <= w_next_state;
    end

    // READ
    if (!rstn) begin
        arready_out <= 1'b1;
        rvalid_out  <= 1'b0;
        rresp_out   <= 2'b00;
    end else begin
        case (r_state)
            S_IDLE: begin
                if (arvalid_in & arready_out) begin
                    ReadAddr1 <= araddr_in[7:0];
                    arready_out <= 1'b0;
                end
            end
            S_GET_AR: begin
                rdata_out <= ReadData1;
                rvalid_out <= 1'b1;
                rresp_out  <= 2'b00;
            end
            S_SEND_R: begin
                if (rvalid_out & rready_in) begin
                    arready_out <= 1'b1;
                    rvalid_out  <= 1'b0;
                end
            end
            default: begin
                arready_out <= 1'b1;
                rvalid_out  <= 1'b0;
            end
        endcase
    end

    // WRITE
    if (!rstn) begin
        awready_out <= 1'b1;
        wready_out  <= 1'b1;
        bresp_out   <= 2'b00;
        bvalid_out  <= 1'b0;
    end else begin
        case (w_state)
            S_IDLE: begin
                if (awvalid_in & awready_out) begin
                    WriteAddr   <= awaddr_in[7:0];
                    awready_out <= 1'b0;
                end
            end
            S_GET_WR: begin
                if (wvalid_in & wready_out) begin
                    WriteData  <= wdata_in;
                    WriteMask  <= wstrb_in;
                    RegWrite   <= 1'b1;
                    wready_out <= 1'b0;
                end
            end
            S_GET_WD: begin
                RegWrite   <= 1'b0;
                bresp_out  <= 2'b00;
                bvalid_out <= 1'b1;
            end
            S_SEND_B: begin
                if (bvalid_out & bready_in) begin
                    awready_out <= 1'b1;
                    wready_out  <=1'b1;
                    bvalid_out  <= 1'b0;
                end
            end
            default: begin
                awready_out <= 1'b1;
                wready_out  <= 1'b1;
                bvalid_out  <= 1'b0;
            end
        endcase
    end
end

always @(*) begin
    r_next_state = r_state;
    w_next_state = w_state;

    // READ
    case (r_state)
        S_IDLE: begin
            if (arvalid_in & arready_out) begin
                r_next_state = S_GET_AR;
            end
        end
        S_GET_AR: begin
            r_next_state = S_SEND_R;
        end
        S_SEND_R: begin
            if (rvalid_out & rready_in) begin
                r_next_state = S_IDLE;
            end
        end
        default: begin
            r_next_state = S_IDLE;
        end
    endcase

    // WRITE
    case (w_state)
        S_IDLE: begin
            if (awvalid_in & awready_out) begin
                w_next_state = S_GET_WR;
            end
        end
        S_GET_WR: begin
            if (wvalid_in & wready_out) begin
                w_next_state = S_GET_WD;
            end
        end
        S_GET_WD: begin
            w_next_state = S_SEND_B;
        end
        S_SEND_B: begin
            if (bvalid_out & bready_in) begin
                w_next_state = S_IDLE;
            end
        end
        default: begin
            w_next_state = S_IDLE;
        end
    endcase
end

wire [31:0] ReadData2, ReadData_a5;

RegisterFile #(8, 32) u_RegisterFile(
    .clk         	(clk          ),
    .ReadAddr1   	(ReadAddr1    ),
    .ReadAddr2   	(8'b0         ),
    .WriteAddr   	(WriteAddr    ),
    .WriteData   	(WriteData    ),
    .RegWrite    	(RegWrite     ),
    .ReadData1   	(ReadData1    ),
    .ReadData2   	(ReadData2    ),
    .ReadData_a5 	(ReadData_a5  )
);


endmodule
