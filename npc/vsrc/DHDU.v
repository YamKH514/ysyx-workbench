// Data Hazard Detection Unit
`include "common.vh"
module DHDU(
    input [2:0] idu_inst_type_i,
    input [9:0] idu_gpr_rs,

    input [4:0] idex_rd_i,
    input       idex_we_i,

    input [4:0] exls_rd_i,
    input       exls_we_i,

    input [4:0] lswb_rd_i,
    input       lswb_we_i,

    input       id_dhdu_valid_i,
    output      dhdu_idex_valid_o
);

wire need_check = ~(idu_inst_type_i == `INST_TYPE_U | idu_inst_type_i == `INST_TYPE_J);
wire use_rs2 = ~(idu_inst_type_i == `INST_TYPE_I);
wire [4:0] rs1 = idu_gpr_rs[4:0];
wire [4:0] rs2 = idu_gpr_rs[9:5];
wire rs1_hazard =   (idex_we_i & (idex_rd_i != 0) & (rs1 == idex_rd_i))|
                    (exls_we_i & (exls_rd_i != 0) & (rs1 == exls_rd_i))|
                    (lswb_we_i & (lswb_rd_i != 0) & (rs1 == lswb_rd_i));
wire rs2_hazard =   (idex_we_i & (idex_rd_i != 0) & (rs2 == idex_rd_i))|
                    (exls_we_i & (exls_rd_i != 0) & (rs2 == exls_rd_i))|
                    (lswb_we_i & (lswb_rd_i != 0) & (rs2 == lswb_rd_i));

assign dhdu_idex_valid_o = id_dhdu_valid_i & (!need_check | !(rs1_hazard | (rs2_hazard & use_rs2)));

endmodule
