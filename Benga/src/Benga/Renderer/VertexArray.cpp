#include "bgpch.h"
#include "Benga/Renderer/VertexArray.h"

#include "Benga/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Benga {

	Ref<VertexArray> VertexArray::Create() {
		
		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLVertexArray>();
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

}