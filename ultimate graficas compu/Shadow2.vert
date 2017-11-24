#version 330

in vec3 VertexPosition; 
in vec3 VertexNormal;
in vec2 VertexTexCoord;


out vec3 PixelPosition;
out vec3 InterpolatedNormal;
out vec2 InterpolatedTexCoord;
out vec4 PixelPositionLightSpace;

uniform mat4 mvpMatrix;
uniform mat4 ModelMatrix;
uniform mat3 normalMatrix; 
uniform mat4 LightVPMatrix;


void main()
{
	gl_Position = mvpMatrix * vec4(VertexPosition, 1.0f);
	PixelPosition = vec3(ModelMatrix * vec4(VertexPosition, 1.0f));
	InterpolatedNormal = normalMatrix * VertexNormal;
	InterpolatedTexCoord = VertexTexCoord;
	PixelPositionLightSpace = LightVPMatrix * vec4(PixelPosition, 1.0f);
}