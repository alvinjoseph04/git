# 2026-03-19T10:28:54.954239300
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace")

platform = client.get_component(name="platform")
status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../../design_3_wrapper.xsa")

status = platform.build()

comp = client.get_component(name="iic_ila")
comp.build()

comp.build()

comp.build()

comp.build()

comp.build()

vitis.dispose()

