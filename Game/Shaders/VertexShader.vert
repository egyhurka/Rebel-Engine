#version 330 core

layout(location = 0) in vec3 inPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 uColor;

out vec4 fragColor;

void main()
{
	fragColor = vec4(uColor, 1.0);
	gl_Position = projection * view * model * vec4(inPosition, 1.0);
}