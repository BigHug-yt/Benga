#include "bgpch.h"
#include "SceneSerializer.h"

#include "Entity.h"
#include "Components.h"

#include <fstream>

#include <Crayon.h>

// Implementing Node::as() function for glm::vec3/4
template <>
glm::vec2 Crayon::Node::as<glm::vec2>() const {
	// return t if conversion goes wrong
	if (!m_IsReal)
		throw std::exception();

	switch (m_Type) {
	case NodeType::Scalar: { throw std::exception(); }
	case NodeType::Tag: { throw std::exception(); }
	case NodeType::List: {
		return glm::vec2(m_Keys[0].as<float>(), m_Keys[1].as<float>());
	}
	case NodeType::Node: { throw std::exception(); }
	case NodeType::None: { throw std::exception(); }
	}
}

template <>
glm::vec3 Crayon::Node::as<glm::vec3>() const {
	// return t if conversion goes wrong
	if (!m_IsReal)
		throw std::exception();

	switch (m_Type) {
		case NodeType::Scalar: { throw std::exception(); }
		case NodeType::Tag: { throw std::exception(); }
		case NodeType::List: {
			return glm::vec3(m_Keys[0].as<float>(), m_Keys[1].as<float>(), m_Keys[2].as<float>());
		}
		case NodeType::Node: { throw std::exception(); }
		case NodeType::None: { throw std::exception(); }
	}
}
template <>
glm::vec4 Crayon::Node::as<glm::vec4>() const {
	// return t if conversion goes wrong
	if (!m_IsReal)
		throw std::exception();

	switch (m_Type) {
		case NodeType::Scalar: { throw std::exception(); }
		case NodeType::Tag: { throw std::exception(); }
		case NodeType::List: {
			return glm::vec4(m_Keys[0].as<float>(), m_Keys[1].as<float>(), m_Keys[2].as<float>(), m_Keys[3].as<float>());
		}
		case NodeType::Node: { throw std::exception(); }
		case NodeType::None: { throw std::exception(); }
	}
}

namespace Benga {

	Crayon::Room& operator<<(Crayon::Room& room, const glm::vec2& v) {

		room << Crayon::BeginList;
		room << v.x << v.y;
		room << Crayon::EndList;
		return room;
	}

	Crayon::Room& operator<<(Crayon::Room& room, const glm::vec3& v) {

		room << Crayon::BeginList;
		room << v.x << v.y << v.z;
		room << Crayon::EndList;
		return room;
	}

	Crayon::Room& operator<<(Crayon::Room& room, const glm::vec4& v) {

		room << Crayon::BeginList;
		room << v.x << v.y << v.z << v.w;
		room << Crayon::EndList;
		return room;
	}

	static std::string RigidBody2DBodyTypeToString(RigidBody2DComponent::BodyType bodyType) {

		switch (bodyType) {

			case RigidBody2DComponent::BodyType::Static:	return "Static";
			case RigidBody2DComponent::BodyType::Dynamic:	return "Dynamic";
			case RigidBody2DComponent::BodyType::Kinematic: return "Kinematic";
		}

		BG_CORE_ASSERT(false, "Unknown body type");
		return {};
	}

	static RigidBody2DComponent::BodyType RigidBody2DBodyTypeFromString(const std::string& bodyTypeString) {

		if (bodyTypeString == "Static")		return RigidBody2DComponent::BodyType::Static;
		if (bodyTypeString == "Dynamic")	return RigidBody2DComponent::BodyType::Dynamic;
		if (bodyTypeString == "Kinematic")	return RigidBody2DComponent::BodyType::Kinematic;

		BG_CORE_ASSERT(false, "Unknown body type");
		return RigidBody2DComponent::BodyType::Static;
	}

	SceneSerializer::SceneSerializer(const Ref<Scene>& scene) 
		: m_Scene(scene) {


	}

	static void SerializeEntity(Crayon::Room& room, Entity entity) {

		BG_CORE_ASSERT(entity.HasComponent<IDComponent>());

		room << Crayon::BeginSubset;

		room << Crayon::Key << "Entity" << Crayon::Value << entity.GetUUID(); // Entity

		if (entity.HasComponent<TagComponent>()) {

			room << Crayon::Key << "TagComponent"; // TagComonent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& tag = entity.GetComponent<TagComponent>().Tag;
			room << Crayon::Key << "Tag" << Crayon::Value << tag;

			room << Crayon::EndSubset; // TagComponent
		}

		if (entity.HasComponent<TransformComponent>()) {

			room << Crayon::Key << "TransformComponent"; // TransformComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& tc = entity.GetComponent<TransformComponent>();
			room << Crayon::Key << "Translation" << Crayon::Value << tc.Translation;
			room << Crayon::Key << "Rotation" << Crayon::Value << tc.Rotation;
			room << Crayon::Key << "Scale" << Crayon::Value << tc.Scale;

			room << Crayon::EndSubset; // TransformComponent
		}

		if (entity.HasComponent<CameraComponent>()) {

			room << Crayon::Key << "CameraComponent"; // CameraComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& cameraComponent = entity.GetComponent<CameraComponent>();
			auto& camera = cameraComponent.Camera;

			room << Crayon::Key << "Camera" << Crayon::Value << Crayon::BeginSubset; // Camera
			room << Crayon::Key << "ProjectionType" << Crayon::Value << (int)camera.GetProjectionType();
			room << Crayon::Key << "PerspectiveFOV" << Crayon::Value << camera.GetPerspectiveVerticalFOV();
			room << Crayon::Key << "PerspectiveNear" << Crayon::Value << camera.GetPerspectiveNearClip();
			room << Crayon::Key << "PerspectiveFar" << Crayon::Value << camera.GetPerspectiveFarClip();
			room << Crayon::Key << "OrthographicSize" << Crayon::Value << camera.GetOrthographicSize();
			room << Crayon::Key << "OrthographicNear" << Crayon::Value << camera.GetOrthographicNearClip();
			room << Crayon::Key << "OrthographicFar" << Crayon::Value << camera.GetOrthographicFarClip();
			room << Crayon::EndSubset; // Camera

			room << Crayon::Key << "Primary" << Crayon::Value << cameraComponent.Primary;
			room << Crayon::Key << "FixedAspectRatio" << Crayon::Value << cameraComponent.FixedAspectRatio;

			room << Crayon::EndSubset; // CameraComponent
		}

		if (entity.HasComponent<SpriteRendererComponent>()) {

			room << Crayon::Key << "SpriteRendererComponent"; // SpriteRendererComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& spriteRendererComponent = entity.GetComponent<SpriteRendererComponent>();
			room << Crayon::Key << "Color" << Crayon::Value << spriteRendererComponent.Color;
			if (spriteRendererComponent.Texture)
				room << Crayon::Key << "TexturePath" << Crayon::Value << spriteRendererComponent.Texture->GetPath();
			room << Crayon::Key << "TilingFactor" << Crayon::Value << spriteRendererComponent.TilingFactor;

			room << Crayon::EndSubset; // SpriteRendererComponent
		}

		if (entity.HasComponent<CircleRendererComponent>()) {

			room << Crayon::Key << "CircleRendererComponent"; // CircleRendererComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& circleRendererComponent = entity.GetComponent<CircleRendererComponent>();
			room << Crayon::Key << "Color" << Crayon::Value << circleRendererComponent.Color;
			room << Crayon::Key << "Thickness" << Crayon::Value << circleRendererComponent.Thickness;
			room << Crayon::Key << "Fade" << Crayon::Value << circleRendererComponent.Fade;

			room << Crayon::EndSubset; // CircleRendererComponent
		}

		if (entity.HasComponent<RigidBody2DComponent>()) {

			room << Crayon::Key << "RigidBody2DComponent"; // RigidBody2DComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& rb2DComponent = entity.GetComponent<RigidBody2DComponent>();
			room << Crayon::Key << "BodyType" << Crayon::Value << RigidBody2DBodyTypeToString(rb2DComponent.Type);
			room << Crayon::Key << "FixedRotation" << Crayon::Value << rb2DComponent.FixedRotation;

			room << Crayon::EndSubset; // RigidBody2DComponent
		}

		if (entity.HasComponent<BoxCollider2DComponent>()) {

			room << Crayon::Key << "BoxCollider2DComponent"; // BoxCollider2DComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& bc2DComponent = entity.GetComponent<BoxCollider2DComponent>();
			room << Crayon::Key << "Offset" << Crayon::Value << bc2DComponent.Offset;
			room << Crayon::Key << "Size" << Crayon::Value << bc2DComponent.Size;
			room << Crayon::Key << "Density" << Crayon::Value << bc2DComponent.Density;
			room << Crayon::Key << "Friction" << Crayon::Value << bc2DComponent.Friction;
			room << Crayon::Key << "Restitution" << Crayon::Value << bc2DComponent.Restitution;
			room << Crayon::Key << "RestitutionTreshold" << Crayon::Value << bc2DComponent.RestitutionTreshold;

			room << Crayon::EndSubset; // BoxCollider2DComponent
		}

		if (entity.HasComponent<CircleCollider2DComponent>()) {

			room << Crayon::Key << "CircleCollider2DComponent"; // CircleCollider2DComponent
			room << Crayon::Value << Crayon::BeginSubset;

			auto& cc2DComponent = entity.GetComponent<CircleCollider2DComponent>();
			room << Crayon::Key << "Offset" << Crayon::Value << cc2DComponent.Offset;
			room << Crayon::Key << "Radius" << Crayon::Value << cc2DComponent.Radius;
			room << Crayon::Key << "Density" << Crayon::Value << cc2DComponent.Density;
			room << Crayon::Key << "Friction" << Crayon::Value << cc2DComponent.Friction;
			room << Crayon::Key << "Restitution" << Crayon::Value << cc2DComponent.Restitution;
			room << Crayon::Key << "RestitutionTreshold" << Crayon::Value << cc2DComponent.RestitutionTreshold;

			room << Crayon::EndSubset; // CircleCollider2DComponent
		}

		room << Crayon::EndSubset; // Entity
	}

	void SceneSerializer::Serialize(const std::string& filepath) {

		Crayon::Room room;

		room << Crayon::Key << "Scene" << Crayon::Value << "Untitled";
		room << Crayon::Key << "Entities" << Crayon::Value << Crayon::BeginSubset;

		m_Scene->m_Registry.each([&](auto entityID) {

			Entity entity = { entityID, m_Scene.get() };
			if (!entity)
				return;

			SerializeEntity(room, entity);
		});
		room << Crayon::EndSubset;

		std::ofstream fout(filepath);
		fout << room.c_str();
	}

	void SceneSerializer::SerializeRuntime(const std::string& filepath) {

		// not implemented
		BG_CORE_ASSERT(false);
	}

	bool SceneSerializer::Deserialize(const std::string& filepath) {

		std::ifstream stream(filepath);
		std::stringstream strStream;
		strStream << stream.rdbuf();

		Crayon::Node data(strStream.str());

		auto scene = data["Scene"];
		if (!scene)
			return false;

		std::string sceneName = data["Scene"].as<std::string>();

		auto entities = data["Entities"];
		if (entities) {

			auto entities = data["Entities"];
			for (auto entity : entities) {

				uint64_t uuid = entity["Entity"].as<uint64_t>();

				std::string name;
				auto tagComponent = entity["TagComponent"];
				if (tagComponent)
					name = tagComponent["Tag"].as<std::string>();

				Entity deserializedEntity = m_Scene->CreateEntityWithUUID(uuid, name);

				auto transformComponent = entity["TransformComponent"];
				if (transformComponent) {
					// all new entities already have transforms
					auto& tc = deserializedEntity.GetComponent<TransformComponent>();
					tc.Translation = transformComponent["Translation"].as<glm::vec3>();
					tc.Rotation = transformComponent["Rotation"].as<glm::vec3>();
					tc.Scale = transformComponent["Scale"].as<glm::vec3>();
				}

				auto cameraComponent = entity["CameraComponent"];
				if (cameraComponent) {

					auto& cc = deserializedEntity.AddComponent<CameraComponent>();

					auto& cameraProps = cameraComponent["Camera"];
					cc.Camera.SetProjectionType((SceneCamera::ProjectionType)cameraProps["ProjectionType"].as<int>());

					cc.Camera.SetPerspectiveVerticalFOV(cameraProps["PerspectiveFOV"].as<float>());
					cc.Camera.SetPerspectiveNearClip(cameraProps["PerspectiveNear"].as<float>());
					cc.Camera.SetPerspectiveFarClip(cameraProps["PerspectiveFar"].as<float>());

					cc.Camera.SetOrthographicSize(cameraProps["OrthographicSize"].as<float>());
					cc.Camera.SetOrthographicNearClip(cameraProps["OrthographicNear"].as<float>());
					cc.Camera.SetOrthographicFarClip(cameraProps["OrthographicFar"].as<float>());

					cc.Primary = cameraComponent["Primary"].as<bool>();
					cc.FixedAspectRatio = cameraComponent["FixedAspectRatio"].as<bool>();
				}

				auto spriteRendererComponent = entity["SpriteRendererComponent"];
				if (spriteRendererComponent) {

					auto& src = deserializedEntity.AddComponent<SpriteRendererComponent>();
					src.Color = spriteRendererComponent["Color"].as<glm::vec4>();

					if (spriteRendererComponent["TexturePath"])
						src.Texture = Texture2D::Create(spriteRendererComponent["TexturePath"].as<std::string>());

					if (spriteRendererComponent["TilingFactor"])
						src.TilingFactor = spriteRendererComponent["TilingFactor"].as<float>();
				}

				auto circleRendererComponent = entity["CircleRendererComponent"];
				if (circleRendererComponent) {

					auto& crc = deserializedEntity.AddComponent<CircleRendererComponent>();
					crc.Color = circleRendererComponent["Color"].as<glm::vec4>();
					crc.Thickness = circleRendererComponent["Thickness"].as<float>();
					crc.Fade = circleRendererComponent["Fade"].as<float>();
				}

				auto rigidBody2DComponent = entity["RigidBody2DComponent"];
				if (rigidBody2DComponent) {

					auto& rb2D = deserializedEntity.AddComponent<RigidBody2DComponent>();
					rb2D.Type = RigidBody2DBodyTypeFromString(rigidBody2DComponent["BodyType"].as<std::string>());
					rb2D.FixedRotation = rigidBody2DComponent["FixedRotation"].as<bool>();
				}

				auto boxCollider2DComponent = entity["BoxCollider2DComponent"];
				if (boxCollider2DComponent) {

					auto& bc2D = deserializedEntity.AddComponent<BoxCollider2DComponent>();
					bc2D.Offset = boxCollider2DComponent["Offset"].as<glm::vec2>();
					bc2D.Size = boxCollider2DComponent["Size"].as<glm::vec2>();
					bc2D.Density = boxCollider2DComponent["Density"].as<float>();
					bc2D.Friction = boxCollider2DComponent["Friction"].as<float>();
					bc2D.Restitution = boxCollider2DComponent["Restitution"].as<float>();
					bc2D.RestitutionTreshold = boxCollider2DComponent["RestitutionTreshold"].as<float>();
				}

				auto circleCollider2DComponent = entity["CircleCollider2DComponent"];
				if (circleCollider2DComponent) {

					auto& cc2D = deserializedEntity.AddComponent<CircleCollider2DComponent>();
					cc2D.Offset = circleCollider2DComponent["Offset"].as<glm::vec2>();
					cc2D.Radius = circleCollider2DComponent["Radius"].as<float>();
					cc2D.Density = circleCollider2DComponent["Density"].as<float>();
					cc2D.Friction = circleCollider2DComponent["Friction"].as<float>();
					cc2D.Restitution = circleCollider2DComponent["Restitution"].as<float>();
					cc2D.RestitutionTreshold = circleCollider2DComponent["RestitutionTreshold"].as<float>();
				}
			}
		}

		return true;
	}

	bool SceneSerializer::DeserializeRuntime(const std::string& filepath) {

		// not implemented
		BG_CORE_ASSERT(false);
		return false;
	}
}
