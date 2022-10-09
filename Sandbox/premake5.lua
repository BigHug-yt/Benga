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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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
		kind "WindowedApp"
		entrypoint "mainCRTStartup"