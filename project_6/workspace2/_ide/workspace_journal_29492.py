# 2026-03-24T12:10:11.244322900
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform4",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

comp = client.create_app_component(name="app_component_uart_test",platform = "$COMPONENT_LOCATION/../platform4/export/platform4/platform4.xpfm",domain = "standalone_ps7_cortexa9_0")

client.delete_component(name="app_component_uart_test")

client.delete_component(name="componentName")

comp = client.create_app_component(name="hello_world",platform = "$COMPONENT_LOCATION/../platform4/export/platform4/platform4.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world")
comp.build()

client.delete_component(name="hello_world")

client.delete_component(name="componentName")

comp = client.create_app_component(name="hello_world_4",platform = "$COMPONENT_LOCATION/../platform4/export/platform4/platform4.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world_4")
comp.build()

client.delete_component(name="hello_world_4")

client.delete_component(name="componentName")

client.delete_component(name="platform4")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform4",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

comp = client.create_app_component(name="hello_world4",platform = "$COMPONENT_LOCATION/../platform4/export/platform4/platform4.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world4")
comp.build()

comp.build()

client.delete_component(name="platform4")

client.delete_component(name="hello_world4")

client.delete_component(name="componentName")

client.delete_component(name="hello_world3")

client.delete_component(name="componentName")

client.delete_component(name="platform3")

client.delete_component(name="componentName")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform4",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

platform = client.get_component(name="platform4")
status = platform.build()

comp = client.create_app_component(name="hello_world4",platform = "$COMPONENT_LOCATION/../platform4/export/platform4/platform4.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp.build()

vitis.dispose()

