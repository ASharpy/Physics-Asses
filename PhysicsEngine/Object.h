#pragma once
#include <glm/ext.hpp>
#include "Gizmos.h"
enum ShapeType{BOX,SPHERE,PLANE};
using namespace glm;
class Object
{

protected:

	Object() {}
	Object(ShapeType shapeID) : m_shapeID(shapeID) {}
	~Object();
	

	

public:
	ShapeType m_shapeID;
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	//virtual void debug() = 0;
	virtual void makeGizmo() = 0;
	virtual void resetPosition() {};

	
};

