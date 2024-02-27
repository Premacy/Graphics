#ifndef WINDOW_H
#define WINDOW_H

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window{
private:
	GLFWwindow *window;
	int w,h;

public:
	Window(int _w, int _h);
	~Window();

	bool is_open(void) const;

	void get_size(int &w, int &h);
	void swap_buffer(void);

	void set_context(void);

	unsigned int get_width(void) const;
	unsigned int get_height(void) const;
};

#endif