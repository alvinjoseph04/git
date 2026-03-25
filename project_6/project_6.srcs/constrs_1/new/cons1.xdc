set_property -dict {PACKAGE_PIN Y19 IOSTANDARD LVCMOS33} [get_ports {CAN_0_0_rx}]
set_property -dict {PACKAGE_PIN Y18 IOSTANDARD LVCMOS33} [get_ports {CAN_0_0_tx}]
set_property -dict {PACKAGE_PIN Y17 IOSTANDARD LVCMOS33} [get_ports {iic_rtl_scl_io}]
set_property -dict {PACKAGE_PIN Y16 IOSTANDARD LVCMOS33} [get_ports {iic_rtl_sda_io}]

#set_property -dict {PACKAGE_PIN U18 IOSTANDARD LVCMOS33} [get_ports {uart_rtl_rxd}]
#set_property -dict {PACKAGE_PIN U19 IOSTANDARD LVCMOS33} [get_ports {uart_rtl_txd}]

#set_property -dict {PACKAGE_PIN D19 IOSTANDARD LVCMOS33} [get_ports {reset_rtl}]
# Explicitly set IOSTANDARD for the internal I2C buffer signals
#set_property IOSTANDARD LVCMOS33 [get_ports iic_rtl_scl_i]
#set_property IOSTANDARD LVCMOS33 [get_ports iic_rtl_scl_t]
#set_property IOSTANDARD LVCMOS33 [get_ports iic_rtl_sda_i]
#set_property IOSTANDARD LVCMOS33 [get_ports iic_rtl_sda_t]