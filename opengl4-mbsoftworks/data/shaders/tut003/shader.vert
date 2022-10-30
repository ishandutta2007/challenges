#version 440 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

smooth out vec3 ioVertexColor;

void main()
{
    gl_Position = vec4(vertexPosition, 1.0);
    ioVertexColor = vertexColor;
}