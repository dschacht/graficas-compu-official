#version 330

in vec2 InterpolatedTexCoord;
in vec3 InterpolatedColor; 
in vec3 PixelPosition;
in vec3 InterpolatedNormal;

uniform sampler2D DiffuseTexture; 
uniform vec3 LightColor;
uniform vec3 LightPosition; 
uniform vec3 cameraPosition;

out vec4 FragColor;


void main()
{
	
	vec3 ambiente = 0.1f * LightColor;
	vec3 normal = normalize(InterpolatedNormal);
	vec3 lightDirection = normalize(LightPosition - PixelPosition);
	float a = dot(normal, lightDirection);
	if (a < 0.0f){
		a = 0.0f;
	}
	vec3 difusa = a * LightColor;
	vec3 reflejo = reflect (-lightDirection, normal);
	vec3 vista = normalize(cameraPosition - PixelPosition);

	float b = dot(reflejo, vista);
	if (b < 0.0f){
		b = 0.0f;
	}

	vec3 especular = 0.5f * pow(b,32)  * LightColor;

	vec3 phongShading = (ambiente + difusa + especular) * vec3 (texture2D(DiffuseTexture, InterpolatedTexCoord));
	//FragColor = texture2D(DiffuseTexture, InterpolatedTexCoord);
	FragColor = vec4(phongShading, 1.0f);
}

// mix vec4=mix(vec4 A, vec4 B, float)