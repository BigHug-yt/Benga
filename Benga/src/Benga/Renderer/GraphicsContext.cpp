#include "bgpch.h"
#include "Benga/Renderer/GraphicsContext.h"

#include "Benga/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Benga {

	Scope<GraphicsContext> GraphicsContext::Create(void* window) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL:	return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		BG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}