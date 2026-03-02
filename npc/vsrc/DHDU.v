// Data Hazard Detection Unit
`include "common.vh"
module DHDU(
    input [ 2:0] idu_inst_type_i,
    input [ 9:0] idu_gpr_rs_i,
    // Checking lsu_re to find out which one is load inst. And load inst cannot use forward.
    // input        idu_is_load,
    input [11:0] idu_csr_raddr_i,
    input        use_csr_i,
    input        is_ecall_i,
    input        is_mret_i,

    input [ 4:0] idex_rd_i,
    input        idex_we_i,
    input [11:0] idex_csr_waddr_i,
    input        idex_csr_we_i,
    input        idex_ecall,
    input        idex_mret,
    input [ 4:0] exls_rd_i,
    input        exls_we_i,
    input [11:0] exls_csr_waddr_i,
    input        exls_csr_we_i,
    input        exls_ecall,
    input        exls_mret,
    input [ 4:0] lswb_rd_i,
    input        lswb_we_i,
    input [11:0] lswb_csr_waddr_i,
    input        lswb_csr_we_i,
    input        lswb_ecall,
    input        lswb_mret,

    // 00b -> use GPR, 01b -> use ex_ls,  10b -> use ls_wb, 11b -> Unused
    // output[ 1:0] exu_rs1_sel_o,
    // output[ 1:0] exu_rs2_sel_o,

    input        id_dhdu_valid_i,
    output       dhdu_idex_valid_o
);

wire need_check = ~(idu_inst_type_i == `INST_TYPE_U | idu_inst_type_i == `INST_TYPE_J) |
                    use_csr_i | is_ecall_i | is_mret_i;
wire use_rs2 = ~(idu_inst_type_i == `INST_TYPE_I);
wire [4:0] rs1 = idu_gpr_rs_i[4:0];
wire [4:0] rs2 = idu_gpr_rs_i[9:5];
wire rs1_hazard =   (idex_we_i & (idex_rd_i != 0) & (rs1 == idex_rd_i))|
                    (exls_we_i & (exls_rd_i != 0) & (rs1 == exls_rd_i))|
                    (lswb_we_i & (lswb_rd_i != 0) & (rs1 == lswb_rd_i));
wire rs2_hazard =   (idex_we_i & (idex_rd_i != 0) & (rs2 == idex_rd_i))|
                    (exls_we_i & (exls_rd_i != 0) & (rs2 == exls_rd_i))|
                    (lswb_we_i & (lswb_rd_i != 0) & (rs2 == lswb_rd_i));
wire [11:0] csr_addr_check = is_ecall_i ? 12'h305 : 12'h341;
wire csr_hazard =   (idex_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == idex_csr_waddr_i) : (idex_csr_waddr_i == csr_addr_check)))|
                    (exls_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == exls_csr_waddr_i) : (exls_csr_waddr_i == csr_addr_check)))|
                    (lswb_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == lswb_csr_waddr_i) : (lswb_csr_waddr_i == csr_addr_check)));
wire ecall_hazard = (idex_ecall | exls_ecall | lswb_ecall)&
                    (idu_csr_raddr_i == 12'h341 | idu_csr_raddr_i == 12'h342 | idu_csr_raddr_i == 12'h300);
wire mret_hazard  = (idex_mret | exls_mret | lswb_mret) & (idu_csr_raddr_i == 12'h300);

wire gpr_hazard =
        (rs1_hazard |
        (rs2_hazard & use_rs2));
wire csr_read_hazard =
        use_csr_i & csr_hazard;
wire ecall_read_hazard =
        is_ecall_i & ecall_hazard;
wire mret_read_hazard =
        is_mret_i & mret_hazard;
wire stall =
        need_check &
        (gpr_hazard |
        csr_read_hazard |
        ecall_read_hazard |
        mret_read_hazard);

assign dhdu_idex_valid_o = id_dhdu_valid_i & !stall;

endmodule
