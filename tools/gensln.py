import subprocess
from tools.globals import IsLinux
import globals

subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2019"])

if globals.isWindows():
    subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2019"])

if globals.IsLinux():
    subprocess.call(["premake/premake5", "gmake2"])

if globals.IsMac():
    subprocess.call(["premake/premake5", "gmake2"])
    subprocess.call(["premake/premake5", "xcode4"])