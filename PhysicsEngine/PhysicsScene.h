#pragma once
#include <glm/vec2.hpp>
#include <vector>
#include "Sphere.h"

using namespace glm;
class PhysicsScene
{
public:

	PhysicsScene();

	~PhysicsScene();

	void addSphere(Sphere * sphere);
	void removeSphere(Sphere * sphere);
	void update(float DT);
	void updateGizmos();
	void setGravity(const vec2 gravity) { m_gravity = gravity; }
	vec2 getGravity() const {return m_gravity;}
	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() const { return m_timeStep; }

protected:

		vec2 m_gravity;
		float m_timeStep;
		std::vector<Sphere*> m_sphere;
};

