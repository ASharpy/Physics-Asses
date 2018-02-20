#pragma once
#include "Object.h"
#include <glm/ext.hpp>
class Plane : public Object
{
	
public:
	vec2 getNormal(vec2 Normal) { return  glm::normalize(Normal); }
	float getDistance() { return m_distanceToOrigin; }
	
	Plane();

	Plane(vec2 normal, float distance) 
	{
		m_normal = normal;
		m_distanceToOrigin = distance;
	};
	virtual void fixedUpdate(vec2 gravity, float timestep);
	virtual void makeGizmo();
	virtual void resetPosition();
	~Plane();

protected:
	vec2 m_normal;
	float m_distanceToOrigin;
};

