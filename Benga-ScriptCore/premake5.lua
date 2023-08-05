project "Benga-ScriptCore"
	kind "SharedLib"
	language "C#"
	dotnetframework "4.7.2"
	staticruntime "off"

	targetdir ("%{wks.location}/Benga-Editor/Resources/Scripts")
	objdir ("%{wks.location}/Benga-Editor/Resources/Scripts/Intermediates")


	files {

		"%{prj.name}/Source/**.cs",
		"%{prj.name}/Properties/**.cs",
	}

	filter "configurations:Debug"
		optimize "Off"
		symbols "Default"

	filter "configurations:Release"
		optimize "On"
		symbols "Default"

	filter "configurations:Dist"
		optimize "On"
		symbols "Off"
