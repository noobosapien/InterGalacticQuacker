import globals
import subprocess

CONFIG = "debug"

import os

if globals.IsWindows():
    VS_BUILD_PATH = os.environ["VS_BUILD_PATH"]

    subprocess.call(["cmd.exe", "/c", VS_BUILD_PATH, "{}.sln".format(globals.PROJECT_NAME), "/property:Configuration={}".format(CONFIG)])