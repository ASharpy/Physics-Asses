#pragma once
#include "Object.h"
class Plane : public Object
{
public:
	vec2 getNormal(vec2 Normal) { return vec2{}; }
	float distance;
	Plane();
	~Plane();
};

