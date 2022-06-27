#include "bgpch.h"
#include "Benga/Renderer/RenderCommand.h"

namespace Benga {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}