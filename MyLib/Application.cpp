#include "Application.h"

Application::~Application(){
    delete window, delete shaderProgram;
}

bool Application::init(int w, int h){
	if (!glfwInit()){
       debug("Error: glfwInit() is not success!");        
        return false;
    }

	window = new Window(w, h);

	window->set_context();

	if(!gladLoadGL(glfwGetProcAddress)){
        debug("Error: gladLoadGL()");
        return false;
    }
    glfwSwapInterval(1);
}

bool Application::loadShaders(){

    shaderProgram = new Shaders();
    shaderProgram->load_shaders();
}


void Application::mainLoop(){

    GLuint program = shaderProgram.create_program();
    while(window->is_open())
        {   
            const char* description;

            int error = glfwGetError(&description);

            if(description){
                debug(description);
            }

            int w,h;
            w = window->get_width();
            h = window->get_height();

            glViewport(0, 0, w, h);

            glClearColor(0, 0, 0, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(program);

            draw_circle(program, start, 1000);

            window->swap_buffer();
            glfwPollEvents();
        }
}

void Application::getWindowSize(int &w, int &h){

}