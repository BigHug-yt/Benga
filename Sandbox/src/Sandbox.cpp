#include <Benga.h>

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


		std::shared_ptr<Benga::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Benga::VertexBuffer::Create(vertices, sizeof(vertices)));
		Benga::BufferLayout layout = {
			{ Benga::ShaderDataType::Float3, "a_Position" },
			{ Benga::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);


		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Benga::IndexBuffer> indexBuffer;
		indexBuffer.reset(Benga::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Benga::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			0.75f, -0.75f, 0.0f,
			0.75f, 0.75f, 0.0f,
			-0.75f, 0.75f, 0.0f
		};

		std::shared_ptr<Benga::VertexBuffer> squareVB;
		squareVB.reset(Benga::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Benga::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Benga::IndexBuffer> squareIB;
		squareIB.reset(Benga::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main() {
				
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

		m_Shader.reset(new Benga::Shader(vertexSrc, fragmentSrc));

		std::string YelvertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main() {
				
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}

		)";

		std::string YelfragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in  vec3 v_Position;

			void main() {
				
				color = vec4(1.0, 1.0, 0.0, 1.0);
			}

		)";

		m_YelShader.reset(new Benga::Shader(YelvertexSrc, YelfragmentSrc));
	}

	void OnUpdate() override {

		if (Benga::Input::IsKeyPressed(BG_KEY_LEFT))
			m_CameraPosition.x += m_CameraMoveSpeed;

		else if (Benga::Input::IsKeyPressed(BG_KEY_RIGHT))
			m_CameraPosition.x -= m_CameraMoveSpeed;

		if (Benga::Input::IsKeyPressed(BG_KEY_DOWN))
			m_CameraPosition.y += m_CameraMoveSpeed;

		else if (Benga::Input::IsKeyPressed(BG_KEY_UP))
			m_CameraPosition.y -= m_CameraMoveSpeed;

		if (Benga::Input::IsKeyPressed(BG_KEY_A))
			m_CameraRotation += m_CameraRotationSpeed;
		if (Benga::Input::IsKeyPressed(BG_KEY_D))
			m_CameraRotation -= m_CameraRotationSpeed;


		Benga::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Benga::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Benga::Renderer::BeginScene(m_Camera);

		Benga::Renderer::Submit(m_YelShader, m_SquareVA);
		Benga::Renderer::Submit(m_Shader, m_VertexArray);

		Benga::Renderer::EndScene();
	}

	void OnEvent(Benga::Event& event) override {

	}

private:
	std::shared_ptr<Benga::Shader> m_Shader;
	std::shared_ptr<Benga::VertexArray> m_VertexArray;

	std::shared_ptr<Benga::Shader> m_YelShader;
	std::shared_ptr<Benga::VertexArray> m_SquareVA;

	Benga::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 0.1f;

	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 0.5f;

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