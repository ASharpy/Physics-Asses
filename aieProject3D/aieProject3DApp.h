#pragma once

#include "Application.h"
#include <glm/mat4x4.hpp>

class aieProject3DApp : public aie::Application {
public:

	aieProject3DApp();
	virtual ~aieProject3DApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};