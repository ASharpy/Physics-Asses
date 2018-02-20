#include "PhysicsScene.h"

void PhysicsScene::update(float DT)
{
	static float accumlatedTime = 0.0f;
	accumlatedTime += DT;
	while (accumlatedTime >= m_timeStep)
	{
		for (auto var : objectList)
		{
			var->fixedUpdate(m_gravity, m_timeStep);
		}
		accumlatedTime -= m_timeStep;
	}
}

void PhysicsScene::updateGizmos()
{
	for (auto var : objectList)
	{
		var->makeGizmo();
	}
}

typedef bool(*fn)(Object*, Object*);
static fn collisionFunctionArray[] =
{
	PhysicsScene::planeToPlane, PhysicsScene::planeToSphere, PhysicsScene::sphereToPlane, PhysicsScene::sphereToSphere
};

void PhysicsScene::checkCollision()
{
	int objectCount = objectList.size();

	for (int outer = 0; outer < objectCount - 1; outer++)
	{
		for (int  inner = 0; inner < objectCount; inner++)
		{
			Object* object1 = objectList[outer];
			Object* object2 = objectList[inner];
			int shapeId1 = object1->m_shapeID;
			int shapeId2 = object2->m_shapeID;
			int functionIdx = (shapeId1 * ShapeType::SPHERE) + shapeId2;
			fn collisionFunctionPtr = collisionFunctionArray[functionIdx];
			if (collisionFunctionPtr != nullptr)
			{
				collisionFunctionPtr(object1, object2);
			}
		}
	}
}
PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(vec2(0,0))
{
}


PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::addObject(Object * object)
{
	objectList.push_back(object);
}


