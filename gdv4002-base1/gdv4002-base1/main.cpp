#include "Engine.h"+++++++++++

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);


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

	addObject("player", glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), "Resources\\Textures\\player1_ship.png");

	addObject("enemy", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");

	addObject("enemy", glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");

	addObject("enemy", glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");

	

	setUpdateFunction(myUpdate);

	listGameObjectKeys();
	listObjectCounts();

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


float enemyPhase[3] = { 0.0f, 1.0f, 2.0f };
float enemyPhaseVelocity[3] = { glm::radians(90.0f),
 glm::radians(90.0f),
 glm::radians(90.0f) };

void myUpdate(GLFWwindow* window, double tDelta) {

	/*float player1RotationSpeed = glm::radians(90.0f);
	GameObject2D* player1 = getObject("player1");
	player1->orientation += player1RotationSpeed * tDelta;*/

	GameObjectCollection enemies = getObjectCollection("enemy");
	for(int i = 0; i < enemies.objectCount; i++) {

		enemies.objectArray[i]->position.y = sinf(enemyPhase[i]); // assume phase stored in radians so no conversion needed

		enemyPhase[i] += enemyPhaseVelocity[i] * tDelta;
	}


}


