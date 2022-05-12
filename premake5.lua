workspace "Learner"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Learner"
	location "Learner"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"LR_PLATFORM_WINDOWS",
			"LEARNER_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}

	filter "configurations:Debug"
		defines "LR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LR_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Learner/vendor/spdlog/include",
		"Learner/src"
	}

	links
	{
		"Learner"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"LR_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LR_DIST"
		optimize "On"