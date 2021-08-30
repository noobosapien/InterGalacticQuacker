workspace "IGQ"
    startproject "IGQ"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

project "IGQ"
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