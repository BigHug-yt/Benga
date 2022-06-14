#include "bgpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Benga {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope< OpenGLRendererAPI>();

}