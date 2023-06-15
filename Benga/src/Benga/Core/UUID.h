#pragma once

namespace Benga {

	class UUID {

	public:
		UUID();
		UUID(uint64_t uuid);
		UUID(const UUID&) = default;

		operator uint64_t() const { return m_UUID; }
	private:
		uint64_t m_UUID;
	};

}

namespace std {
	
	template<typename T> struct hash;

	template<>
	struct hash<Benga::UUID> {

		std::size_t operator()(const Benga::UUID& uuid) const {

			// UUID's should already be uniformly distributed, no need for hashing.
			return (uint64_t)uuid;
		}
	};
}
