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

void RigidBody::resolveCollision(RigidBody * obj)
{
	vec2 normal = obj->getPosition() - m_position;
	vec2 relativeVelocity = obj->getVelocity() - m_velocity;

	float elacticity = 1;
	float j = dot(-(1 + elacticity) * (relativeVelocity), normal) / dot(normal, normal * ((1 / m_mass) + (1 / obj->getMass())));
	vec2 force = normal * j;

	ApplyForceToObject(obj, force);

}

void RigidBody::ApplyForceToObject(RigidBody * object, vec2 force)
{
	object->applyForce(force);
	applyForce(-force);
}
