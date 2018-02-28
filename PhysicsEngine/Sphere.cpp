#include "Sphere.h"


void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius,50,m_colour);
}
