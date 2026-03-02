// Data Hazard Detection Unit
`include "common.vh"
module DHDU(
    input [ 2:0] idu_inst_type_i,
    input [ 9:0] idu_gpr_rs_i,
    // Checking lsu_re to find out which one is load inst. Load in exls cannot forward.
    input        is_load_i,
    input [11:0] idu_csr_raddr_i,
    input        is_csr_i,
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

// Per-stage GPR match signals for rs1
wire rs1_idex_match = idex_we_i & (idex_rd_i != 0) & (rs1 == idex_rd_i);
wire rs1_exls_match = exls_we_i & (exls_rd_i != 0) & (rs1 == exls_rd_i);
wire rs1_lswb_match = lswb_we_i & (lswb_rd_i != 0) & (rs1 == lswb_rd_i);

// Per-stage GPR match signals for rs2
wire rs2_idex_match = idex_we_i & (idex_rd_i != 0) & (rs2 == idex_rd_i);
wire rs2_exls_match = exls_we_i & (exls_rd_i != 0) & (rs2 == exls_rd_i);
wire rs2_lswb_match = lswb_we_i & (lswb_rd_i != 0) & (rs2 == lswb_rd_i);

wire rs1_hazard = rs1_idex_match | rs1_exls_match | rs1_lswb_match;
wire rs2_hazard = rs2_idex_match | rs2_exls_match | rs2_lswb_match;

// exls can only forward when it is NOT a load instruction (load data not ready in exls)
wire rs1_exls_can_fwd = rs1_exls_match & !is_load_i & !rs1_idex_match;
wire rs2_exls_can_fwd = rs2_exls_match & !is_load_i & !rs2_idex_match;
// lswb can forward (including load results) only when no closer stage shadows it
wire rs1_lswb_can_fwd = rs1_lswb_match & !rs1_idex_match & !rs1_exls_match;
wire rs2_lswb_can_fwd = rs2_lswb_match & !rs2_idex_match & !rs2_exls_match;

// Forwarding select for rs1: exls priority > lswb
// 00 -> GPR, 01 -> exls forward, 10 -> lswb forward
assign exu_rs1_sel_o = rs1_exls_can_fwd ? 2'b01 :
                        rs1_lswb_can_fwd ? 2'b10 :
                        2'b00;

// Forwarding select for rs2: same priority
assign exu_rs2_sel_o = rs2_exls_can_fwd ? 2'b01 :
                        rs2_lswb_can_fwd ? 2'b10 :
                        2'b00;

// Can be resolved by forwarding
wire rs1_can_fwd = rs1_exls_can_fwd | rs1_lswb_can_fwd;
wire rs2_can_fwd = rs2_exls_can_fwd | rs2_lswb_can_fwd;

// GPR hazard that cannot be resolved by forwarding → stall
// Cases: idex match, or exls match with load (data not ready yet)
wire rs1_stall = rs1_hazard & !rs1_can_fwd;
wire rs2_stall = rs2_hazard & !rs2_can_fwd & use_rs2;

wire [11:0] csr_addr_check = is_ecall_i ? 12'h305 : 12'h341;
wire csr_hazard =   (idex_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == idex_csr_waddr_i) : (idex_csr_waddr_i == csr_addr_check)))|
                    (exls_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == exls_csr_waddr_i) : (exls_csr_waddr_i == csr_addr_check)))|
                    (lswb_csr_we_i & (~(is_ecall_i | is_mret_i) ? (idu_csr_raddr_i == lswb_csr_waddr_i) : (lswb_csr_waddr_i == csr_addr_check)));
wire ecall_hazard = (idex_ecall | exls_ecall | lswb_ecall)&
                    (idu_csr_raddr_i == 12'h341 | idu_csr_raddr_i == 12'h342 | idu_csr_raddr_i == 12'h300);
wire mret_hazard  = (idex_mret | exls_mret | lswb_mret) & (idu_csr_raddr_i == 12'h300);

wire gpr_hazard = (rs1_stall | rs2_stall);
wire csr_read_hazard = is_csr_i & csr_hazard & rs1_hazard;
wire ecall_read_hazard = is_ecall_i & ecall_hazard;
wire mret_read_hazard = is_mret_i & mret_hazard;
wire stall = need_check &
        (gpr_hazard |
        csr_read_hazard |
        ecall_read_hazard |
        mret_read_hazard);

assign dhdu_idex_valid_o = id_dhdu_valid_i & !stall;

endmodule
