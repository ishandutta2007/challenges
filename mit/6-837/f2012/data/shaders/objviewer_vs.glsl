#version 440 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 normal;

layout(location = 0) uniform mat4 transform;
layout(location = 1) uniform mat4 modelview;
layout(location = 2) uniform mat4 projection;
layout(location = 3) uniform vec4 color;

smooth out vec4 ioNormal;
smooth out vec4 ioColor;

void main() {
	gl_Position = projection * modelview * transform * position;
	ioNormal = transpose(inverse(modelview * transform)) * normal;
	ioColor = color;
}
