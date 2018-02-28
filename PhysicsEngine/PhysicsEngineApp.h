#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"
#include "Object.h"

class PhysicsEngineApp : public aie::Application {
public:

	PhysicsEngineApp();
	virtual ~PhysicsEngineApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	PhysicsScene* m_physicsScene;
	Sphere *ball;
	Sphere* ball2;
	Plane *plane;
	Plane *plane2;
	Plane *plane3;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};