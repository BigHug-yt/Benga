#include "bgpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Benga {

	Ref<Texture2D> Texture2D::Create(const std::string& path) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:	return std::make_shared<OpenGLTexture2D>(path);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}

}