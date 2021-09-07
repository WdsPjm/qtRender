#version 330 core


layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 texCoord;

//out vec3 outColor;
out vec3 outNormal;
out vec2 m_texCoord;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{
	//m_texCoord = texCoord;
	//
	//outColor = inColor;
	//outNormal = inNormal;
	outNormal = mat3(transpose(inverse(model))) * inNormal;
	m_texCoord = vec2(texCoord.x, texCoord.y);
	m_texCoord.y*=-1;
	FragPos = vec3(model * vec4(pos,1.0f));
	gl_Position =projection * view * model* vec4(pos,1.0f);



	

}