#include <Benga.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public Benga::Layer {

public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f) {

		m_VertexArray.reset(Benga::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
		};


		Benga::Ref<Benga::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Benga::VertexBuffer::Create(vertices, sizeof(vertices)));
		Benga::BufferLayout layout = {
			{ Benga::ShaderDataType::Float3, "a_Position" },
			{ Benga::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);


		uint32_t indices[3] = { 0, 1, 2 };
		Benga::Ref<Benga::IndexBuffer> indexBuffer;
		indexBuffer.reset(Benga::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Benga::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f
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

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main() {
				
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform  * vec4(a_Position, 1.0);
			}

		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in  vec3 v_Position;
			in vec4 v_Color;

			void main() {
				
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}

		)";

		m_Shader.reset(Benga::Shader::Create(vertexSrc, fragmentSrc));

		std::string YelvertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main() {
				
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform  * vec4(a_Position, 1.0);
			}

		)";

		std::string flatColorShaderfragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in  vec3 v_Position;

			uniform vec3 u_Color;

			void main() {
				
				color = vec4(u_Color, 1.0);
			}

		)";

		m_FlatColorShader.reset(Benga::Shader::Create(YelvertexSrc, flatColorShaderfragmentSrc));
	}

	void OnUpdate(Benga::Timestep ts) override {

		if (Benga::Input::IsKeyPressed(BG_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;

		else if (Benga::Input::IsKeyPressed(BG_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if (Benga::Input::IsKeyPressed(BG_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		else if (Benga::Input::IsKeyPressed(BG_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		if (Benga::Input::IsKeyPressed(BG_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed * ts;
		if (Benga::Input::IsKeyPressed(BG_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed * ts;


		Benga::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Benga::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Benga::Renderer::BeginScene(m_Camera);

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Benga::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Benga::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int x = 0; x < 20; x++) {
			for (int y = 0; y < 20; y++) {

				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Benga::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		Benga::Renderer::Submit(m_Shader, m_VertexArray);

		Benga::Renderer::EndScene();
	}

	void OnEvent(Benga::Event& event) override {

	}

private:
	Benga::Ref<Benga::Shader> m_Shader;
	Benga::Ref<Benga::VertexArray> m_VertexArray;

	Benga::Ref<Benga::Shader> m_FlatColorShader;
	Benga::Ref<Benga::VertexArray> m_SquareVA;

	Benga::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.0f, 0.0f, 1.0f };
};

class Sandbox : public Benga::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Benga::Application* Benga::CreateApplication() {

	return new Sandbox();
}