#include "Engine.h"
#include "Keys.h"
#include "Player.h"
#include "Enemy.h"
#include <bitset>
#include <complex>
using namespace std;

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

std::bitset<5> keys{ 0x0 };

glm::vec2 gravity = glm::vec2(0.0f, -0.0f);



int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed


	}

	//
	// Setup game scene objects here
	//

	GLuint playerTexture = loadTexture("Resources\\Textures\\myBackground.png");



	GLuint playerTexture = loadTexture("Resources\\Textures\\myShip1.png");

	Player* mainPlayer = new Player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 2.5f);

	addObject("player", mainPlayer);


	GLuint enemyTexture = loadTexture("Resources\\Textures\\myAsteroid1.png");

	// 2. Create enemy objects
	Enemy* enemy1 = new Enemy(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(45.0f));

	Enemy* enemy2 = new Enemy(glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(90.0f));

	Enemy* enemy3 = new Enemy(glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(60.0f));

	// Add enemy objects to the engine
	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);



	
	/*addObject("player", glm::vec2(1.0f,1.0f), glm::radians(45.0f), glm::vec2(0.5f,1.0f), "Resources\\Textures\\mcblock01.png", TextureProperties::NearestFilterTexture());*/

	//addObject("player1");
	//addObject("player2");

	//GameObject2D* player1Object = getObject("player1");

	//if (player1Object != nullptr) {

	//	player1Object->position = glm::vec2(-1.0f, 1.0f);
	//	player1Object->orientation = glm::radians(-30.0f);
	//	player1Object->size = glm::vec2(2.0f, 3.0f);
	//	player1Object->textureID = loadTexture("Resources\\Textures\\bumblebee.png");
	//}

	//GameObject2D* player2Object = getObject("player2");

	//if (player2Object != nullptr) {

	//	player2Object->position = glm::vec2(1.5f, 1.0f);
	//	player2Object->orientation = glm::radians(45.0f);
	//	player2Object->size = glm::vec2(1.0f, 0.5f);
	//	player2Object->textureID = loadTexture("Resources\\Textures\\Player1_ship.png");
	//}

	//addObject("player", glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), "Resources\\Textures\\player1_ship.png");

	//addObject("enemy", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");

	//addObject("enemy", glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");

	//addObject("enemy", glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");
	//++

#
	//setUpdateFunction(myUpdate);
	
		

	setKeyboardHandler(myKeyboardHandler);

	listGameObjectKeys();
	listObjectCounts();

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

//
//float enemyPhase[3] = { glm::radians(0.0f), glm::radians(90.0f), glm::radians(270.0f) };
//float enemyPhaseVelocity[3] = { glm::radians(90.0f),
// glm::radians(90.0f),
// glm::radians(90.0f) };

//void myUpdate(GLFWwindow* window, double tDelta) {
//
//	/*float player1RotationSpeed = glm::radians(90.0f);
//	GameObject2D* player1 = getObject("player1");
//	player1->orientation += player1RotationSpeed * tDelta;*/
//
//	GameObjectCollection enemies = getObjectCollection("enemy");
//	for(int i = 0; i < enemies.objectCount; i++) {
//
//		enemies.objectArray[i]->position.y = sinf(enemyPhase[i]); // assume phase stored in radians so no conversion needed
//
//		enemyPhase[i] += enemyPhaseVelocity[i] * tDelta;
//	}
//
//
//	GameObject2D* player = getObject("player");
//	
//	static float playerSpeed = 1.0f; // distance per second
//	static float playerAngle = glm::radians(90.0f);
//	complex<float> i = complex<float>(0.0f, 1.0f);
//	auto c = exp(i * player->orientation);
//	
//
// 
//
//
//	
//
//	if (keys.test(Key::W) == true) {
//
//		player->position += glm::vec2(c.real(), c.imag()) * (float)tDelta;
//		//player->position.x += 0.0f;
//		//player->position.y += playerSpeed * (float)tDelta;
//	}
//	if (keys.test(Key::S) == true) {
//
//		player->position.y -= playerSpeed * (float)tDelta;
//	}
//	if (keys.test(Key::A) == true) {
//
//		player->orientation += playerAngle * (float)tDelta;
//	}
//	if (keys.test(Key::D) == true) {
//
//		player->orientation -= playerAngle * (float)tDelta;
//	}
//
//
//
//}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
				glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W:
			keys[Key::W] = true;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = true;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = true;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = true;
			break;





		}
	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {

		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = false;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = false;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = false;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = false;
			break;


		}





		// handle key release events
	}
}




