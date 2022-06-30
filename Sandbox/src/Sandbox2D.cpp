#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {

}

void Sandbox2D::OnAttach() {

	BG_PROFILE_FUNCTION();

	m_CheckerboardTexture = Benga::Texture2D::Create("assets/textures/checkerboard.png");
}

void Sandbox2D::OnDetach() {

	BG_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Benga::Timestep ts) {

	BG_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	{
		BG_PROFILE_SCOPE("Renderer Prep");
		Benga::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Benga::RenderCommand::Clear();
	}

	{
		BG_PROFILE_SCOPE("Renderer Draw");
		Benga::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Benga::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Benga::Renderer2D::DrawRotatedQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, glm::radians(-45.0f), m_SquareColor);
		Benga::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, glm::radians(45.0f), m_CheckerboardTexture, 10.0f, glm::vec4(1.0f, 0.9f, 0.9f, 1.0f));
		Benga::Renderer2D::EndScene();
	}
	
}

void Sandbox2D::OnImGuiRender() {

	BG_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Benga::Event& e) {

	m_CameraController.OnEvent(e);
}