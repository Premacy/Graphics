#ifndef PRIMITIVES_H
#define PRIMITIVES_H

//#include "../../Log/Log.h"
#include "../../math/Vec2.h"

#include <vector>

int gen_buffer(const std::vector< Math::Vec2 > points){
    GLuint vertex_buffer;

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points[0]) * 2, &points[0], GL_STATIC_DRAW);

    return vertex_buffer;
}

void draw_line(GLuint program, const Math::Vec2 &start, const Math::Vec2 &end){

    GLuint vertex_buffer;
    Math::Vec2 vertices[2] = {start, end};

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(start) * 2, vertices, GL_STATIC_DRAW);

    GLint vpos_location = 0;

    vpos_location = glGetAttribLocation(program, "vPos");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void*) 0);

    glDrawArrays(GL_LINES, 0, 2);
}

void draw_line_strip(GLuint program, const std::vector< Math::Vec2 > &points){

  
}

void draw_circle(GLuint program, const Math::Vec2 center, float radius){
    GLuint vertex_buffer;

    Math::Vec2 vertices[1] = {center};

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(center), vertices, GL_STATIC_DRAW);

    GLint vpos_location = 0;

    vpos_location = glGetAttribLocation(program, "vPos");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(center), (void*) 0);

    glEnable(GL_POINT_SMOOTH);
    glPointSize(int(radius));
    glDrawArrays(GL_POINTS, 0, 1);
}

void draw_point(auto *surface, const Math::Vec2 &coords){

}

#endif