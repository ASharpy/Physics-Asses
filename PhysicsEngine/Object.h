#pragma once
#include <glm/vec2.hpp>
#include "Gizmos.h"
using namespace glm;
class Object
{

protected:
	Object() {}
	~Object();


	

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	virtual void debug() = 0;
	virtual void makeGizomo() = 0;
	virtual void resetPosition() {};
};

