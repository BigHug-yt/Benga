#pragma once

#include "Benga/Core/Base.h"
#include "Benga/Core/Log.h"
#include "Benga/Scene/Scene.h"
#include "Benga/Scene/Entity.h"

namespace Benga {

	class SceneHierarchyPanel {

	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}
