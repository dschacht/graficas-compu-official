#version 330

in vec4 PixelPositionLightSpace;
in vec2 InterpolatedTexCoord;
in vec3 InterpolatedColor; 
in vec3 PixelPosition;
in vec3 InterpolatedNormal;

uniform sampler2D ShadowMap;
uniform sampler2D DiffuseTexture; 
uniform vec3 LightColor;
uniform vec3 LightPosition; 
uniform vec3 cameraPosition;

out vec4 FragColor;

float IsPixelOccluded(vec4 fragPosLightSpace) 
{
	vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w; 
	projCoords = (projCoords * 0.5 + 0.5);

	float closestDepth = texture2D(ShadowMap, projCoords.xy).r;  
	float currentDepth = projCoords.z; 

	float shadow = currentDepth - 0.005f > closestDepth ? 1.0f : 0.0f; 
	return shadow; 
}

void main()
{
	
	vec3 ambient = 0.1f * LightColor;
	vec3 normal = normalize(InterpolatedNormal);
	vec3 lightDirection = normalize(LightPosition - PixelPosition);
	float a = dot(normal, lightDirection);
	if (a < 0.0f){
		a = 0.0f;
	}
	vec3 diffuse = a * LightColor;
	vec3 reflejo = reflect (-lightDirection, normal);
	vec3 vista = normalize(cameraPosition - PixelPosition);

	float b = dot(reflejo, vista);
	if (b < 0.0f){
		b = 0.0f;
	}

	vec3 specular = 0.5f * pow(b,32)  * LightColor;

	float shadow = IsPixelOccluded(PixelPositionLightSpace);
	vec3 phong = (ambient + (1.0f - shadow) * (diffuse + specular));
	//vec3 phongShading = (ambient + diffuse + specular) * vec3 (texture2D(DiffuseTexture, InterpolatedTexCoord));
	//FragColor = texture2D(DiffuseTexture, InterpolatedTexCoord);
	FragColor = vec4(phong, 1.0f) * texture2D(DiffuseTexture, InterpolatedTexCoord);

	

}

// mix vec4=mix(vec4 A, vec4 B, float)
