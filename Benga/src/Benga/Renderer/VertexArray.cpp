#include "bgpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Benga {

	VertexArray* VertexArray::Create() {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL:	return new OpenGLVertexArray();
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

}