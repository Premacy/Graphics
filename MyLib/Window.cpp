#include "Window.h"

Window::Window(int _w, int _h)
{
	w = _w;
	h = _h;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(w, h, "Simple example", NULL, NULL);
    if (!window)
        window = nullptr;
}

Window::~Window()
{
	glfwDestroyWindow(window);
}

void Window::set_context(void)
{
	glfwMakeContextCurrent(window);
}

void Window::swap_buffer(void)
{
	glfwSwapBuffers(window);
}

void Window::get_size(int &_w, int &_h)
{
	glfwGetFramebufferSize(window, &w, &h);
	_w = w;
	_h = h;
}

unsigned int Window::get_width(void) const
{
	return w;
}

unsigned int Window::get_height(void) const
{
	return h;
}

bool Window::is_open(void) const
{
	if(!window) return false;
	return !glfwWindowShouldClose(window);
}