#version 440

layout(location = 0) out vec4 outputColor;

layout(location = 4) uniform bool useNormal;

smooth in vec4 ioNormal;
smooth in vec4 ioColor;

float maxcomp3(vec3 v) {
	return max(v.x, max(v.y, v.z));
}

void main() {
	float gray = 1;
	if (useNormal)
		gray = maxcomp3(ioNormal.xyz);
	outputColor = vec4(vec3(gray), 1) * ioColor;
}
