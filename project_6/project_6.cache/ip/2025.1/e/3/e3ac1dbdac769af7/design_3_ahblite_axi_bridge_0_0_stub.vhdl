-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2025.1 (win64) Build 6140274 Thu May 22 00:12:29 MDT 2025
-- Date        : Thu Mar 19 10:17:51 2026
-- Host        : 7RMY0V3 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_3_ahblite_axi_bridge_0_0_stub.vhdl
-- Design      : design_3_ahblite_axi_bridge_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    s_ahb_hclk : in STD_LOGIC;
    s_ahb_hresetn : in STD_LOGIC;
    s_ahb_hsel : in STD_LOGIC;
    s_ahb_haddr : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_ahb_hprot : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_ahb_htrans : in STD_LOGIC_VECTOR ( 1 downto 0 );
    s_ahb_hsize : in STD_LOGIC_VECTOR ( 2 downto 0 );
    s_ahb_hwrite : in STD_LOGIC;
    s_ahb_hburst : in STD_LOGIC_VECTOR ( 2 downto 0 );
    s_ahb_hwdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_ahb_hready_out : out STD_LOGIC;
    s_ahb_hready_in : in STD_LOGIC;
    s_ahb_hrdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_ahb_hresp : out STD_LOGIC;
    m_axi_awid : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_awlen : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_awsize : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_awburst : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_awcache : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_awaddr : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_awprot : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_awvalid : out STD_LOGIC;
    m_axi_awready : in STD_LOGIC;
    m_axi_awlock : out STD_LOGIC;
    m_axi_wdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_wstrb : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_wlast : out STD_LOGIC;
    m_axi_wvalid : out STD_LOGIC;
    m_axi_wready : in STD_LOGIC;
    m_axi_bid : in STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_bresp : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_bvalid : in STD_LOGIC;
    m_axi_bready : out STD_LOGIC;
    m_axi_arid : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_arlen : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_arsize : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_arburst : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_arprot : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_arcache : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_arvalid : out STD_LOGIC;
    m_axi_araddr : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_arlock : out STD_LOGIC;
    m_axi_arready : in STD_LOGIC;
    m_axi_rid : in STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_rdata : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_rresp : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_rvalid : in STD_LOGIC;
    m_axi_rlast : in STD_LOGIC;
    m_axi_rready : out STD_LOGIC
  );

  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_3_ahblite_axi_bridge_0_0,ahblite_axi_bridge,{}";
  attribute core_generation_info : string;
  attribute core_generation_info of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_3_ahblite_axi_bridge_0_0,ahblite_axi_bridge,{x_ipProduct=Vivado 2025.1,x_ipVendor=xilinx.com,x_ipLibrary=ip,x_ipName=ahblite_axi_bridge,x_ipVersion=3.0,x_ipCoreRevision=29,x_ipLanguage=VERILOG,x_ipSimLanguage=MIXED,C_FAMILY=zynq,C_INSTANCE=design_3_ahblite_axi_bridge_0_0,C_M_AXI_SUPPORTS_NARROW_BURST=0,C_M_AXI_NON_SECURE=1,C_S_AHB_ADDR_WIDTH=32,C_M_AXI_ADDR_WIDTH=32,C_S_AHB_DATA_WIDTH=32,C_M_AXI_DATA_WIDTH=32,C_M_AXI_PROTOCOL=AXI4,C_M_AXI_THREAD_ID_WIDTH=4,C_AHB_AXI_TIMEOUT=0}";
  attribute downgradeipidentifiedwarnings : string;
  attribute downgradeipidentifiedwarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  attribute syn_black_box : boolean;
  attribute black_box_pad_pin : string;
  attribute syn_black_box of stub : architecture is true;
  attribute black_box_pad_pin of stub : architecture is "s_ahb_hclk,s_ahb_hresetn,s_ahb_hsel,s_ahb_haddr[31:0],s_ahb_hprot[3:0],s_ahb_htrans[1:0],s_ahb_hsize[2:0],s_ahb_hwrite,s_ahb_hburst[2:0],s_ahb_hwdata[31:0],s_ahb_hready_out,s_ahb_hready_in,s_ahb_hrdata[31:0],s_ahb_hresp,m_axi_awid[3:0],m_axi_awlen[7:0],m_axi_awsize[2:0],m_axi_awburst[1:0],m_axi_awcache[3:0],m_axi_awaddr[31:0],m_axi_awprot[2:0],m_axi_awvalid,m_axi_awready,m_axi_awlock,m_axi_wdata[31:0],m_axi_wstrb[3:0],m_axi_wlast,m_axi_wvalid,m_axi_wready,m_axi_bid[3:0],m_axi_bresp[1:0],m_axi_bvalid,m_axi_bready,m_axi_arid[3:0],m_axi_arlen[7:0],m_axi_arsize[2:0],m_axi_arburst[1:0],m_axi_arprot[2:0],m_axi_arcache[3:0],m_axi_arvalid,m_axi_araddr[31:0],m_axi_arlock,m_axi_arready,m_axi_rid[3:0],m_axi_rdata[31:0],m_axi_rresp[1:0],m_axi_rvalid,m_axi_rlast,m_axi_rready";
  attribute x_interface_info : string;
  attribute x_interface_info of s_ahb_hclk : signal is "xilinx.com:signal:clock:1.0 AHB_CLK CLK";
  attribute x_interface_mode : string;
  attribute x_interface_mode of s_ahb_hclk : signal is "slave AHB_CLK";
  attribute x_interface_parameter : string;
  attribute x_interface_parameter of s_ahb_hclk : signal is "XIL_INTERFACENAME AHB_CLK, ASSOCIATED_BUSIF AHB_INTERFACE:M_AXI, ASSOCIATED_RESET s_ahb_hresetn, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN design_3_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0";
  attribute x_interface_info of s_ahb_hresetn : signal is "xilinx.com:signal:reset:1.0 AHB_RESETN RST";
  attribute x_interface_mode of s_ahb_hresetn : signal is "slave AHB_RESETN";
  attribute x_interface_parameter of s_ahb_hresetn : signal is "XIL_INTERFACENAME AHB_RESETN, POLARITY ACTIVE_LOW, INSERT_VIP 0";
  attribute x_interface_info of s_ahb_hsel : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE SEL";
  attribute x_interface_mode of s_ahb_hsel : signal is "slave AHB_INTERFACE";
  attribute x_interface_parameter of s_ahb_hsel : signal is "XIL_INTERFACENAME AHB_INTERFACE, BD_ATTRIBUTE.TYPE INTERIOR";
  attribute x_interface_info of s_ahb_haddr : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HADDR";
  attribute x_interface_info of s_ahb_hprot : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HPROT";
  attribute x_interface_info of s_ahb_htrans : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HTRANS";
  attribute x_interface_info of s_ahb_hsize : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HSIZE";
  attribute x_interface_info of s_ahb_hwrite : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HWRITE";
  attribute x_interface_info of s_ahb_hburst : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HBURST";
  attribute x_interface_info of s_ahb_hwdata : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HWDATA";
  attribute x_interface_info of s_ahb_hready_out : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HREADY_OUT";
  attribute x_interface_info of s_ahb_hready_in : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HREADY_IN";
  attribute x_interface_info of s_ahb_hrdata : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HRDATA";
  attribute x_interface_info of s_ahb_hresp : signal is "xilinx.com:interface:ahblite:2.0 AHB_INTERFACE HRESP";
  attribute x_interface_info of m_axi_awid : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWID";
  attribute x_interface_mode of m_axi_awid : signal is "master M_AXI";
  attribute x_interface_parameter of m_axi_awid : signal is "XIL_INTERFACENAME M_AXI, MAX_BURST_LENGTH 16, DATA_WIDTH 32, PROTOCOL AXI4, FREQ_HZ 100000000, ID_WIDTH 4, ADDR_WIDTH 32, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, READ_WRITE_MODE READ_WRITE, HAS_BURST 0, HAS_LOCK 1, HAS_PROT 1, HAS_CACHE 1, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 2, NUM_WRITE_OUTSTANDING 2, PHASE 0.0, CLK_DOMAIN design_3_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0";
  attribute x_interface_info of m_axi_awlen : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWLEN";
  attribute x_interface_info of m_axi_awsize : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWSIZE";
  attribute x_interface_info of m_axi_awburst : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWBURST";
  attribute x_interface_info of m_axi_awcache : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWCACHE";
  attribute x_interface_info of m_axi_awaddr : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWADDR";
  attribute x_interface_info of m_axi_awprot : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWPROT";
  attribute x_interface_info of m_axi_awvalid : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWVALID";
  attribute x_interface_info of m_axi_awready : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWREADY";
  attribute x_interface_info of m_axi_awlock : signal is "xilinx.com:interface:aximm:1.0 M_AXI AWLOCK";
  attribute x_interface_info of m_axi_wdata : signal is "xilinx.com:interface:aximm:1.0 M_AXI WDATA";
  attribute x_interface_info of m_axi_wstrb : signal is "xilinx.com:interface:aximm:1.0 M_AXI WSTRB";
  attribute x_interface_info of m_axi_wlast : signal is "xilinx.com:interface:aximm:1.0 M_AXI WLAST";
  attribute x_interface_info of m_axi_wvalid : signal is "xilinx.com:interface:aximm:1.0 M_AXI WVALID";
  attribute x_interface_info of m_axi_wready : signal is "xilinx.com:interface:aximm:1.0 M_AXI WREADY";
  attribute x_interface_info of m_axi_bid : signal is "xilinx.com:interface:aximm:1.0 M_AXI BID";
  attribute x_interface_info of m_axi_bresp : signal is "xilinx.com:interface:aximm:1.0 M_AXI BRESP";
  attribute x_interface_info of m_axi_bvalid : signal is "xilinx.com:interface:aximm:1.0 M_AXI BVALID";
  attribute x_interface_info of m_axi_bready : signal is "xilinx.com:interface:aximm:1.0 M_AXI BREADY";
  attribute x_interface_info of m_axi_arid : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARID";
  attribute x_interface_info of m_axi_arlen : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARLEN";
  attribute x_interface_info of m_axi_arsize : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARSIZE";
  attribute x_interface_info of m_axi_arburst : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARBURST";
  attribute x_interface_info of m_axi_arprot : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARPROT";
  attribute x_interface_info of m_axi_arcache : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARCACHE";
  attribute x_interface_info of m_axi_arvalid : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARVALID";
  attribute x_interface_info of m_axi_araddr : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARADDR";
  attribute x_interface_info of m_axi_arlock : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARLOCK";
  attribute x_interface_info of m_axi_arready : signal is "xilinx.com:interface:aximm:1.0 M_AXI ARREADY";
  attribute x_interface_info of m_axi_rid : signal is "xilinx.com:interface:aximm:1.0 M_AXI RID";
  attribute x_interface_info of m_axi_rdata : signal is "xilinx.com:interface:aximm:1.0 M_AXI RDATA";
  attribute x_interface_info of m_axi_rresp : signal is "xilinx.com:interface:aximm:1.0 M_AXI RRESP";
  attribute x_interface_info of m_axi_rvalid : signal is "xilinx.com:interface:aximm:1.0 M_AXI RVALID";
  attribute x_interface_info of m_axi_rlast : signal is "xilinx.com:interface:aximm:1.0 M_AXI RLAST";
  attribute x_interface_info of m_axi_rready : signal is "xilinx.com:interface:aximm:1.0 M_AXI RREADY";
  attribute x_core_info : string;
  attribute x_core_info of stub : architecture is "ahblite_axi_bridge,Vivado 2025.1";
begin
end;
