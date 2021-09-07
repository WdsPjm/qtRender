#version 330 core



out vec4 FragColor;

//in vec3 outColor;
in vec3 outNormal;
in vec2 m_texCoord;
in vec3 FragPos;

// texture samplers
uniform sampler2D samp1;
uniform sampler2D samp2;
uniform float mixValue;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
void main()
{

//	vec4 tmp  = mix(texture(samp1, m_texCoord), texture(samp2, m_texCoord), mixValue);
//	FragColor = vec4(tmp.rgb*outColor,1.0);
  // FragColor = vec4(objectColor * lightColor ,1.0f);

//ambient
   float ambientStreamth = 0.1;
   vec3 ambient = ambientStreamth * lightColor;

   //diffuse
   vec3 norm = normalize(outNormal);
   vec3 lightDir = normalize(lightPos - FragPos);
   float diff = max(dot(norm, lightDir), 0.0f);
   vec3 diffuse = diff * lightColor;

   //specular
   float specularStrength = 0.5f;
   vec3 viewDir = normalize(viewPos - FragPos);
   vec3 reflectDir =reflect(-lightDir,norm);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
   vec3 specular =specularStrength* spec *lightColor;

   vec3 result =(ambient + diffuse +specular) * objectColor;
   FragColor =vec4(result ,1.0f);

}
