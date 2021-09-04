workspace "IGQ"
    startproject "IGQeditor"
    --startproject "IGQ"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "bin-obj/%{cfg.buildcfg}/%{prj.name}"

--External dependencies
externals = {}
externals["maclibs"] = "external/maclibs"
externals["sdl2"] = "external/sdl2"
externals["spdlog"] = "external/spdlog"
externals["glad"] = "external/glad"

include "external/glad"

project "IGQengine"
    location "IGQengine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    
    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    sysincludedirs
    {
        "%{prj.name}/include/IGQengine",
        "%{externals.sdl2}/include",
        "%{externals.spdlog}/include",
        "%{externals.glad}/include"
    }

    flags
    {
        "FatalWarnings"
    }

    defines
    {
        "GLFW_INCLUDE_NONE"
    }

    filter {"system:windows", "configurations:*"}
        systemversion "latest"

        defines
        {
            "IGQ_PLATFORM_WINDOWS"
        }
    
    filter {"system:macosx", "configurations:*"}
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }

        defines
        {
            "IGQ_PLATFORM_MAC"
        }

    filter {"system:linux", "configurations:*"}
        defines
        {
            "IGQ_PLATFORM_LINUX"
        }

    filter "configurations:Debug"
        defines{
            "IGQ_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines{
            "IGQ_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"

project "IGQeditor"
    --location "IGQ"
    location "IGQeditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    links "IGQengine"

    targetdir(tdir)
    objdir(odir)

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    sysincludedirs
    {
        "IGQengine/include"
    }

    flags
    {
        "FatalWarnings"
    }

    filter {"system:windows", "configurations:*"}
        systemversion "latest"

        defines
        {
            "IGQ_PLATFORM_WINDOWS"
        }

        libdirs
        {
            "%{externals.sdl2}/lib"
        }

        links 
        {
            "SDL2",
            "glad"
        }
    
    filter {"system:macosx", "configurations:*"}
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }

        defines
        {
            "IGQ_PLATFORM_MAC"
        }

        abspath = path.getabsolute("%{externals.maclibs}")
        linkoptions = {"-F ".. abspath}

        links 
        {
            "SDL2.framework",
            "glad"
        }

    filter {"system:linux", "configurations:*"}
        defines
        {
            "IGQ_PLATFORM_LINUX"
        }

        links
        {
            "SDL2",
            "glad"
        }

    filter "configurations:Debug"
        defines{
            "IGQ_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines{
            "IGQ_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"