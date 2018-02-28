#include "Plane.h"





Plane::Plane() : Object(ShapeType::PLANE)
{
	m_distanceToOrigin = 0;
	m_normal = vec2(0, 1);
}

void Plane::resolveCollision(RigidBody * obj)
{
	vec2 normal = m_normal;
	vec2 relativeVelocity = obj->getVelocity();

	//float elacticity = 0.8f;

	//obj->setVelocity((relativeVelocity - (1.0f + elacticity) * dot(relativeVelocity, normal) * normal));

	float elacticity = 1;
	float j =  dot(-(1.0f + elacticity) * (relativeVelocity), normal) / (1 /obj->getMass());
	vec2 force = normal * j;

	obj->applyForce(force);

	//obj->setVelocity(force);
}

void Plane::makeGizmo()
{
	float lineSegmentLength = 300;
	vec2 centerPoint = m_normal * m_distanceToOrigin;
	vec2 venterPoint = m_normal * m_distanceToOrigin;
	vec2 parallel(m_normal.y, -m_normal.x);
	vec4 colour(1, 1, 1, 1);
	vec2 start = centerPoint + (parallel * lineSegmentLength);
	vec2 end = centerPoint - (parallel * lineSegmentLength);
	aie::Gizmos::add2DLine(start, end, colour);
}

Plane::~Plane()
{
}
