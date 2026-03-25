# 2026-03-19T10:35:52.706219300
import vitis

client = vitis.create_client()
client.set_workspace(path="workspace")

comp = client.get_component(name="iic_ila")
comp.build()

status = comp.clean()

comp.build()

comp.build()

status = client.add_platform_repos(platform=["c:\Users\291914\project_6\workspace\platform"])

vitis.dispose()

