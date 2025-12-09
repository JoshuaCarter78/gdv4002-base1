#include "Gun.h"
#include "Player.h"
#include "Keys.h"
#include "Engine.h"
#include <complex>
#include <bitset>



extern std::bitset<5> keys;
extern glm::vec2 gravity;

Gun::Gun(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity
}





void Gun::update(double tDelta) {



	glm::vec2 F = glm::vec2(0.0f, 0.0f);

	const float thrust = 3.5f;



	const float playerRotationSpeed = glm::radians(175.0f);

	std::complex<float> i = std::complex<float>(0.0f, 1.0f);
	auto c = exp(i * orientation);

	// 1. accumulate forces
	if (keys.test(Key::W) == true) {

		F += glm::vec2(c.real(), c.imag()) * thrust;
	}
	if (keys.test(Key::S) == true) {

		F += glm::vec2(-c.real(), -c.imag()) * thrust;
	}
	if (keys.test(Key::A) == true) {

		orientation += playerRotationSpeed * (float)tDelta;
	}
	if (keys.test(Key::D) == true) {

		orientation += -playerRotationSpeed * (float)tDelta;
	}

}

void Gun::render()
{
}