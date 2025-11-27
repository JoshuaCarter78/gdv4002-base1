#include "Player.h"
#include "Keys.h"
#include "Engine.h"
#include "complex.h"
#include <bitset>



extern std::bitset<5> keys;
extern glm::vec2 gravity;

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) {

	this->mass = mass;
	

	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity
}





void Player::update(double tDelta) {

	// Unlike our myUpdate function, we're already 'in' the player object, so no need to call getObject as we did before :)


	glm::vec2 F = glm::vec2(0.0f, 0.0f);

	const float thrust = 2.0f;


	// 1. accumulate forces
	if (keys.test(Key::W) == true) {

		F += glm::vec2(0.0f, thrust);
	}
	if (keys.test(Key::S) == true) {

		F += glm::vec2(0.0f, -thrust);
	}
	if (keys.test(Key::A) == true) {

		F += glm::vec2(-thrust, 0.0f);
	}
	if (keys.test(Key::D) == true) {

		F += glm::vec2(thrust, 0.0f);
	}

	//F += gravity;

	// add impulse force

	//down - inverse teleport
	if (position.y < -getViewplaneHeight() / 2.0f) {

		position.y = getViewplaneHeight() / 2.0;
	}

	//up - inverse teleport
	if (position.y > getViewplaneHeight() / 2.0f) {		

		position.y = -getViewplaneHeight() / 2.0;
		}
		
	//left - bounce
	if (position.x < -getViewplaneWidth() / 2.0f) {

		F += glm::vec2((velocity.x * -125.0f), 0.0);
		position.x = -getViewplaneHeight() / 2.0;
	}

	//right - inverse teleport
	if (position.x > getViewplaneWidth() / 2.0f) {

		position.x = -getViewplaneHeight() / 2.0;
	}


	// 2. calculate acceleration.  If f=ma, a = f/m
	glm::vec2 a = F * (1.0f / mass);

	// 3. integate to get new velocity
	velocity = velocity + (a * (float)tDelta);

	// 4. integrate to get new position
	position = position + (velocity * (float)tDelta);




}
