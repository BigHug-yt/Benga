workspace "Benga"
	architecture "x64"

	configurations {

		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Benga"
	location "Benga"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines {

			"BG_PLATFORM_WINDOWS",
			"BG_BUILD_DLL"
		}

		postbuildcommands {

			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "BG_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "BG_DIST"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {

		"Benga/vendor/spdlog/include",
		"Benga/src"
	}

	links {

		"Benga"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines {

			"BG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "BG_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "BG_DIST"
		optimize "on"