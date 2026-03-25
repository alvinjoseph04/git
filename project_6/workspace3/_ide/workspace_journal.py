# 2026-03-24T13:57:05.569874600
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace3")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.create_app_component(name="hello_world",platform = "$COMPONENT_LOCATION/../platform/export/platform/platform.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world")
comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

domain = platform.get_domain(name="standalone_ps7_cortexa9_0")

status = domain.regenerate()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa")

status = platform.build()

comp.build()

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform_2",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

platform = client.get_component(name="platform_2")
status = platform.build()

comp = client.create_app_component(name="hello_world_2",platform = "$COMPONENT_LOCATION/../platform_2/export/platform_2/platform_2.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world_2")
comp.build()

comp.build()

comp.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa")

status = platform.build()

comp.build()

comp = client.create_app_component(name="hello_world_4",platform = "$COMPONENT_LOCATION/../platform_2/export/platform_2/platform_2.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world_4")
comp.build()

comp.build()

comp.build()

comp = client.create_app_component(name="can_uart_i2c_system",platform = "$COMPONENT_LOCATION/../platform_2/export/platform_2/platform_2.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="can_uart_i2c_system")
comp.build()

comp.build()

