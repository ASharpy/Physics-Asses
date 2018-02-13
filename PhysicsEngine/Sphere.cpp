#include "Sphere.h"

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(vec2(0, 0), m_radius,12,m_colour);
}
