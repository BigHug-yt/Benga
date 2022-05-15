#include "bgpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Benga {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::None:		BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::None:		BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLIndexBuffer(indices, size);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}
}