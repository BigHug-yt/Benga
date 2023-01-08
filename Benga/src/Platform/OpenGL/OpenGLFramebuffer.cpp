#include "bgpch.h"
#include "OpenGLFramebuffer.h"

#include <glad/glad.h>

namespace Benga {

	static const uint32_t s_MaxFramebufferSize = 8192;

	namespace Utils {

		static GLenum TextureTarget(bool multisampled) {

			return multisampled ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
		}

		static void CreateTextures(bool multisampled, uint32_t* outID, uint32_t count) {

			glGenTextures(count, outID);
		}

		static void BindTexture(bool multisampled, uint32_t id) {

			glBindTexture(TextureTarget(multisampled), id);
		}


		static void AttachColorTexture(uint32_t id, int samples, GLenum internalFormat, GLenum format, uint32_t width, uint32_t height, int index) {

			bool multisampled = samples > 1;
			if (multisampled) {

				glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, internalFormat, width, height, GL_FALSE);
			}
			else {
				glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, nullptr);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			}

			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + index, TextureTarget(multisampled), id, 0);
		}

		static void AttachDepthTexture(uint32_t id, int samples, GLenum format, GLenum attachmentType, uint32_t width, uint32_t height) {

			bool multisampled = samples > 1;
			if (multisampled) {

				glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, samples, format, width, height, GL_FALSE);
			}
			else {
				glTexStorage2D(GL_TEXTURE_2D, 1, format, width, height);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			}

			glFramebufferTexture2D(GL_FRAMEBUFFER, attachmentType, TextureTarget(multisampled), id, 0);
		}

		static bool IsDepthFormat(FramebufferTextureFormat format) {

			switch (format) {

			case FramebufferTextureFormat::DEPTH24STENCIL8: return true;

			}

			return false;
		}

		static GLenum BengaFBTextureFormatToGL(FramebufferTextureFormat format) {

			switch (format) {
				case FramebufferTextureFormat::RGBA8:		return GL_RGBA8;
				case FramebufferTextureFormat::RED_INTEGER: return GL_RED_INTEGER;
			}

			BG_CORE_ASSERT(false);
			return 0;
		}
	}

	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpec& specs)
		: m_Spec(specs) {

		for (auto format : m_Spec.Attachments.Attachments) {

			if (!Utils::IsDepthFormat(format.TextureFormat))
				m_ColorAttachmentSpecs.emplace_back(format);
			else
				m_DepthAttachmentSpec = format;
		}

		Invalidate();
	}

	OpenGLFramebuffer::~OpenGLFramebuffer() {

		glDeleteFramebuffers(1, &m_RendererID);
		glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
		glDeleteTextures(1, &m_DepthAttachment);
	}

	void OpenGLFramebuffer::Invalidate() {

		if (m_RendererID) {

			glDeleteFramebuffers(1, &m_RendererID);
			glDeleteTextures(m_ColorAttachments.size(), m_ColorAttachments.data());
			glDeleteTextures(1, &m_DepthAttachment);

			m_ColorAttachments.clear();
			m_DepthAttachment = 0;
		}

		glGenFramebuffers(1, &m_RendererID);
		glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);

		bool multisample = m_Spec.Samples > 1;

		// Attachments
		if (m_ColorAttachmentSpecs.size()) {

			m_ColorAttachments.resize(m_ColorAttachmentSpecs.size());
			Utils::CreateTextures(multisample, m_ColorAttachments.data(), m_ColorAttachments.size());

			for (size_t i = 0; i < m_ColorAttachments.size(); i++) {

				Utils::BindTexture(multisample, m_ColorAttachments[i]);
				switch (m_ColorAttachmentSpecs[i].TextureFormat) {

					case FramebufferTextureFormat::RGBA8:
						Utils::AttachColorTexture(m_ColorAttachments[i], m_Spec.Samples, GL_RGBA8, GL_RGBA, m_Spec.Width, m_Spec.Height, i);
						break;
					case FramebufferTextureFormat::RED_INTEGER:
						Utils::AttachColorTexture(m_ColorAttachments[i], m_Spec.Samples, GL_R32I, GL_RED_INTEGER, m_Spec.Width, m_Spec.Height, i);
						break;
				}
			}
		}

		if (m_DepthAttachmentSpec.TextureFormat != FramebufferTextureFormat::None) {

			Utils::CreateTextures(multisample, &m_DepthAttachment, 1);
			Utils::BindTexture(multisample, m_DepthAttachment);
			switch (m_DepthAttachmentSpec.TextureFormat) {

			case FramebufferTextureFormat::DEPTH24STENCIL8:
				Utils::AttachDepthTexture(m_DepthAttachment, m_Spec.Samples, GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT, m_Spec.Width, m_Spec.Height);
				break;
			}
		}

		if (m_ColorAttachments.size() > 1) {

			BG_CORE_ASSERT(m_ColorAttachments.size() <= 4);
			GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
			glDrawBuffers(m_ColorAttachments.size(), buffers);
		}
		else if (m_ColorAttachments.empty()) {

			// Only depth-pass
			glDrawBuffer(GL_NONE);
		}

		/*
		glGenTextures(1, &m_ColorAttachment);
		glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Spec.Width, m_Spec.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);

		glGenTextures(1, &m_DepthAttachment);
		glBindTexture(GL_TEXTURE_2D, m_DepthAttachment);
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH24_STENCIL8, m_Spec.Width, m_Spec.Height);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_DepthAttachment, 0);

		*/
		BG_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is incomplete!");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void OpenGLFramebuffer::Bind() {

		glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID);
		glViewport(0, 0, m_Spec.Width, m_Spec.Height);
	}

	void OpenGLFramebuffer::UnBind() {

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void OpenGLFramebuffer::Resize(uint32_t width, uint32_t height) {

		if (width == 0 || height == 0 || width > s_MaxFramebufferSize || height > s_MaxFramebufferSize) {

			BG_CORE_WARN("Attempted to resize framebuffer to {0}, {1}", width, height);
			return;
		}
		
		m_Spec.Width = width;
		m_Spec.Height = height;

		Invalidate();
	}

	int OpenGLFramebuffer::ReadPixel(uint32_t attachmentIndex, int x, int y) {

		BG_CORE_ASSERT(attachmentIndex < m_ColorAttachments.size());

		glReadBuffer(GL_COLOR_ATTACHMENT0 + attachmentIndex);
		int pixelData;
		glReadPixels(x, y, 1, 1, GL_RED_INTEGER, GL_INT, &pixelData);
		return pixelData;
	}

	void OpenGLFramebuffer::ClearAttachment(uint32_t attachmentIndex, int value) {

		glDrawBuffer(GL_NONE);

		// Set drawBuffers to the attachmentBuffer
		GLenum buffers[1] = { GL_COLOR_ATTACHMENT0 + attachmentIndex };
		glDrawBuffers(1, buffers);

		// Setting clearColor and Clearing
		glClearColor(*(float*)&value, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Reset drawBuffers
		if (m_ColorAttachments.size() > 1) {

			BG_CORE_ASSERT(m_ColorAttachments.size() <= 4);
			GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
			glDrawBuffers(m_ColorAttachments.size(), buffers);
		}
		else if (m_ColorAttachments.empty()) {

			// Only depth-pass
			glDrawBuffer(GL_NONE);
		}
	}
}
