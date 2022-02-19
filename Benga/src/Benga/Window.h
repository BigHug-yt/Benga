#pragma once

#include "bgpch.h"

#include "Benga/Core.h"
#include "Benga/Events/Event.h"

namespace Benga {

	struct WindowProps {

		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Benga Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	//Interface representing a desktop system based Window
	class BENGA_API Window {

	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}