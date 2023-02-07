#pragma once

#include <filesystem>

#include "Benga/Renderer/Texture.h"

namespace Benga {

	class ContentBrowserPanel {

	public:
		ContentBrowserPanel();

		void OnImGuiRender();
	private:
		std::filesystem::path m_CurrentDirectory;

		Ref<Texture2D> m_DirectoryIcon;
		Ref<Texture2D> m_FileIcon;
	};
}
