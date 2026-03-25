-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2025.1 (win64) Build 6140274 Thu May 22 00:12:29 MDT 2025
-- Date        : Thu Mar 19 10:18:11 2026
-- Host        : 7RMY0V3 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_3_axi_ahblite_bridge_0_0_stub.vhdl
-- Design      : design_3_axi_ahblite_bridge_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    s_axi_aclk : in STD_LOGIC;
    s_axi_aresetn : in STD_LOGIC;
    s_axi_awlen : in STD_LOGIC_VECTOR ( 7 downto 0 );
    s_axi_awsize : in STD_LOGIC_VECTOR ( 2 downto 0 );
    s_axi_awburst : in STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_awcache : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_awaddr : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_awprot : in STD_LOGIC_VECTOR ( 2 downto 0 );
    s_axi_awvalid : in STD_LOGIC;
    s_axi_awready : out STD_LOGIC;
    s_axi_awlock : in STD_LOGIC;
    s_axi_wdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_wstrb : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_wlast : in STD_LOGIC;
    s_axi_wvalid : in STD_LOGIC;
    s_axi_wready : out STD_LOGIC;
    s_axi_bresp : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_bvalid : out STD_LOGIC;
    s_axi_bready : in STD_LOGIC;
    s_axi_araddr : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_arprot : in STD_LOGIC_VECTOR ( 2 downto 0 );
    s_axi_arcache : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_arvalid : in STD_LOGIC;
    s_axi_arlen : in STD_LOGIC_VECTOR ( 7 downto 0 );
    s_axi_arsize : in STD_LOGIC_VECTOR ( 2 downto 0 );
    s_axi_arburst : in STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_arlock : in STD_LOGIC;
    s_axi_arready : out STD_LOGIC;
    s_axi_rdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_rresp : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_rvalid : out STD_LOGIC;
    s_axi_rlast : out STD_LOGIC;
    s_axi_rready : in STD_LOGIC;
    m_ahb_haddr : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_ahb_hwrite : out STD_LOGIC;
    m_ahb_hsize : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_ahb_hburst : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_ahb_hprot : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_ahb_htrans : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_ahb_hmastlock : out STD_LOGIC;
    m_ahb_hwdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_ahb_hready : in STD_LOGIC;
    m_ahb_hrdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_ahb_hresp : in STD_LOGIC
  );

  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_3_axi_ahblite_bridge_0_0,axi_ahblite_bridge,{}";
  attribute core_generation_info : string;
  attribute core_generation_info of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_3_axi_ahblite_bridge_0_0,axi_ahblite_bridge,{x_ipProduct=Vivado 2025.1,x_ipVendor=xilinx.com,x_ipLibrary=ip,x_ipName=axi_ahblite_bridge,x_ipVersion=3.0,x_ipCoreRevision=31,x_ipLanguage=VERILOG,x_ipSimLanguage=MIXED,C_FAMILY=zynq,C_INSTANCE=design_3_axi_ahblite_bridge_0_0,C_S_AXI_ADDR_WIDTH=32,C_S_AXI_DATA_WIDTH=32,C_S_AXI_SUPPORTS_NARROW_BURST=0,C_S_AXI_ID_WIDTH=1,C_M_AHB_ADDR_WIDTH=32,C_M_AHB_DATA_WIDTH=32,C_DPHASE_TIMEOUT=0}";
  attribute downgradeipidentifiedwarnings : string;
  attribute downgradeipidentifiedwarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  attribute syn_black_box : boolean;
  attribute black_box_pad_pin : string;
  attribute syn_black_box of stub : architecture is true;
  attribute black_box_pad_pin of stub : architecture is "s_axi_aclk,s_axi_aresetn,s_axi_awlen[7:0],s_axi_awsize[2:0],s_axi_awburst[1:0],s_axi_awcache[3:0],s_axi_awaddr[31:0],s_axi_awprot[2:0],s_axi_awvalid,s_axi_awready,s_axi_awlock,s_axi_wdata[31:0],s_axi_wstrb[3:0],s_axi_wlast,s_axi_wvalid,s_axi_wready,s_axi_bresp[1:0],s_axi_bvalid,s_axi_bready,s_axi_araddr[31:0],s_axi_arprot[2:0],s_axi_arcache[3:0],s_axi_arvalid,s_axi_arlen[7:0],s_axi_arsize[2:0],s_axi_arburst[1:0],s_axi_arlock,s_axi_arready,s_axi_rdata[31:0],s_axi_rresp[1:0],s_axi_rvalid,s_axi_rlast,s_axi_rready,m_ahb_haddr[31:0],m_ahb_hwrite,m_ahb_hsize[2:0],m_ahb_hburst[2:0],m_ahb_hprot[3:0],m_ahb_htrans[1:0],m_ahb_hmastlock,m_ahb_hwdata[31:0],m_ahb_hready,m_ahb_hrdata[31:0],m_ahb_hresp";
  attribute x_interface_info : string;
  attribute x_interface_info of s_axi_aclk : signal is "xilinx.com:signal:clock:1.0 ACLK CLK";
  attribute x_interface_mode : string;
  attribute x_interface_mode of s_axi_aclk : signal is "slave ACLK";
  attribute x_interface_parameter : string;
  attribute x_interface_parameter of s_axi_aclk : signal is "XIL_INTERFACENAME ACLK, ASSOCIATED_BUSIF AXI4:M_AHB, ASSOCIATED_RESET s_axi_aresetn, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN design_3_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0";
  attribute x_interface_info of s_axi_aresetn : signal is "xilinx.com:signal:reset:1.0 ARESETN RST";
  attribute x_interface_mode of s_axi_aresetn : signal is "slave ARESETN";
  attribute x_interface_parameter of s_axi_aresetn : signal is "XIL_INTERFACENAME ARESETN, POLARITY ACTIVE_LOW, INSERT_VIP 0";
  attribute x_interface_info of s_axi_awlen : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWLEN";
  attribute x_interface_mode of s_axi_awlen : signal is "slave AXI4";
  attribute x_interface_parameter of s_axi_awlen : signal is "XIL_INTERFACENAME AXI4, BD_ATTRIBUTE.TYPE INTERIOR, DATA_WIDTH 32, PROTOCOL AXI4, FREQ_HZ 100000000, ID_WIDTH 0, ADDR_WIDTH 32, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 1, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 8, NUM_WRITE_OUTSTANDING 8, MAX_BURST_LENGTH 16, PHASE 0.0, CLK_DOMAIN design_3_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0";
  attribute x_interface_info of s_axi_awsize : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWSIZE";
  attribute x_interface_info of s_axi_awburst : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWBURST";
  attribute x_interface_info of s_axi_awcache : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWCACHE";
  attribute x_interface_info of s_axi_awaddr : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWADDR";
  attribute x_interface_info of s_axi_awprot : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWPROT";
  attribute x_interface_info of s_axi_awvalid : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWVALID";
  attribute x_interface_info of s_axi_awready : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWREADY";
  attribute x_interface_info of s_axi_awlock : signal is "xilinx.com:interface:aximm:1.0 AXI4 AWLOCK";
  attribute x_interface_info of s_axi_wdata : signal is "xilinx.com:interface:aximm:1.0 AXI4 WDATA";
  attribute x_interface_info of s_axi_wstrb : signal is "xilinx.com:interface:aximm:1.0 AXI4 WSTRB";
  attribute x_interface_info of s_axi_wlast : signal is "xilinx.com:interface:aximm:1.0 AXI4 WLAST";
  attribute x_interface_info of s_axi_wvalid : signal is "xilinx.com:interface:aximm:1.0 AXI4 WVALID";
  attribute x_interface_info of s_axi_wready : signal is "xilinx.com:interface:aximm:1.0 AXI4 WREADY";
  attribute x_interface_info of s_axi_bresp : signal is "xilinx.com:interface:aximm:1.0 AXI4 BRESP";
  attribute x_interface_info of s_axi_bvalid : signal is "xilinx.com:interface:aximm:1.0 AXI4 BVALID";
  attribute x_interface_info of s_axi_bready : signal is "xilinx.com:interface:aximm:1.0 AXI4 BREADY";
  attribute x_interface_info of s_axi_araddr : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARADDR";
  attribute x_interface_info of s_axi_arprot : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARPROT";
  attribute x_interface_info of s_axi_arcache : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARCACHE";
  attribute x_interface_info of s_axi_arvalid : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARVALID";
  attribute x_interface_info of s_axi_arlen : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARLEN";
  attribute x_interface_info of s_axi_arsize : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARSIZE";
  attribute x_interface_info of s_axi_arburst : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARBURST";
  attribute x_interface_info of s_axi_arlock : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARLOCK";
  attribute x_interface_info of s_axi_arready : signal is "xilinx.com:interface:aximm:1.0 AXI4 ARREADY";
  attribute x_interface_info of s_axi_rdata : signal is "xilinx.com:interface:aximm:1.0 AXI4 RDATA";
  attribute x_interface_info of s_axi_rresp : signal is "xilinx.com:interface:aximm:1.0 AXI4 RRESP";
  attribute x_interface_info of s_axi_rvalid : signal is "xilinx.com:interface:aximm:1.0 AXI4 RVALID";
  attribute x_interface_info of s_axi_rlast : signal is "xilinx.com:interface:aximm:1.0 AXI4 RLAST";
  attribute x_interface_info of s_axi_rready : signal is "xilinx.com:interface:aximm:1.0 AXI4 RREADY";
  attribute x_interface_info of m_ahb_haddr : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HADDR";
  attribute x_interface_mode of m_ahb_haddr : signal is "master M_AHB";
  attribute x_interface_info of m_ahb_hwrite : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HWRITE";
  attribute x_interface_info of m_ahb_hsize : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HSIZE";
  attribute x_interface_info of m_ahb_hburst : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HBURST";
  attribute x_interface_info of m_ahb_hprot : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HPROT";
  attribute x_interface_info of m_ahb_htrans : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HTRANS";
  attribute x_interface_info of m_ahb_hmastlock : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HMASTLOCK";
  attribute x_interface_info of m_ahb_hwdata : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HWDATA";
  attribute x_interface_info of m_ahb_hready : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HREADY";
  attribute x_interface_info of m_ahb_hrdata : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HRDATA";
  attribute x_interface_info of m_ahb_hresp : signal is "xilinx.com:interface:ahblite:2.0 M_AHB HRESP";
  attribute x_core_info : string;
  attribute x_core_info of stub : architecture is "axi_ahblite_bridge,Vivado 2025.1";
begin
end;
