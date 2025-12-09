#include "Bullet.h"
#include "keys.h"
#include <complex>
#include <bitset>

Bullet::Bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	speed = 5.0f;

}

void Bullet::update(double tDelta) {


	position = (position + speed) * (float)tDelta;

	




}
