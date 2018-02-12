#pragma once
#include "Object.h"
class RigidBody : public Object
{
protected:
float m_mass;
vec2 m_position;
vec2 m_velocity;
vec2 m_acceleration;
float m_Rotation;
public:
	RigidBody(ShapeType shapeID, vec2 position,vec2 velocity, float rotation, float mass);

	~RigidBody();
	virtual void fixedUpdate(vec2 gravity, float timeStep);
	virtual void debug();
	void applyForce(vec2 force);
	void ApplyForceToObject(RigidBody* object, vec2 force);
	virtual bool checkCollision(Object* pOther) = 0;

	vec2 getPosition() { return m_position; }
	vec2 getVelocity() { return m_velocity; }
	float getMass() { return m_mass; }
	float getRotation() { return m_Rotation; }
	virtual void applyForce(vec2 force) {};
};

