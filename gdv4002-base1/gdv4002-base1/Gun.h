#pragma once

#include "GameObject2D.h"
#include "Bullet.h"

class Gun : public GameObject2D {

private:
	float		mass;
	glm::vec2	velocity;

public:
	Gun(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass);

	void update(double tDelta) override;
	void render() override;


};