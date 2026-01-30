module sdram(
  input        clk,
  input        cke,
  input        cs,
  input        ras,
  input        cas,
  input        we,
  input [13:0] a,
  input [ 1:0] ba,
  input [ 3:0] dqm,
  inout [31:0] dq
);

  wire [2:0]  cmd = {ras, cas, we};
  wire        cs0 = (cmd == 'b111 | cmd == 'b000) ? 0:
                    !a[13] ? cs : 1;
  wire        cs1 = (cmd == 'b111 | cmd == 'b000) ? 0:
                    a[13] ? cs : 1;

  // a[13]=0 low 16bit
  sdram32Mx16 u00_sdram32Mx16(
    .clk 	(clk      ),
    .cke 	(cke      ),
    .cs  	(cs0      ),
    .ras 	(ras      ),
    .cas 	(cas      ),
    .we  	(we       ),
    .a   	(a[12:0]  ),
    .ba  	(ba       ),
    .dqm 	(dqm[1:0] ),
    .dq  	(dq[15:0] )
  );

  // a[13]=0 high 16bit
  sdram32Mx16 u01_sdram32Mx16(
    .clk 	(clk      ),
    .cke 	(cke      ),
    .cs  	(cs0      ),
    .ras 	(ras      ),
    .cas 	(cas      ),
    .we  	(we       ),
    .a   	(a[12:0]  ),
    .ba  	(ba       ),
    .dqm 	(dqm[3:2] ),
    .dq  	(dq[31:16])
  );
  
  // a[13]=1 low 16bit
  sdram32Mx16 u10_sdram32Mx16(
    .clk 	(clk      ),
    .cke 	(cke      ),
    .cs  	(cs1      ),
    .ras 	(ras      ),
    .cas 	(cas      ),
    .we  	(we       ),
    .a   	(a[12:0]  ),
    .ba  	(ba       ),
    .dqm 	(dqm[1:0] ),
    .dq  	(dq[15:0] )
  );

  // a[13]=1 high 16bit
  sdram32Mx16 u11_sdram32Mx16(
    .clk 	(clk      ),
    .cke 	(cke      ),
    .cs  	(cs1      ),
    .ras 	(ras      ),
    .cas 	(cas      ),
    .we  	(we       ),
    .a   	(a[12:0]  ),
    .ba  	(ba       ),
    .dqm 	(dqm[3:2] ),
    .dq  	(dq[31:16])
  );

endmodule
