#pragma once

#include "Benga/Core/Base.h"

namespace Benga {

	struct FramebufferSpecs {

		uint32_t Width, Height;
		uint32_t Samples = 1;

		bool SwapChainTarget = false;
	};

	class Framebuffer {

	public:
		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual uint32_t GetColorAttachmentRendererID() const = 0;

		virtual const FramebufferSpecs& GetSpecification() const = 0;

		static Ref<Framebuffer> Create(const FramebufferSpecs& specs);
	};
}