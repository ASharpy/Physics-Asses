#pragma once
#include "Object.h"
class RigidBody : public Object
{
protected:
float m_mass;
vec2 m_position;
vec2 m_velocity;
vec2 m_acceleration;
vec2 Rotation;

	RigidBody();

	~RigidBody();
public:

	virtual void applyForce(float force) {};
};

