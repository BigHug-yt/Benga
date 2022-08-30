#include <Benga.h>
#include <Benga/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Benga {

	class BengaEditor : public Application {

	public:
		BengaEditor()
			: Application("Benga Editor") {

			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~BengaEditor() {

		}
	};

	Benga::Application* CreateApplication() {

		return new BengaEditor();
	}
}