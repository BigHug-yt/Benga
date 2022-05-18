#include "bgpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Benga {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}