#version 330 core

out vec4 FragColor;
in vec3 outColor;
in vec2 m_texCoord;

uniform sampler2D samp1;
uniform float discardValue;
void main()
{
	//FragColor = vec4(outColor,1.0f);
	vec4 textureColor = texture(samp1, m_texCoord);
	if(textureColor.a<discardValue)
	{
		discard;
	}
	FragColor = textureColor;
}