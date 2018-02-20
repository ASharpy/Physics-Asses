#include "Sphere.h"

bool Sphere::checkCollision(Object * pOther)
{
	if (pOther->m_shapeID == SPHERE)
	{
		
	}
	return false;
}

void Sphere::makeGizmo()
{
	aie::Gizmos::add2DCircle(m_position, m_radius,50,m_colour);
}
