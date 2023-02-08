#include <Benga.h>
#include <Benga/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Benga {

	class BengaEditor : public Application {

	public:
		BengaEditor(ApplicationCommandLineArgs args)
			: Application("Benga Editor", args) {

			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~BengaEditor() {

		}
	};

	Benga::Application* CreateApplication(ApplicationCommandLineArgs args) {

		return new BengaEditor(args);
	}
}
