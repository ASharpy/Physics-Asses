#include "PhysicsEngineApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Gizmos.h>
#include <glm\ext.hpp>
#include <iostream>


PhysicsEngineApp::PhysicsEngineApp() {

}

PhysicsEngineApp::~PhysicsEngineApp() {

}

bool PhysicsEngineApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_physicsScene = new PhysicsScene();

	m_physicsScene->setGravity(vec2(0, -20));

	ball = new Sphere(vec2(0, 40), vec2(0, 0), 3.0f, 5, vec4(1, 0, 0, 1));

	ball2 = new Sphere(vec2(40, 40), vec2(0, 0), 3.0f, 5, vec4(0, 1, 0, 1));
	
	plane = new Plane(vec2(0, 1), -20);

	plane2 = new Plane(vec2(1, 0), -30);

	plane3 = new Plane(vec2(1, 0), 30);

	m_physicsScene->addObject(ball);

	m_physicsScene->addObject(ball2);

	m_physicsScene->addObject(plane);
	m_physicsScene->addObject(plane3);
	m_physicsScene->addObject(plane2);

	ball->applyForce(vec2(100,0));
	return true;
}

void PhysicsEngineApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void PhysicsEngineApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();
	
	m_physicsScene->update(deltaTime);
	m_physicsScene->checkCollision();
	m_physicsScene->updateGizmos();

	


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void PhysicsEngineApp::draw() {
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	
	// draw your stuff here!
	static float aspectRatio = 16 / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));
	


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}