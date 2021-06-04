#pragma once

#include "Components/ColliderComponent.h" 
#include "Components/RigidBodyComponent.h" 
#include "Core.h"
#include "System.h"

namespace ScarletEngine::Achilles
{
	struct IntersectionData
	{
		float Distance;
		glm::vec3 Direction;
	};

	class AABBvsAABBColliderSystem : public System<BoxColliderComponent, RigidBodyComponent, TransformComponent>
	{
	public:
		virtual void FixedUpdate() const override;
	};

	class SphereVsSphereColliderSystem : public System<SphereColliderComponent, RigidBodyComponent, TransformComponent>
	{
	public:
		virtual void FixedUpdate() const override;
	private:
		IntersectionData GetIntersection(const SphereColliderComponent* SphereA, const SphereColliderComponent* SphereB) const;
		static void SolveIntersection(RigidBodyComponent* Rb, TransformComponent* Trans, SphereColliderComponent* Sphere, SphereColliderComponent* OtherSphere, glm::vec3 Fi, glm::vec3 NewPos);
	};

	class PlaneVsSphereColliderSystem : public System<SphereColliderComponent, PlaneColliderComponent, RigidBodyComponent, TransformComponent>
	{
	public:
		virtual void FixedUpdate() const override;
	private:
		IntersectionData GetIntersection(const PlaneColliderComponent* Plane, const SphereColliderComponent* Sphere) const;
	};
}
