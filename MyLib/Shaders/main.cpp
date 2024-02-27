#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <iostream>

#include "Shaders.h"
#include "Window.h"

#include "Log/Logger.h"

#include "math/Vec2.h"
#include "Render/Primitives/Primitives.hpp"

void init()
{   
    if(!gladLoadGL(glfwGetProcAddress)){
        debug("Error: gladLoadGL()");
    }
    glfwSwapInterval(1);
}


int main(void)
{   
    Logger::log("Hello, log!");

    debug("START PROGRAM!");

    if (!glfwInit()){
       debug("Error: glfwInit() is not success!");        
        exit(EXIT_FAILURE);
    }

    Window *window = new Window(640, 480);

    window->set_context();
    init();

    Shaders shaders;
    shaders.load_shaders();

    GLuint program;

    program = shaders.create_program();
    debug(program);
    
    if(!program){
        return -1;
    }

    Math::Vec2 start(0,0);
    Math::Vec2 end(0,1);

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
    
    glfwTerminate();
    delete window;

    debug("End program !");

    return 1;
}