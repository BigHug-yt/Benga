#include <Benga.h>
#include <Benga/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Benga {

	class BengaEditor : public Application {

	public:
		BengaEditor(const ApplicationSpec& spec)
			: Application(spec) {

			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~BengaEditor() {

		}
	};

	Benga::Application* CreateApplication(ApplicationCommandLineArgs args) {

		ApplicationSpec spec;
		spec.Name = "Benga editor";
		spec.WorkingDirectory = "../Benga-Editor";
		spec.CommandLineArgs = args;

		return new BengaEditor(spec);
	}
}
