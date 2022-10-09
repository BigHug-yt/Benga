#pragma once

#include "Benga/Core/Base.h"

namespace Benga {

	struct FramebufferSpecs {

		uint32_t Width = 0, Height = 0;
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer {

	public:
		virtual ~Framebuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual void Resize(uint32_t width, uint32_t height) = 0;

		virtual uint32_t GetColorAttachmentRendererID() const = 0;

		virtual const FramebufferSpecs& GetSpecification() const = 0;

		static Ref<Framebuffer> Create(const FramebufferSpecs& specs);
	};
}