module vga_ctrl(
    input           pclk,
    input           reset,
    input   [23:0]  vga_data,
    output  [19:0]  vga_addr,
    output          hsync,
    output          vsync,
    output          valid,
    output  [ 7:0]  vga_r,
    output  [ 7:0]  vga_g,
    output  [ 7:0]  vga_b
);

    parameter h_frontporch = 96;
    parameter h_active = 144;
    parameter h_backporch = 784;
    parameter h_total = 800;

    parameter v_frontporch = 2;
    parameter v_active = 35;
    parameter v_backporch = 515;
    parameter v_total = 525;

    reg [9:0] x_cnt;
    reg [9:0] y_cnt;
    wire h_valid;
    wire v_valid;

    always @(posedge pclk) begin
        if (reset) begin
            x_cnt <= 0;
            y_cnt <= 0;
        end else begin
            if (x_cnt == h_total) begin
                // 当前行扫描完毕
                x_cnt <= 1;
                if (y_cnt == v_total) y_cnt <= 1;
                else y_cnt <= y_cnt + 1; // 进入下一行
            end else begin
                x_cnt <= x_cnt + 1;
            end
        end
    end

    assign vga_addr = {y_cnt, x_cnt};

    assign hsync = (x_cnt > h_frontporch);
    assign vsync = (y_cnt > v_frontporch);

    assign h_valid    = (h_active < x_cnt) & (x_cnt <= h_backporch);
    assign v_valid    = (v_active < y_cnt) & (y_cnt <= v_backporch);
    assign valid    = h_valid & v_valid;

    assign {vga_r, vga_g, vga_b} = vga_data;

endmodule
