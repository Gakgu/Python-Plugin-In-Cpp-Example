import os
import glob

path = (os.path.dirname(os.path.realpath(__file__)))
os.chdir(path)

for plugin_name in glob.glob("./plugins/*.py"):
    __import__("plugins." + plugin_name[10:-3])
