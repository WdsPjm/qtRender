#version 330 core


layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 texCoord;
out vec3 outColor;
out vec2 m_texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{

	outColor = inColor;
	m_texCoord = vec2(texCoord.x, texCoord.y);
	gl_Position = projection * view * model* vec4(pos,1.0f);
	//gl_Position = vec4(pos,1.0f);

}
