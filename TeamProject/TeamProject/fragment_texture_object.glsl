#version 330 core
in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

uniform sampler2D outTexture;

out vec4 FragColor;

uniform float ambient;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main ()
{
	float ambientLight = ambient;
	vec3 ambient = ambientLight * vec3(1.0, 1.0, 1.0);
	
	vec3 normalVector = normalize (Normal);
	vec3 lightDir = normalize (lightPos - FragPos);
	float diffuseLight = max(dot(normalVector, lightDir), 0.0);
	vec3 diffuse = diffuseLight * lightColor;
	
	int shininess = 128;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, normalVector);
	float specularLight = max(dot(viewDir, reflectDir), 0.0);	
	specularLight = pow(specularLight, shininess);
	vec3 specular = specularLight * lightColor;

	vec3 result = (ambient + diffuse + specular);

	FragColor = vec4 (result, 1.0);
	FragColor = texture(outTexture, TexCoord) * FragColor;
}