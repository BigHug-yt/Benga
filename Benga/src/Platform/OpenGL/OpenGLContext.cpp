#include "bgpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Benga {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle) {
		BG_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init() {
		
		BG_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BG_CORE_ASSERT(status, "Failed to initialize Gladç");

		BG_CORE_INFO("OpenGL Info:");
		BG_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BG_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BG_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		BG_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 3), "Benga requires at least OpenGL version 4.3")
	}

	void OpenGLContext::SwapBuffers() {
		
		BG_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
