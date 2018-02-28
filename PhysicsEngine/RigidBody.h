#pragma once
#include "Object.h"
class RigidBody : public Object
{
protected:
float m_mass;
vec2 m_position;
vec2 m_velocity;
float m_Rotation;
vec2 m_acceleration;

public:
	RigidBody() {};

	RigidBody(ShapeType shapeID, vec2 position, vec2 velocity, float rotation, float mass);
	
	~RigidBody();
	
	void resolveCollision(RigidBody * obj);

	void fixedUpdate(vec2 gravity, float timeStep)
	{
		applyForce(gravity * m_mass * timeStep);
		m_velocity += gravity * timeStep;
		m_position += m_velocity * timeStep;
	}
	
	//virtual void debug();
	void applyForce(vec2 force) 
	{ 
		m_velocity += force / m_mass; 
		
	};
	void ApplyForceToObject(RigidBody* object, vec2 force);
	virtual bool checkCollision(Object* pOther) = 0;

	vec2 getPosition() { return m_position; }
	vec2 getVelocity() { return m_velocity; }
	float getMass() { return m_mass; }
	float getRotation() { return m_Rotation; }

	void setVelocity(vec2 vel) { m_velocity = vel; }

};

