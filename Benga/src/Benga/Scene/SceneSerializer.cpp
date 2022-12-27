#include "bgpch.h"
#include "SceneSerializer.h"

#include "Entity.h"
#include "Components.h"

#include <fstream>

#include <Crayon.h>

// Implementing Node::as() function for glm::vec3/4
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

	SceneSerializer::SceneSerializer(const Ref<Scene>& scene) 
		: m_Scene(scene) {


	}

	static void SerializeEntity(Crayon::Room& room, Entity entity) {

		room << Crayon::BeginSubset;
		// TODO: entity ID's
		room << Crayon::Key << "Entity" << Crayon::Value << "9785461786987623487"; // Entity

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

			room << Crayon::EndSubset; // SpriteRendererComponent
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
		// BG_CORE_TRACE("Deserializing scene '{0}'", sceneName);

		auto entities = data["Entities"];
		if (entities) {

			auto entities = data["Entities"];
			for (auto entity : entities) {

				uint64_t uuid = entity["Entity"].as<uint64_t>(); // TODO

				std::string name;
				auto tagComponent = entity["TagComponent"];
				if (tagComponent)
					name = tagComponent["Tag"].as<std::string>();

				// BG_CORE_TRACE("Deserialized entity with ID = {0}, name = {1}", uuid, name);

				Entity deserializedEntity = m_Scene->CreateEntity(name);

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
