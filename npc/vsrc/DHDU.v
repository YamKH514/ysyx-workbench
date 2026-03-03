// Data Hazard Detection Unit
`include "common.vh"
module DHDU(
    input [ 2:0] idu_inst_type_i,
    input [ 9:0] idu_gpr_rs_i,

    input [11:0] idu_csr_raddr_i,
    input        is_csr_i,
    input        is_ecall_i,
    input        is_mret_i,

    input [ 4:0] exls_rd_i,
    input        exls_we_i,
    input [11:0] exls_csr_waddr_i,
    input        exls_csr_we_i,
    input        exls_ecall,
    input        exls_mret,
    input        exls_is_load,
    input [ 4:0] lswb_rd_i,
    input        lswb_we_i,
    input [11:0] lswb_csr_waddr_i,
    input        lswb_csr_we_i,
    input        lswb_ecall,
    input        lswb_mret,

    // 2'b00 -> use GPR, 2'b01 -> use EX_LS, 2'b10 -> use LS_WB, 2'b11 -> Unused
    output[ 1:0] exu_rs1_sel_o,
    output[ 1:0] exu_rs2_sel_o,

    input        id_dhdu_valid_i,
    output       dhdu_idex_valid_o
);

wire need_check = ~(idu_inst_type_i == `INST_TYPE_U | idu_inst_type_i == `INST_TYPE_J) |
                    is_csr_i | is_ecall_i | is_mret_i;
wire use_rs2 = ~(idu_inst_type_i == `INST_TYPE_I);
wire [4:0] rs1 = idu_gpr_rs_i[4:0];
wire [4:0] rs2 = idu_gpr_rs_i[9:5];
// wire rs1_hazard =   (exls_we_i & (exls_rd_i != 0) & (rs1 == exls_rd_i))|
//                     (lswb_we_i & (lswb_rd_i != 0) & (rs1 == lswb_rd_i));
// wire rs2_hazard =   (exls_we_i & (exls_rd_i != 0) & (rs2 == exls_rd_i))|
//                     (lswb_we_i & (lswb_rd_i != 0) & (rs2 == lswb_rd_i));
wire [11:0] csr_addr_check = is_ecall_i ? 12'h305 : 12'h341;
wire csr_hazard =   (exls_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == exls_csr_waddr_i) : (exls_csr_waddr_i == csr_addr_check)))|
                    (lswb_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == lswb_csr_waddr_i) : (lswb_csr_waddr_i == csr_addr_check)));
wire ecall_hazard = (exls_ecall | lswb_ecall)&
                    (idu_csr_raddr_i == 12'h341 | idu_csr_raddr_i == 12'h342 | idu_csr_raddr_i == 12'h300);
wire mret_hazard  = (exls_mret | lswb_mret) & (idu_csr_raddr_i == 12'h300);

// wire gpr_hazard =
//         (rs1_hazard |
//         (rs2_hazard & use_rs2));
wire csr_read_hazard =
        is_csr_i & csr_hazard;
wire ecall_read_hazard =
        is_ecall_i & ecall_hazard;
wire mret_read_hazard =
        is_mret_i & mret_hazard;
// wire stall =
//         need_check &
//         (gpr_hazard |
//         csr_read_hazard |
//         ecall_read_hazard |
//         mret_read_hazard);

// assign dhdu_idex_valid_o = id_dhdu_valid_i & !stall;

wire rs1_from_exls =
    exls_we_i &&
    !exls_is_load &&
    (exls_rd_i != 0) &&
    (rs1 == exls_rd_i);
wire rs1_from_lswb =
    lswb_we_i &&
    (lswb_rd_i != 0) &&
    (rs1 == lswb_rd_i);

wire rs2_from_exls =
    exls_we_i &&
    !exls_is_load &&
    (exls_rd_i != 0) &&
    (rs2 == exls_rd_i);
wire rs2_from_lswb =
    lswb_we_i &&
    (lswb_rd_i != 0) &&
    (rs2 == lswb_rd_i);

wire rs1_load_use =
    exls_we_i &&
    exls_is_load &&
    (exls_rd_i != 0) &&
    (rs1 == exls_rd_i);
wire rs2_load_use =
    exls_we_i &&
    exls_is_load &&
    (exls_rd_i != 0) &&
    (rs2 == exls_rd_i);

assign exu_rs1_sel_o =
    rs1_from_exls ? 2'b01 :
    rs1_from_lswb ? 2'b10 :
                    2'b00;
assign exu_rs2_sel_o =
    rs2_from_exls ? 2'b01 :
    rs2_from_lswb ? 2'b10 :
                    2'b00;

wire csr_stall =
    csr_read_hazard |
    ecall_read_hazard |
    mret_read_hazard;
wire load_use_stall =
    rs1_load_use |
    (rs2_load_use & use_rs2);
wire gpr_stall = load_use_stall;
wire stall =
    need_check &
    (gpr_stall | csr_stall);

assign dhdu_idex_valid_o = id_dhdu_valid_i & !stall;

endmodule
