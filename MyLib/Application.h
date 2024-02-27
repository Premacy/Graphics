#ifndef APPLICATION_H
#define APPLICATION_H

//#include "glad/gl.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Log/Logger.h"
#include "Window.h"
#include "Shaders/Shaders.h"

class Application{
public:
	Application() : window(nullptr), shaderProgram(nullptr) {};
	~Application();

	bool init(int w, int h);
	bool loadShaders();

	void mainLoop(int program);
	void getWindowSize(int &w, int &h);

private:
	Window *window; //TODO : smart pointers?
	Shaders* shaderProgram;
};

#endif
