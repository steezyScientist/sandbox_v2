#version 330 core
struct Material {    
	sampler2D texture_diffuse;
	sampler2D texture_specular;
	sampler2D texture_normal;
	vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
  
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform Material material;
uniform Light light;

uniform vec3 view_position;

out vec4 color;

void main()
{
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse, TexCoord));

	//diffuse
	vec3 normal = normalize(Normal);
	vec3 lightDir = normalize(-light.direction);
	float NdotL = max(dot(normal, lightDir), 0.0f);
	vec3 diffuse = NdotL * light.diffuse *  vec3(texture(material.texture_diffuse, TexCoord));

	//specular
	vec3 viewDir = normalize(-view_position);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = vec3(texture(material.texture_specular, TexCoord)) * spec * light.specular;

	vec3 result = (ambient + diffuse + specular);
	color = vec4(result, 1.0);
	//color = vec4(normal, 1.0); //debug for testing different results
	//test
}
