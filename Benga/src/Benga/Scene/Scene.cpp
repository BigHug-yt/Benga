#include "bgpch.h"
#include "Scene.h"

#include "Components.h"
#include "ScriptableEntity.h"
#include "Benga/Renderer/Renderer2D.h"

#include <glm/glm.hpp>

#include "Entity.h"

// Box2D
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"

namespace Benga {

	static b2BodyType RigidBody2DTypeToBox2DBodyType(RigidBody2DComponent::BodyType bodyType) {

		switch (bodyType) {

			case RigidBody2DComponent::BodyType::Static:	return b2_staticBody;
			case RigidBody2DComponent::BodyType::Dynamic:	return b2_dynamicBody;
			case RigidBody2DComponent::BodyType::Kinematic: return b2_kinematicBody;
		}

		BG_CORE_ASSERT(false, "Unknown body type");
		return b2_staticBody;
	}

	Scene::Scene() {


	}

	Scene::~Scene() {


	}

	Entity Scene::CreateEntity(const std::string& name) {

		return CreateEntityWithUUID(UUID(), name);
	}

	Entity Scene::CreateEntityWithUUID(UUID uuid, const std::string& name) {

		Entity entity = { m_Registry.create(), this };
		auto& id = entity.AddComponent<IDComponent>(uuid);
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}

	void Scene::DestroyEntity(Entity entity) {

		m_Registry.destroy(entity);
	}

	void Scene::OnRuntimeStart() {

		m_PhysicsWorld = new b2World({ 0.0f, -9.81f });

		auto view = m_Registry.view<RigidBody2DComponent>();
		for (auto e : view) {

			Entity entity = { e, this };
			auto& transform = entity.GetComponent<TransformComponent>();
			auto& rb2D = entity.GetComponent<RigidBody2DComponent>();

			b2BodyDef bodyDef;
			bodyDef.type = RigidBody2DTypeToBox2DBodyType(rb2D.Type);
			bodyDef.position.Set(transform.Translation.x, transform.Translation.y);
			bodyDef.angle = transform.Rotation.z;

			b2Body* body = m_PhysicsWorld->CreateBody(&bodyDef);
			body->SetFixedRotation(rb2D.FixedRotation);
			rb2D.RuntimeBody = body;

			if (entity.HasComponent<BoxCollider2DComponent>()) {

				auto& bc2D = entity.GetComponent<BoxCollider2DComponent>();

				b2PolygonShape boxShape;
				boxShape.SetAsBox(bc2D.Size.x * transform.Scale.x, bc2D.Size.y * transform.Scale.y);

				b2FixtureDef fixtureDef;
				fixtureDef.shape = &boxShape;
				fixtureDef.density = bc2D.Density;
				fixtureDef.friction = bc2D.Friction;
				fixtureDef.restitution = bc2D.Restitution;
				fixtureDef.restitutionThreshold = bc2D.RestitutionTreshold;
				body->CreateFixture(&fixtureDef);
			}
		}

	}

	void Scene::OnRuntimeStop() {

		delete m_PhysicsWorld;
		m_PhysicsWorld = nullptr;
	}

	void Scene::OnUpdateRuntime(Timestep ts) {

		// Update scripts
		{
			m_Registry.view<NativeScriptComponent>().each([=](auto entity, auto& nsc) {

				// TODO: Move to Scene::OnScenePlay
				if (!nsc.Instance) {

					nsc.Instance = nsc.InstantiateScript();
					nsc.Instance->m_Entity = Entity{ entity, this };
					nsc.Instance->OnCreate();
				}

				nsc.Instance->OnUpdate(ts);
			});
		}

		// Physics
		{
			const int32_t velocityIterations = 6;
			const int32_t positionIterations = 2;
			m_PhysicsWorld->Step(ts, velocityIterations, positionIterations);

			// Retrieve transform from box2D
			auto view = m_Registry.view<RigidBody2DComponent>();
			for (auto e : view) {

				Entity entity = { e, this };
				auto& transform = entity.GetComponent<TransformComponent>();
				auto& rb2D = entity.GetComponent<RigidBody2DComponent>();

				b2Body* body = (b2Body*)rb2D.RuntimeBody;
				const auto& position = body->GetPosition();
				transform.Translation.x = position.x;
				transform.Translation.y = position.y;
				transform.Rotation.z = body->GetAngle();
			}
		}

		// Render 2D
		Camera* mainCamera = nullptr;
		glm::mat4 cameraTransform;
		{
			auto view = m_Registry.view<TransformComponent, CameraComponent>();
			for (auto entity : view) {

				auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

				if (camera.Primary) {

					mainCamera = &camera.Camera;
					cameraTransform = transform.GetTransform();
					break;
				}

			}
		}

		if (mainCamera) {

			Renderer2D::BeginScene(*mainCamera, cameraTransform);

			auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
			for (auto entity : group) {

				auto [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

				Renderer2D::DrawSprite(transform.GetTransform(), sprite, (int)entity);
			}

			Renderer2D::EndScene();
		}

	}

	void Scene::OnUpdateEditor(Timestep ts, EditorCamera& camera) {

		Renderer2D::BeginScene(camera);

		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group) {

			auto [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawSprite(transform.GetTransform(), sprite, (int)entity);
		}

		Renderer2D::EndScene();
	}

	void Scene::OnViewportResize(uint32_t width, uint32_t height) {

		m_ViewportWidth = width;
		m_ViewportHeight = height;

		auto view = m_Registry.view<CameraComponent>();
		for (auto entity : view) {

			auto& cameraComponent = view.get<CameraComponent>(entity);
			if (!cameraComponent.FixedAspectRatio)
				cameraComponent.Camera.SetViewportSize(width, height);
		}
	}

	Entity Scene::GetPrimaryCameraEntity() {

		auto view = m_Registry.view<CameraComponent>();
		for (auto entity : view) {

			const auto& camera = view.get<CameraComponent>(entity);
			if (camera.Primary)
				return Entity{ entity, this };
		}
		return {};
	}

	template<typename T>
	void Scene::OnComponentAdded(Entity entity, T& component) {
		static_assert(false);
	}

	template<>
	void Scene::OnComponentAdded<IDComponent>(Entity entity, IDComponent& component) {
	}

	template<>
	void Scene::OnComponentAdded<TransformComponent>(Entity entity, TransformComponent& component) {
	}

	template<>
	void Scene::OnComponentAdded<CameraComponent>(Entity entity, CameraComponent& component) {

		if (m_ViewportWidth > 0 && m_ViewportHeight > 0)
			component.Camera.SetViewportSize(m_ViewportWidth, m_ViewportHeight);
	}

	template<>
	void Scene::OnComponentAdded<SpriteRendererComponent>(Entity entity, SpriteRendererComponent& component) {
	}

	template<>
	void Scene::OnComponentAdded<TagComponent>(Entity entity, TagComponent& component) {
	}

	template<>
	void Scene::OnComponentAdded<NativeScriptComponent>(Entity entity, NativeScriptComponent& component) {
	}

	template<>
	void Scene::OnComponentAdded<RigidBody2DComponent>(Entity entity, RigidBody2DComponent& component) {
	}

	template<>
	void Scene::OnComponentAdded<BoxCollider2DComponent>(Entity entity, BoxCollider2DComponent& component) {
	}
}
