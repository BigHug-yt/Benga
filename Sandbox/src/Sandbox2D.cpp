#include "Sandbox2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) {

}

void Sandbox2D::OnAttach() {

	m_SquareVA = Benga::VertexArray::Create();

	float squareVertices[5 * 4] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	Benga::Ref<Benga::VertexBuffer> squareVB;
	squareVB.reset(Benga::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
	squareVB->SetLayout({
		{ Benga::ShaderDataType::Float3, "a_Position" }
		});
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
	Benga::Ref<Benga::IndexBuffer> squareIB;
	squareIB.reset(Benga::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
	m_SquareVA->SetIndexBuffer(squareIB);

	
	m_FlatColorShader = Benga::Shader::Create("assets/shaders/FlatColor.glsl");
}

void Sandbox2D::OnDetach() {

}

void Sandbox2D::OnUpdate(Benga::Timestep ts) {

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Benga::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	Benga::RenderCommand::Clear();

	Benga::Renderer::BeginScene(m_CameraController.GetCamera());

	std::dynamic_pointer_cast<Benga::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<Benga::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);

	Benga::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
	
	Benga::Renderer::EndScene();
}

void Sandbox2D::OnEvent(Benga::Event& e) {

	m_CameraController.OnEvent(e);
}