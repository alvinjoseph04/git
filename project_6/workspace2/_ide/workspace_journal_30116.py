# 2026-03-19T11:28:52.716750500
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

platform = client.get_component(name="platform")
status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_3_wrapper.xsa")

status = platform.build()

comp = client.get_component(name="appl_lcd")
comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_3_wrapper.xsa")

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_3_wrapper.xsa")

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_3_wrapper.xsa")

status = platform.build()

comp.build()

vitis.dispose()

