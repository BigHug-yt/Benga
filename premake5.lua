workspace "Benga"
	architecture "x86_64"
	startproject "Sandbox"

	configurations {

		"Debug",
		"Release",
		"Dist"
	}

	flags {

		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Benga/vendor/GLFW/include"
IncludeDir["Glad"] = "Benga/vendor/Glad/include"
IncludeDir["ImGui"] = "Benga/vendor/imgui"
IncludeDir["glm"] = "Benga/vendor/glm"
IncludeDir["stb_image"] = "Benga/vendor/stb_image"

group "Dependencies"
	include "Benga/vendor/GLFW"
	include "Benga/vendor/Glad"
	include "Benga/vendor/imgui"
	
group ""

project "Benga"
	location "Benga"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "bgpch.h"
	pchsource "Benga/src/bgpch.cpp"

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
		"%{prj.name}/vendor/glm/glm/**.hpp"
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
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

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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