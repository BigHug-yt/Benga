#pragma once

#include <Benga.h>

class Sandbox2D : public Benga::Layer {

public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Benga::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Benga::Event& e) override;
private:
	Benga::OrthoGraphicCameraController m_CameraController;

	// Temp
	Benga::Ref<Benga::VertexArray> m_SquareVA;
	Benga::Ref<Benga::Shader> m_FlatColorShader;

	Benga::Ref<Benga::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor;
};