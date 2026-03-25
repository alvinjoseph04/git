//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Command: generate_target bd_978d.bd
//Design : bd_978d
//Purpose: IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "bd_978d,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=bd_978d,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=SBD,synth_mode=None}" *) (* HW_HANDOFF = "design_3_system_ila_0_0.hwdef" *) 
module bd_978d
   (SLOT_0_AHBLITE_haddr,
    SLOT_0_AHBLITE_hburst,
    SLOT_0_AHBLITE_hmastlock,
    SLOT_0_AHBLITE_hprot,
    SLOT_0_AHBLITE_hrdata,
    SLOT_0_AHBLITE_hready,
    SLOT_0_AHBLITE_hresp,
    SLOT_0_AHBLITE_hsize,
    SLOT_0_AHBLITE_htrans,
    SLOT_0_AHBLITE_hwdata,
    SLOT_0_AHBLITE_hwrite,
    clk,
    probe0);
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HADDR" *) (* X_INTERFACE_MODE = "Monitor SlaveType" *) input [31:0]SLOT_0_AHBLITE_haddr;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HBURST" *) input [2:0]SLOT_0_AHBLITE_hburst;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HMASTLOCK" *) input SLOT_0_AHBLITE_hmastlock;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HPROT" *) input [3:0]SLOT_0_AHBLITE_hprot;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HRDATA" *) input [31:0]SLOT_0_AHBLITE_hrdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HREADY" *) input SLOT_0_AHBLITE_hready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HRESP" *) input SLOT_0_AHBLITE_hresp;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HSIZE" *) input [2:0]SLOT_0_AHBLITE_hsize;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HTRANS" *) input [1:0]SLOT_0_AHBLITE_htrans;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HWDATA" *) input [31:0]SLOT_0_AHBLITE_hwdata;
  (* X_INTERFACE_INFO = "xilinx.com:interface:ahblite:2.0 SLOT_0_AHBLITE HWRITE" *) input SLOT_0_AHBLITE_hwrite;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.CLK CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.CLK, CLK_DOMAIN design_3_processing_system7_0_0_FCLK_CLK0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.0" *) input clk;
  input [0:0]probe0;

  wire [31:0]SLOT_0_AHBLITE_haddr;
  wire [2:0]SLOT_0_AHBLITE_hburst;
  wire SLOT_0_AHBLITE_hmastlock;
  wire [3:0]SLOT_0_AHBLITE_hprot;
  wire [31:0]SLOT_0_AHBLITE_hrdata;
  wire SLOT_0_AHBLITE_hready;
  wire SLOT_0_AHBLITE_hresp;
  wire [2:0]SLOT_0_AHBLITE_hsize;
  wire [1:0]SLOT_0_AHBLITE_htrans;
  wire [31:0]SLOT_0_AHBLITE_hwdata;
  wire SLOT_0_AHBLITE_hwrite;
  wire clk;
  wire [0:0]probe0;

  bd_978d_ila_lib_0 ila_lib
       (.clk(clk),
        .probe0(probe0),
        .probe1(SLOT_0_AHBLITE_haddr),
        .probe10(SLOT_0_AHBLITE_hwdata),
        .probe11(SLOT_0_AHBLITE_hwrite),
        .probe2(SLOT_0_AHBLITE_hburst),
        .probe3(SLOT_0_AHBLITE_hmastlock),
        .probe4(SLOT_0_AHBLITE_hprot),
        .probe5(SLOT_0_AHBLITE_hrdata),
        .probe6(SLOT_0_AHBLITE_hready),
        .probe7(SLOT_0_AHBLITE_hresp),
        .probe8(SLOT_0_AHBLITE_hsize),
        .probe9(SLOT_0_AHBLITE_htrans));
endmodule
