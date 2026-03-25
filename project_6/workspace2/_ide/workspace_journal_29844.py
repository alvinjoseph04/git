# 2026-03-24T10:24:24.816470500
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

platform = client.get_component(name="platform2")
status = platform.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa")

status = platform.build()

client.delete_component(name="platform2")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform2",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

status = platform.build()

comp = client.create_app_component(name="app_canlcd",platform = "$COMPONENT_LOCATION/../platform2/export/platform2/platform2.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="app_canlcd")
comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

comp = client.create_app_component(name="app_canlcduart",platform = "$COMPONENT_LOCATION/../platform2/export/platform2/platform2.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="app_canlcduart")
comp.build()

comp.build()

comp.build()

comp.build()

comp = client.create_app_component(name="hello_world1",platform = "$COMPONENT_LOCATION/../platform2/export/platform2/platform2.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world1")
comp.build()

client.delete_component(name="hello_world1")

client.delete_component(name="componentName")

comp = client.create_app_component(name="hello_world2",platform = "$COMPONENT_LOCATION/../platform2/export/platform2/platform2.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform3",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

client.delete_component(name="hello_world2")

client.delete_component(name="componentName")

platform = client.get_component(name="platform3")
status = platform.build()

comp = client.create_app_component(name="hello_world3",platform = "$COMPONENT_LOCATION/../platform3/export/platform3/platform3.xpfm",domain = "standalone_ps7_cortexa9_0",template = "hello_world")

comp = client.get_component(name="hello_world3")
comp.build()

vitis.dispose()

