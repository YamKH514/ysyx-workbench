module sdram32Mx16 (
    input        clk,
    input        cke,
    input        cs,
    input        ras,
    input        cas,
    input        we,
    input [12:0] a,
    input [ 1:0] ba,
    input [ 1:0] dqm,
    inout [15:0] dq
);

    wire    [15:0]      din;
    reg     [15:0]      dout;
    wire    [15:0]      douten;

    assign  din[15:0] = dq;
    genvar  i;
    generate
        for (i = 0; i < 16; i = i + 1) begin
            assign dq[i] = douten[i] ? dout[i] : 1'bz;
        end
    endgenerate

    localparam BANK_SIZE   = 4;
    localparam MEMORY_SIZE = 8192*512;

    localparam CMD_W             = 4;
    localparam CMD_NOP           = 4'b0111;
    localparam CMD_ACTIVE        = 4'b0011;
    localparam CMD_READ          = 4'b0101;
    localparam CMD_WRITE         = 4'b0100;
    localparam CMD_TERMINATE     = 4'b0110;
    localparam CMD_PRECHARGE     = 4'b0010;
    localparam CMD_REFRESH       = 4'b0001;
    localparam CMD_LOAD_MODE     = 4'b0000;

    reg     [15:0]      mem_bank[0:BANK_SIZE-1][0:MEMORY_SIZE-1];
    reg     [12:0]      row_addr[0:BANK_SIZE-1];
    reg     [ 1:0]      dqm_r;
    reg     [ 1:0]      ba_r;
    reg     [ 2:0]      CAS_Latency;
    reg     [ 2:0]      Burst_Length;
    wire    [CMD_W-1:0] cmd;

    reg     [ 3:0]      cnt_read;
    reg     [ 3:0]      cnt_write;
    reg     [ 3:0]      data_len;
    reg                 is_read;
    reg     [ 8:0]      raddr_r;
    reg     [ 8:0]      waddr_r;
    reg     [15:0]      wdata_r;
    wire    [21:0]      sdram_raddr = {row_addr[ba_r], raddr_r};
    wire    [21:0]      sdram_waddr = {row_addr[ba_r], waddr_r};

    assign  cmd = {cs, ras, cas, we};
    assign  douten = is_read ? 'hFFFF : 'd0;
    assign  data_len =  (Burst_Length == 'b000) ? 1:
                        (Burst_Length == 'b001) ? 2:
                        (Burst_Length == 'b010) ? 4:
                        8;

    // BA Set
    always @(posedge clk) begin
        if (!cke) begin
            ba_r <= 0;
        end else if (cmd == CMD_ACTIVE | cmd == CMD_READ | cmd == CMD_WRITE) begin
            ba_r <= ba;
        end
    end

    // DQM Set
    always @(posedge clk) begin
        if (!cke) begin
            dqm_r <= 0;
        end else if (!cs) begin
            dqm_r <= dqm;
        end
    end

    // ACTIVE
    always @(posedge clk) begin
        if (cmd == CMD_ACTIVE) begin
            row_addr[ba] <= a;
        end
    end

    // READ
    always @(posedge clk) begin
        if (!cke) begin
            cnt_read <= 'd0;
            is_read <= 'd0;
            raddr_r <= 'd0;
        end else if (cmd == CMD_READ) begin
            cnt_read <= cnt_read + 1;
            is_read <= 1;
            raddr_r <= a[8:0];
        end else if ((0 < cnt_read) && (cnt_read < {1'b0, CAS_Latency} - 1)) begin
            // delay
            cnt_read <= cnt_read + 1;
            is_read <= 1;
        end else if (cnt_read >= {1'b0, CAS_Latency} - 1) begin
            cnt_read <= (cnt_read < data_len + {1'b0, CAS_Latency} - 1) ? cnt_read + 1 : 'd0;
            is_read <= 1;
            raddr_r <= raddr_r + 1;
        end else begin
            cnt_read <= 'd0;
            is_read <= 'd0;
            raddr_r <= 'd0;
        end
    end

    always @(posedge clk) begin
        if (!cke) begin
            dout <= 'd0;
        end else begin
            if (cnt_read >= {1'b0, CAS_Latency} - 1) begin
                dout <= mem_bank[ba_r][sdram_raddr];
            end else begin
                dout <= 0;
            end
        end
    end

    // WRITE
    always @(posedge clk) begin
        if (!cke) begin
            cnt_write <= 'd0;
            waddr_r <= 'd0;
        end else if (cmd == CMD_WRITE) begin
            cnt_write <= cnt_write + 1;
            waddr_r <= a[8:0];
            wdata_r <= din;
        end else if (0 < cnt_write) begin
            cnt_write <= (cnt_write < data_len) ? cnt_write + 1 : 'd0;
            waddr_r <= waddr_r + 1;
            wdata_r <= din;
        end else begin
            cnt_write <= 'd0;
            waddr_r <= 'd0;
            wdata_r <= 'd0;
        end
    end

    always @(posedge clk) begin
        if (0 < cnt_write) begin
            mem_bank[ba_r][sdram_waddr][15:8] <= (!dqm_r[1]) ? wdata_r[15:8] : mem_bank[ba_r][sdram_waddr][15:8];
            mem_bank[ba_r][sdram_waddr][ 7:0] <= (!dqm_r[0]) ? wdata_r[ 7:0] : mem_bank[ba_r][sdram_waddr][ 7:0];
        end
    end

    // LOAD MODE REG
    always @(posedge clk) begin
        if (!cke) begin
            CAS_Latency  <= 'd0;
            Burst_Length <= 'd0;
        end else if (cmd == CMD_LOAD_MODE) begin
            CAS_Latency  <= a[6:4];
            Burst_Length <= a[2:0];
        end
    end

endmodule
