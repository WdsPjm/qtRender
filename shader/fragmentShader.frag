#version 330 core



out vec4 FragColor;

in vec3 outColor;
in vec2 m_texCoord;

// texture samplers
uniform sampler2D samp1;
uniform sampler2D samp2;
uniform float mixValue;
void main()
{
	//vec3 rgb1 =texture2D(samp1,m_texCoord).rgb;
	//vec3 rgb2 =texture2D(samp2,m_texCoord).rgb;
	//gl_FragColor =vec4( rgb1 ,1.0f);
	//FragColor = vec4(outColor,1.0f);
    //gl_FragColor = vec4(mix(texture2D(samp2,m_texCoord).rgb,texture2D(samp1,m_texCoord).rgb*outColor,0.5f),1.0f);
	//FragColor = mix(texture2D(samp1, m_texCoord), texture2D(samp2, m_texCoord), 0.5);
	//FragColor =vec4(texture2D(samp1, m_texCoord).rgb*outColor,1.0f);
	//FragColor = texture2D(samp2,m_texCoord);
	FragColor = mix(texture(samp1, m_texCoord), texture(samp2, m_texCoord), mixValue);
}