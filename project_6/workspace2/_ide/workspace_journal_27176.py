# 2026-03-19T11:21:15.992324500
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace2")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="appl_lcd")
comp.build()

vitis.dispose()

