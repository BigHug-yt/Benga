project "Benga-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"src/**.h",
		"src/**.cpp"
	}

	includedirs {

		"%{wks.location}/Benga/vendor/spdlog/include",
		"%{wks.location}/Benga/src",
		"%{wks.location}/Benga/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}",
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