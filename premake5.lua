include "./vendor/premake/premake_customization/solution_items.lua"
include "dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Benga/vendor/Box2D"
	include "Benga/vendor/GLFW"
	include "Benga/vendor/Glad"
	include "Benga/vendor/imgui"
	include "Benga/vendor/Crayon"
group ""

group "Core"
	include "Benga"
	include "Benga-ScriptCore"
group ""

group "Tools"
	include "Benga-Editor"
group ""

group "Misc"
	include "Sandbox"
group ""