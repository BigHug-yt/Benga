include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Benga"
	architecture "x86_64"
	startproject "Benga-Editor"

	configurations {

		"Debug",
		"Release",
		"Dist"
	}

	solution_items {

		".editorconfig"
	}

	flags {

		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Benga/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Benga/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Benga/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Benga/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Benga/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Benga/vendor/entt/include"

group "Dependencies"
	include "vendor/premake"
	include "Benga/vendor/GLFW"
	include "Benga/vendor/Glad"
	include "Benga/vendor/imgui"
group ""

include "Benga"
include "Sandbox"
include "Benga-Editor"