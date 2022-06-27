#include "bgpch.h"
#include "Benga/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Benga {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create() {

		switch (s_API) {

			case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL:	return CreateScope<OpenGLRendererAPI>();
		}

		BG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}