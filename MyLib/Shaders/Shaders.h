#ifndef SHADER_H
#define SHADER_H

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../Log/Logger.h"

#include <string>

class Shaders{
private:
	int v_shader, f_shader, program;

public:
	Shaders(): v_shader(0), f_shader(0), program(0) {};
	~Shaders();
	
	void load_shaders(void);

	void set_shaders(int v_shader, int f_shader);

	int create_program(void);
	int get_program(void) const;

	bool load_shaders(std::string vertex_shader_path, std::string fragment_shader_path) //TODO

	bool load_fragment_shader(std::string fragment_shader_path) //TODO
	bool load_vertex_shader(std::string vertex_shader_path) //TODO
};

static const char* vertex_shader_text =
"#version 110\n"
"attribute vec2 vPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(vPos, 0.0, 1.0);\n"
"}\n";

static const char* fragment_shader_text =
"#version 110\n"
"void main()\n"
"{\n"
"    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\n";

#endif
