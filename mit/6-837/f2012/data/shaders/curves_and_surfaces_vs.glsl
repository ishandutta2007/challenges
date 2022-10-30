#version 440 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec3 color;

layout(location = 0) uniform mat4 transform;
layout(location = 1) uniform mat4 modelview;
layout(location = 2) uniform mat4 projection;

smooth out vec3 ioNormal;
smooth out vec3 ioColor;

void main() {
	gl_Position = projection * modelview * transform * vec4(position, 1);
	ioNormal = vec3(transpose(inverse(modelview * transform)) * vec4(normal, 1));
	ioColor = color;
}
