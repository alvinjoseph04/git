# 2026-03-24T09:58:43.208962200
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

comp = client.get_component(name="app_can1")
comp.build()

comp = client.create_app_component(name="app_canlcd",platform = "$COMPONENT_LOCATION/../platform1/export/platform1/platform1.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="app_canlcd")
comp.build()

comp.build()

client.delete_component(name="app_canlcd")

client.delete_component(name="componentName")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform2",hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

vitis.dispose()

