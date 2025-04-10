module top(
    input clk, rst,
    input [31:0] inst,
    output [31:0] pc
);
    wire wen, success;
    wire [4:0] raddr, waddr, addr_s, addr_d;
    wire [31:0] rdata, wdata, imm;
    
    GPR u_GPR(
        .clk   	(clk    ),
        .wen   	(wen    ),
        .waddr 	(waddr  ),
        .raddr 	(raddr  ),
        .wdata 	(wdata  ),
        .rdata 	(rdata  )
    );
    
    PC u_PC(
        .clk    	(clk     ),
        .rst    	(rst     ),
        .next   	(success ),
        .pc_out 	(pc      )
    );
    
    Decode u_Decode(
        .inst   	(inst    ),
        .addr_s 	(addr_s  ),
        .addr_d 	(addr_d  ),
        .imm    	(imm     )
    );
    
    ADDI u_ADDI(
        .addr_s     	(addr_s      ),
        .addr_d     	(addr_d      ),
        .imm        	(imm         ),
        .src1       	(rdata       ),
        .wen        	(wen         ),
        .addr_s_out 	(raddr       ),
        .addr_d_out 	(waddr       ),
        .res        	(wdata       ),
        .success    	(success     )
    );
    
endmodule
