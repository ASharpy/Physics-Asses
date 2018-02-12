#pragma once
#include "RigidBody.h"
class Box : public RigidBody
{
public:
	float m_height;
	float m_length;
	Box();
	~Box();
};

