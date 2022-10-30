#version 440

layout(location = 0) out vec4 outputColor;

layout(location = 4) uniform bool useNormal;

smooth in vec3 ioNormal;
smooth in vec3 ioColor;

void main() {
	outputColor = vec4(ioColor, 1);
}
