#pragma once

#include "Benga/Window.h"

#include <GLFW/glfw3.h>

namespace Benga {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Window attributes
		inline void SetEventCallback(const EventCallBackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallBackFn EventCallback;
		};

		WindowData m_Data;
	};
}