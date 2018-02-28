#pragma once
#include "Object.h"
#include <glm/ext.hpp>
#include "RigidBody.h"
class Plane : public Object
{
	
public:
	vec2 getNormal() { return  glm::normalize(m_normal); }
	float getDistance() { return m_distanceToOrigin; }
	
	Plane();

	Plane(vec2 normal, float distance) : Object(ShapeType::PLANE)
	{
		m_normal = normal;
		m_distanceToOrigin = distance;
	};

	void resolveCollision(RigidBody* obj);

	virtual void fixedUpdate(vec2 gravity, float timestep) {};
	virtual void makeGizmo();
	virtual void resetPosition() {};
	~Plane();

protected:
	vec2 m_normal;
	float m_distanceToOrigin;
};

