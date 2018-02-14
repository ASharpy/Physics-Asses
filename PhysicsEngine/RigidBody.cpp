#include "RigidBody.h"





RigidBody::RigidBody(ShapeType shapeID, vec2 position, vec2 velocity, float rotation, float mass)
{
	m_shapeID = shapeID;
	m_position = position;
	m_mass = mass;
	m_Rotation = rotation;
	m_velocity = velocity;
}

RigidBody::~RigidBody()
{
}

void RigidBody::ApplyForceToObject(RigidBody * object, vec2 force)
{
	object->applyForce(force);
	applyForce(-force);
}
