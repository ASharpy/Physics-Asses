#pragma once
#include "RigidBody.h"
class Box : public RigidBody
{
public:
	float m_height;
	float m_length;


	Box(vec2 position, vec2 velocity, float mass) : RigidBody(BOX, position, velocity, 0, mass)
	{

	}
	~Box();
};

