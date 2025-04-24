module top(
    input clk, rst,
    input [31:0] inst,
    output [31:0] pc
);
    wire [31:0] npc;
    wire [2:0] imm_type;
    wire wen;
    wire [1:0] pc_sel;
    wire [1:0] src1_sel;
    wire [31:0] imm;
    wire [31:0] src1;
    wire [31:0] src;
    wire [31:0] res;

    assign npc = ((pc_sel[1] == 0) ? pc : src1) + ((pc_sel[0] == 0) ? 4 : imm);

    PC u_PC(
        .clk 	(clk  ),
        .rst 	(rst  ),
        .npc 	(npc  ),
        .pc  	(pc   )
    );
    
    Decode u_Decode(
        .opcode   	(inst[6:0]      ),
        .funct3   	(inst[14:12]    ),
        .funct7   	(inst[31:25]    ),
        .imm_type 	(imm_type       ),
        .wen      	(wen            ),
        .src1_sel 	(src1_sel       ),
        .pc_sel     (pc_sel         )
    );
    
    ImmDecode u_ImmDecode(
        .imm_type 	(imm_type       ),
        .imm_in   	(inst[31:7]     ),
        .imm_out  	(imm            )
    );
    
    assign src =
            (src1_sel == 2'b00) ? 32'b0 :
            (src1_sel == 2'b01) ? pc    :
            (src1_sel == 2'b10) ? src1  :
            32'b0;

    ADD u_ADD(
        .imm 	(imm  ),
        .src 	(src  ),
        .res 	(res  )
    );
    
    GPR u_GPR(
        .clk   	(clk            ),
        .wen   	(wen            ),
        .waddr 	(inst[11:7]     ),
        .raddr 	(inst[19:15]    ),
        .wdata 	(res            ),
        .rdata 	(src1           )
    );
    
endmodule
