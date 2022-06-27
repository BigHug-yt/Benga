#include "bgpch.h"
#include "Benga/Renderer/Buffer.h"

#include "Benga/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Benga {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size) {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None:		BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL:		return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:		BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}
}