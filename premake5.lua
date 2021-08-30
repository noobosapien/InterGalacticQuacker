workspace "IGQ"
    startproject "IGQ editor"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

project "IGQ Engine"
    location "IGQ"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    flags
    {
        "FatalWarnings"
    }