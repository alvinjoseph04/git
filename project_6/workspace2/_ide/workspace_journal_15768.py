# 2026-03-23T16:44:43.690270800
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

platform = client.get_component(name="platform")
status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_5_wrapper.xsa")

status = platform.build()

status = client.add_platform_repos(platform=["c:\Users\291914\project_6\workspace2\platform\ps7_cortexa9_0"])

status = client.add_platform_repos(platform=["c:\Users\291914\project_6\workspace2\platform"])

status = client.add_platform_repos(platform=["c:\Users\291914\project_6\workspace2\platform\zynq_fsbl"])

vitis.dispose()

