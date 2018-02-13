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


