#include "Shaders.h"

Shaders::~Shaders()
{
    glDeleteShader(v_shader);
    glDeleteShader(f_shader);  
    //glDeleteProgram(program);
}

void Shaders::load_shaders(void)
{   
    int success = 0;
    char logBuff[512];

	v_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(v_shader);

    glGetShaderiv(v_shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(v_shader, 512, NULL, logBuff);
        debug(logBuff);
    }

    f_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(f_shader);

    glGetShaderiv(f_shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(f_shader, 512, NULL, logBuff);
        debug(logBuff);
    }
}

int Shaders::create_program(void)
{
	program = glCreateProgram();
    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);
    glLinkProgram(program);

    int success = 0;
    char logBuff[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if(!success){
        glGetProgramInfoLog(program, 512, NULL, logBuff);
        debug(logBuff);
    }
    return program;
}

int Shaders::get_program(void) const
{
	return program;
}