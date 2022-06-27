#include "bgpch.h"
#include "Benga/Renderer/Texture.h"

#include "Benga/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Benga {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height) {

		switch (Renderer::GetAPI()) {

		case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(width, height);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(path);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

}