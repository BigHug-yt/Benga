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

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BG_CORE_ASSERT(status, "Failed to initialize Gladç");

		BG_CORE_INFO("OpenGL Info:");
		BG_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		BG_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		BG_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

#ifdef BG_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		BG_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 3), "Benga requires at least OpenGL version 4.3!");
#endif
	}

	void OpenGLContext::SwapBuffers() {

		glfwSwapBuffers(m_WindowHandle);
	}

}