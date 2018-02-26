#pragma once
#include "RigidBody.h"

class Sphere : public RigidBody
{
public:
	Sphere(vec2 position, vec2 velocity, float mass, float radius , vec4 colour) : RigidBody(SPHERE , position , velocity,0, mass)
	{
		m_colour = colour;
		m_radius = radius;
	};

	float getRadius() { return m_radius; }


protected:
	

	

	vec4 getColour() { return m_colour; }
	~Sphere();
	float m_radius;
	vec4 m_colour;


	bool checkCollision(Object* pOther);
	virtual void makeGizmo();
};

