# 2026-03-23T17:13:31.319139100
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

comp = client.get_component(name="appl_lcd")
comp.build()

comp.build()

comp.build()

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform1",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

platform = client.get_component(name="platform1")
status = platform.build()

comp = client.create_app_component(name="app_can",platform = "$COMPONENT_LOCATION/../platform1/export/platform1/platform1.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="app_can")
comp.build()

comp.build()

comp = client.create_app_component(name="app_can1",platform = "$COMPONENT_LOCATION/../platform1/export/platform1/platform1.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="app_can1")
comp.build()

vitis.dispose()

