# 2026-03-18T09:45:28.361018500
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace")

platform = client.get_component(name="platform")
status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_1_wrapper.xsa")

status = platform.build()

status = platform.build()

comp = client.get_component(name="iic_ila")
comp.build()

vitis.dispose()

vitis.dispose()

