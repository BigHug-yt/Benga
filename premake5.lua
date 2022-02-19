
workspace "Benga"
	architecture "x64"
	startproject "Sandbox"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Benga/vendor/GLFW/include"
IncludeDir["Glad"] = "Benga/vendor/Glad/include"
IncludeDir["ImGui"] = "Benga/vendor/ImGui"
IncludeDir["glm"] = "Benga/vendor/glm"

include "Benga/vendor/GLFW"
include "Benga/vendor/Glad"
include "Benga/vendor/ImGui"

project "Benga"
	location "Benga"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	pchheader "bgpch.h"
	pchsource "Benga/src/bgpch.cpp"

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines {

		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {

		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {

		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {

			"BG_PLATFORM_WINDOWS",
			"BG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BG_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {

		"Benga/vendor/spdlog/include",
		"Benga/src",
		"Benga/vendor",
		"%{IncludeDir.glm}"
	}

	links {

		"Benga"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			
			"BG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "BG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "BG_DIST"
		runtime "Release"
		optimize "on"