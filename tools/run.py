import globals
import os, subprocess, sys

config = "Debug"
exepath = "{}/bin/{}/{}".format(os.getcwd(), config, globals.EDITOR_NAME)

ret = 0

if globals.IsWindows():
    ret = subprocess.call(["cmd.exe", "/c", "{}\\run.bat".format(globals.TOOLS_DIR), config, globals.EDITOR_NAME], cwd=os.getcwd())
else:
    subprocess.call(["{}{}".format(exepath, globals.PROJECT_NAME)], cwd=exepath)

sys.exit(ret)
