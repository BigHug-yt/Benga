#include "bgpch.h"
#include "Entity.h"

namespace Benga {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene) {

	}
}