#include "bgpch.h"
#include "Framebuffer.h"

#include "Benga/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Benga {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecs& specs) {

		switch (Renderer::GetAPI()) {

			case RendererAPI::API::None:	BG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLFramebuffer>(specs);
		}

		BG_CORE_ASSERT(false, "unknown RendererAPI!");
		return nullptr;
	}
}