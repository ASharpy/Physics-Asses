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
		for (int inner = outer + 1; inner < objectCount; inner++)
		{
			Object* object1 = objectList[outer];
			Object* object2 = objectList[inner];
			int shapeId1 = object1->m_shapeID;
			int shapeId2 = object2->m_shapeID;
			int functionIdx = (shapeId1 * 2) + shapeId2;
			fn collisionFunctionPtr = collisionFunctionArray[functionIdx];
			if (collisionFunctionPtr != nullptr)
			{
				 collisionFunctionPtr(object1, object2);
			}
			else
			{
				return;
			}
		}
	}
	
}

bool PhysicsScene::planeToPlane(Object * obj1, Object * obj2)
{
	return false;
}

bool PhysicsScene::planeToSphere(Object * obj1, Object * obj2)
{
	return false;
}

bool PhysicsScene::sphereToPlane(Object * obj1, Object * obj2)
{
	Sphere * sphere = dynamic_cast<Sphere*>(obj1);

	Plane* plane = dynamic_cast<Plane*>(obj2);

	

	if (sphere != nullptr && plane != nullptr)
	{



		vec2 planeNormal = plane->getNormal();
		vec2 spherePos = sphere->getPosition();

		float Pdistance = dot(spherePos, planeNormal) - plane->getDistance();

		if (Pdistance < 0)
		{
			planeNormal *= -1;
			Pdistance *= -1;
		}

		float intersection = sphere->getRadius() - Pdistance;

		if (intersection > 0)
		{
			plane->resolveCollision(sphere);
			sphere->setPosition((sphere->getPosition()  + vec2(0,intersection)));
			return true;
		}

		return false;
	}
}
	

bool PhysicsScene::sphereToSphere(Object * sphere1, Object * sphere2)
{
	Sphere * Sphere1 = dynamic_cast<Sphere*>(sphere1);

	Sphere* Sphere2 = dynamic_cast<Sphere*>(sphere2);

	float distance1 = glm::length(Sphere1->getPosition() - Sphere2->getPosition());
	float rDistance = Sphere1->getRadius() +Sphere2->getRadius();
	

	if (distance1 < rDistance)
	{
		Sphere1->resolveCollision(Sphere2);
	}
	return false;
}
PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(vec2(0, 0)){}


PhysicsScene::~PhysicsScene(){}

void PhysicsScene::addObject(Object * object)
{
	objectList.push_back(object);
}


