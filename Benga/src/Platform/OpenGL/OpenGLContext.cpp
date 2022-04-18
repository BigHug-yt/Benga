#include "bgpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Benga {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) {
		BG_CORE_ASSERT(windowHandle, "Window hanel is null!");
	}

	void OpenGLContext::Init() {

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BG_CORE_ASSERT(status, "Failed to initialize Gladç");
	}

	void OpenGLContext::SwapBuffers() {

		glfwSwapBuffers(m_WindowHandle);
	}

}