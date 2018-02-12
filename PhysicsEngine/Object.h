#pragma once
#include <glm/vec2.hpp>
#include "Gizmos.h"
enum ShapeType{BOX,SPHERE,PLANE};
using namespace glm;
class Object
{

protected:
	Object(ShapeType shapeID) : m_shapeID(shapeID) {}
	~Object();
	ShapeType m_shapeID;

	

public:
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	virtual void debug() = 0;
	virtual void makeGizomo() = 0;
	virtual void resetPosition() {};

	
};

