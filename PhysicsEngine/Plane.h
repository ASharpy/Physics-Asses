#pragma once
#include "Object.h"
#include <glm/ext.hpp>
class Plane : public Object
{
	
public:
	vec2 getNormal(vec2 Normal) { return  glm::normalize(Normal); }
	float distance;
	Plane();
	~Plane();
};

