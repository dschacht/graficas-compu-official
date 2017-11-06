#version 330

in vec3 VertexPosition;
in vec3 VertexColor;
in vec3 VertexNormals;

out vec3 InterpolatedNormals;
out vec3 PixelPosition;
out vec3 InterpolatedColor;



uniform mat4 mvpMatrix;
uniform mat4 ModelMatrix;
uniform mat3 normalsMatrix;


void main()  
{     
  PixelPosition = vec3 (ModelMatrix * vec4(VertexPosition, 1.0f));
  InterpolatedColor = VertexColor;
  gl_Position = mvpMatrix *vec4(VertexPosition, 1.0f);
  InterpolatedNormals= normalsMatrix *VertexNormals;
}