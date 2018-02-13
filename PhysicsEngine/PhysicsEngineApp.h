#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

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
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};