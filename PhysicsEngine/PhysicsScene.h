#pragma once
#include <glm/ext.hpp>
#include <vector>
#include "Sphere.h"
#include "Plane.h"

using namespace glm;
class PhysicsScene
{
public:

	PhysicsScene();

	~PhysicsScene();

	void addObject(Object * object);
	//void removeObject(Object * object);
	void update(float DT);
	void updateGizmos();
	void setGravity(const vec2 gravity) { m_gravity = gravity; }
	vec2 getGravity() const {return m_gravity;}
	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() const { return m_timeStep; }
	void checkCollision();

	static bool planeToPlane(Object*, Object*);
	static bool planeToSphere(Object*, Object*);
	static bool sphereToPlane(Object*, Object*);
	static bool sphereToSphere(Object*, Object*);

protected:

		vec2 m_gravity;
		float m_timeStep;
		std::vector<Object*> objectList;
};

