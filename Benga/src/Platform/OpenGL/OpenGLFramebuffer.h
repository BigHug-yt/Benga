#pragma once

#include "Benga/Renderer/Framebuffer.h"

namespace Benga {

	class OpenGLFramebuffer : public Framebuffer {

	public:
		OpenGLFramebuffer(const FramebufferSpec& specs);
		virtual ~OpenGLFramebuffer();

		void Invalidate();

		virtual void Resize(uint32_t width, uint32_t height) override;

		virtual void Bind() override;
		virtual void UnBind() override;

		virtual uint32_t GetColorAttachmentRendererID(uint32_t index = 0) const override { BG_CORE_ASSERT(index < m_ColorAttachments.size()); return m_ColorAttachments[index]; };

		virtual const FramebufferSpec& GetSpecification() const override { return m_Spec; };
	private:
		uint32_t m_RendererID = 0;
		FramebufferSpec m_Spec;

		std::vector<FramebufferTextureSpec> m_ColorAttachmentSpecs;
		FramebufferTextureSpec m_DepthAttachmentSpec = FramebufferTextureFormat::None;

		std::vector<uint32_t> m_ColorAttachments;
		uint32_t m_DepthAttachment = 0;
	};
}
