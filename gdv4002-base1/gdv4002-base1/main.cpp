#include "Engine.h"
#include "Keys.h"
#include "Player.h"
#include "Emitter.h"
#include <bitset>
#include <complex>
using namespace std;

// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void deleteSnowlakes(GLFWwindow* window, double tDelta);

std::bitset<5> keys{ 0x0 };

// Global vars
glm::vec2 gravity = glm::vec2(0.0f, -0.005f);


void deleteSnowlakes(GLFWwindow* window, double tDelta) {

	GameObjectCollection snowflakes = getObjectCollection("snowflake");

	for (int i = 0; i < snowflakes.objectCount; i++) {

		if (snowflakes.objectArray[i]->position.y < -(getViewplaneHeight() / 2.0f)) {

			deleteObject(snowflakes.objectArray[i]);
		}
	}
}

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed

	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_ALWAYS);

	
	//
	// Setup game scene objects here
	//

	Emitter* emitter = new Emitter(
		glm::vec2(0.0f, getViewplaneHeight() / 2.0f * 1.2f),
		glm::vec2(getViewplaneWidth() / 2.0f, 0.0f),
		0.3f);

	addObject("emitter", emitter);


	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png");

	Player* mainPlayer = new Player(glm::vec2(0.0f, -1.5f), glm::radians(90.0f), glm::vec2(0.5f, 0.5f), playerTexture, 2.0f);

	addObject("player", mainPlayer);








	
	

	setKeyboardHandler(myKeyboardHandler);

	listGameObjectKeys();
	listObjectCounts();

	setUpdateFunction(deleteSnowlakes, false);




	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}



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




