#version 330
in vec3 InterpolatedColor;
in vec3 InterpolatedNormals;
in vec3 PixelPosition;


out vec4 FragColor;

uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform vec3 cameraPosition;
  

void main ()  
{  

   //calculate Ambient Term:  
   
   vec3 ambient = 0.1f*LightColor;
   vec3 normals = normalize(InterpolatedNormals);   vec3 lightDirection = normalize(LightPosition - PixelPosition);   float p = dot(normals, lightDirection);   if(p< 0.0f){   p= 0.0f;   }   vec3 difuse= p*LightColor;   vec3 reflection =reflect (-lightDirection, normals);   vec3 view= normalize(cameraPosition-PixelPosition);   float w = dot(reflection, view);   if(w<0.0f){   w= 0.0f;   }   vec3 specular = 0.5f * pow(w,32)*LightColor;   vec3 phongShading = (ambient +difuse + specular)* InterpolatedColor;   FragColor= vec4(phongShading,1.0f);

   
}
          