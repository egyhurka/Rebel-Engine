#version 330 core

layout(triangles) in;

layout(triangle_strip, max_vertices = 4) out;

in vec3 fragColor[];
out vec3 outColor;

void main()
{
	for ()int i = 0; i < 3; i++)
	{
		gl_Position = gl_in[i].gl_Position;
        outColor = fragColor[i];
        EmitVertex();
	}
	EndPrimitive();
}