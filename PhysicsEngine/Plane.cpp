#include "Plane.h"





Plane::Plane() : Object(ShapeType::PLANE)
{
	m_distanceToOrigin = 0;
	m_normal = vec2(0, 1);
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
