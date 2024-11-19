#version 330 core

layout(location = 0) in vec3 inPosition;
//layout(location = 1) in vec3 inColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 uColor;

out vec4 fragColor;

void main()
{
	fragColor = inColor;
	gl_Position = projection * view * model vec4(inPosition, 1.0);
}