# 2026-03-19T15:36:47.560357400
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

comp = client.get_component(name="appl_lcd")
status = comp.clean()

comp.build()

