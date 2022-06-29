#pragma once

#include "Benga.h"

class ExampleLayer : public Benga::Layer {

public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Benga::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Benga::Event& e) override;

private:
	Benga::ShaderLibrary m_ShaderLibrary;
	Benga::Ref<Benga::Shader> m_Shader;
	Benga::Ref<Benga::VertexArray> m_VertexArray;

	Benga::Ref<Benga::Shader> m_FlatColorShader;
	Benga::Ref<Benga::VertexArray> m_SquareVA;

	Benga::Ref<Benga::Texture2D> m_Texture, m_PolandTexture;

	Benga::OrthoGraphicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.0f, 0.0f, 1.0f };
};