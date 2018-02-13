#include "RigidBody.h"





RigidBody::RigidBody(ShapeType shapeID, vec2 position, vec2 velocity, float rotation, float mass)
{
	shapeID = m_shapeID;
	position = m_position;
	velocity = m_velocity;
	rotation = m_Rotation;
	mass = m_mass;
}

RigidBody::~RigidBody()
{
}

void RigidBody::ApplyForceToObject(RigidBody * object, vec2 force)
{
	object->applyForce(force);
	applyForce(-force);
}
