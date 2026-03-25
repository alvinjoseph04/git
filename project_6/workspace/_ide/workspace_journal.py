# 2026-03-19T10:56:33.502161900
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace")

platform = client.get_component(name="platform")
status = platform.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_1_wrapper.xsa")

status = platform.build()

comp = client.get_component(name="iic_ila")
comp.build()

