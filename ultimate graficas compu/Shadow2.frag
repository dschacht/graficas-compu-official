#version 330

in vec3 PixelPosition;
in vec3 InterpolatedNormal;
in vec2 InterpolatedTexCoord;
in vec4 PixelPositionLightSpace;

uniform vec3 LightColor;
uniform vec3 LightPosition; 
uniform vec3 cameraPosition;
uniform sampler2D DiffuseTexture; 
uniform sampler2D DiffuseTexture2;
uniform sampler2D ShadowMap;


out vec4 FragColor;

float  IsPixelOccluded(vec4 fragPosLightSpace)
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

	vec4 Texture1 = texture2D(DiffuseTexture, InterpolatedTexCoord);
	vec4 Texture2 = texture2D(DiffuseTexture2, InterpolatedTexCoord);

	vec4 MixTexture = mix(Texture1, Texture2 , 0.5f);

	float shadow =  IsPixelOccluded(PixelPositionLightSpace);

	vec3 phongShading = (ambient + (1.0 - shadow )* (diffuse + specular));

	FragColor = vec4 (phongShading, 1.0f) * MixTexture;

}