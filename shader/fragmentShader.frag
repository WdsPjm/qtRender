#version 330 core



out vec4 FragColor;

in vec3 outColor;
in vec2 m_texCoord;

// texture samplers
uniform sampler2D samp1;
uniform sampler2D samp2;
uniform float mixValue;
uniform vec3 objectColor;
uniform vec3 lightColor;
void main()
{

//	vec4 tmp  = mix(texture(samp1, m_texCoord), texture(samp2, m_texCoord), mixValue);
//	FragColor = vec4(tmp.rgb*outColor,1.0);
   FragColor = vec4(objectColor * lightColor ,1.0f);
}
