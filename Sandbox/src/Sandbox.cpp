#include <Benga.h>
#include <Benga/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Benga::Layer {

public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f, true) {

		m_VertexArray = Benga::VertexArray::Create();

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

		m_SquareVA = Benga::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		Benga::Ref<Benga::VertexBuffer> squareVB;
		squareVB.reset(Benga::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Benga::ShaderDataType::Float3, "a_Position" },
			{ Benga::ShaderDataType::Float2, "a_TexCoord" }
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

		m_Shader = Benga::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
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

		m_FlatColorShader = Benga::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderfragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Benga::Texture2D::Create("assets/textures/checkerboard.png");
		m_PolandTexture = Benga::Texture2D::Create("assets/textures/poland.png");

		std::dynamic_pointer_cast<Benga::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Benga::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Benga::Timestep ts) override {

		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Benga::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Benga::RenderCommand::Clear();

		Benga::Renderer::BeginScene(m_CameraController.GetCamera());

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

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Benga::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_PolandTexture->Bind();
		Benga::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		// Benga::Renderer::Submit(m_Shader, m_VertexArray);

		Benga::Renderer::EndScene();
	}

	void OnEvent(Benga::Event& e) override {

		m_CameraController.OnEvent(e);
	}

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

class Sandbox : public Benga::Application {

public:
	Sandbox() {
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox() {

	}
};

Benga::Application* Benga::CreateApplication() {

	return new Sandbox();
}