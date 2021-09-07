#version 330 core

out vec4 FragColor;

//in vec3 outColor;
in vec3 outNormal;
in vec2 m_texCoord;
in vec3 FragPos;

struct Material {
sampler2D diffuse;
//vec3 diffuse;
//vec3 specular;
sampler2D specular;
float shininess;
};

struct Light{
vec3 position;
vec3 ambient;
vec3 diffuse;
vec3 specular;
};

// texture samplers
uniform sampler2D samp1;
uniform sampler2D samp2;
uniform float mixValue;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

uniform float matrixlight;
uniform float matrixmove;
void main()
{

//ambient
   vec3 ambient = light.ambient * texture(material.diffuse,m_texCoord).rgb;

   //diffuse
   vec3 norm = normalize(outNormal);
   vec3 lightDir = normalize(light.position - FragPos);
   float diff = max(dot(norm, lightDir), 0.0f);
   vec3 diffuse = light.diffuse *  diff * texture(material.diffuse,m_texCoord).rgb;

   //specular
   float specularStrength = 0.5f;
   vec3 viewDir = normalize(viewPos - FragPos);
   vec3 reflectDir =reflect(-lightDir,norm);
   float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
   vec3 specular =light.specular * spec * (texture(material.specular,m_texCoord).rgb);
   vec3 emission = matrixlight*texture(material.specular,vec2(m_texCoord.x,m_texCoord.y+matrixmove)).rgb;

   vec3 result =(ambient + diffuse + specular + emission) ;
   //vec4 tmp  = mix(texture(samp1, m_texCoord), texture(samp2, m_texCoord), mixValue);

   FragColor =vec4( result ,1.0f);

}
