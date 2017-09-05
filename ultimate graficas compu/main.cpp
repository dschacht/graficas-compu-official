#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Inputfile.h"

//identificador del manager al que vamos a asociar todos los VBOs
GLuint vao;

//identificador del manager de los shaders (shaderProgram)
GLuint shaderProgram;

typedef struct
{
	float x;
	float y;
}CIRCLE;

CIRCLE circle;

float rot = 0;

void createcircle(int k, int r, int h) {
	glBegin(GL_LINES);
	for (int i = 0; i < 180; i++)
	{
		circle.x = r * cos(i) - h;
		circle.y = r * sin(i) + k;
		glVertex3f(circle.x + k, circle.y - h, 0);

		circle.x = r * cos(i + 0.1) - h;
		circle.y = r * sin(i + 0.1) + k;
		glVertex3f(circle.x + k, circle.y - h, 0);
	}
	glEnd();
}

void Initialize() 
{

	//creando la memoria que el programa va a utilizar

	//creacion del atributo de posiciones de los vertices
	//lista de vec2
	//claramente en el cpu y ram
	
	std::vector<glm::vec2> positions;
	
	positions.push_back(glm::vec2(0.0f, 0.0f));
	positions.push_back(glm::vec2(1.0f, 0.0f));
	positions.push_back(glm::vec2(0.999847695156f, 0.017452406437f)); //1
	positions.push_back(glm::vec2(0.999390827019f, 0.034899496703f));//2
	positions.push_back(glm::vec2(0.998629534755f, 0.052335956243f));//3
	positions.push_back(glm::vec2(0.99756405f, 0.06975647f));//4
	positions.push_back(glm::vec2(0.9961947f, 0.08715574f));//5
	positions.push_back(glm::vec2(0.9945219f, 0.10452846f));//6
	positions.push_back(glm::vec2(0.99254615f, 0.12186934f));//7
	positions.push_back(glm::vec2(0.99026807f, 0.1391731f));//8
	positions.push_back(glm::vec2(0.98768834f, 0.15643447f));//9
	positions.push_back(glm::vec2(0.98480775f, 0.17364818f));//10
	positions.push_back(glm::vec2(0.98162718f, 0.190809f));//11
	positions.push_back(glm::vec2(0.9781476f, 0.20791169f));//12
	positions.push_back(glm::vec2(0.97437006f, 0.22495105f));//13
	positions.push_back(glm::vec2(0.97029573f, 0.2419219f));//14
	positions.push_back(glm::vec2(0.96592583f, 0.25881905f));//15
	positions.push_back(glm::vec2(0.9612617f, 0.27563736));//16
	positions.push_back(glm::vec2(0.95630476f, 0.2923717f));//17
	positions.push_back(glm::vec2(0.95105652f, 0.30901699f));//18
	positions.push_back(glm::vec2(0.94551858f, 0.32556815f));//19
	positions.push_back(glm::vec2(0.93969262f, 0.34202014f));//20
	positions.push_back(glm::vec2(0.93358043f, 0.35836795f));//21
	positions.push_back(glm::vec2(0.92718385f, 0.37460659f));//22
	positions.push_back(glm::vec2(0.92050485f, 0.39073113f));//23
	positions.push_back(glm::vec2(0.91354546f, 0.40673664f));//24
	positions.push_back(glm::vec2(0.90630779f, 0.42261826f));//25
	positions.push_back(glm::vec2(0.89879405f, 0.43837115f));//26
	positions.push_back(glm::vec2(0.89100652f, 0.4539905f));//27
	positions.push_back(glm::vec2(0.88294759f, 0.46947156f));//28
	positions.push_back(glm::vec2(0.87461971f, 0.48480962f));//29
	positions.push_back(glm::vec2(0.8660254f, 0.5f));//30
	positions.push_back(glm::vec2(0.8571673f, 0.51503807f));//31
	positions.push_back(glm::vec2(0.8480481f, 0.52991926f));//32
	positions.push_back(glm::vec2(0.83867057f, 0.54463904f));//33
	positions.push_back(glm::vec2(0.82903757f, 0.5591929f));//34
	positions.push_back(glm::vec2(0.81915204f, 0.57357644f));//35
	positions.push_back(glm::vec2(0.80901699f, 0.58778525f));//36
	positions.push_back(glm::vec2(0.79863551f, 0.60181502f));//37
	positions.push_back(glm::vec2(0.78801075f, 0.61566148f));//38
	positions.push_back(glm::vec2(0.77714596f, 0.62932039f));//39
	positions.push_back(glm::vec2(0.76604444f, 0.64278761f));//40
	positions.push_back(glm::vec2(0.75470958f, 0.65605903f));//41
	positions.push_back(glm::vec2(0.74314483f, 0.66913061f));//42
	positions.push_back(glm::vec2(0.7313537f, 0.68199836f));//43
	positions.push_back(glm::vec2(0.7193398f, 0.69465837f));//44
	positions.push_back(glm::vec2(0.70710678f, 0.70710678f));//45
	positions.push_back(glm::vec2(0.69465837f, 0.7193398f));//46
	positions.push_back(glm::vec2(0.68199836f, 0.7313537f));//47
	positions.push_back(glm::vec2(0.66913061f, 0.74314483f));//48
	positions.push_back(glm::vec2(0.65605903f, 0.75470958f));//49
	positions.push_back(glm::vec2(0.64278761f, 0.76604444f));//50
	positions.push_back(glm::vec2(0.62932039f, 0.77714596f));//51
	positions.push_back(glm::vec2(0.61566148f, 0.78801075f));//52
	positions.push_back(glm::vec2(0.60181502f, 0.79863551f));//53
	positions.push_back(glm::vec2(0.58778525f, 0.80901699f));//54
	positions.push_back(glm::vec2(0.57357644f, 0.81915204f));//55
	positions.push_back(glm::vec2(0.5591929f, 0.82903757f));//56
	positions.push_back(glm::vec2(0.54463904f, 0.83867057f));//57
	positions.push_back(glm::vec2(0.52991926f, 0.8480481f));//58
	positions.push_back(glm::vec2(0.51503807f, 0.8571673f));//59
	positions.push_back(glm::vec2(0.5f, 0.8660254f));//60
	positions.push_back(glm::vec2(0.48480962f, 0.8660254f));//61
	positions.push_back(glm::vec2(0.46947156f, 0.87461971f));//62
	positions.push_back(glm::vec2(0.4539905f, 0.88294759f));//63
	positions.push_back(glm::vec2(0.43837115f, 0.89100652f));//64
	positions.push_back(glm::vec2(0.42261826f, 0.89879405f));//65
	positions.push_back(glm::vec2(0.40673664f, 0.90630779f));//66
	positions.push_back(glm::vec2(0.39073113f, 0.91354546f));//67
	positions.push_back(glm::vec2(0.37460659f, 0.92050485f));//68
	positions.push_back(glm::vec2(0.35836795f, 0.92718385f));//69
	positions.push_back(glm::vec2(0.34202014f, 0.93358043f));//70
	positions.push_back(glm::vec2(0.32556815f, 0.93969262f));//71
	positions.push_back(glm::vec2(0.30901699f, 0.94551858f));//72
	positions.push_back(glm::vec2(0.2923717f, 0.95630476f));//73
	positions.push_back(glm::vec2(0.27563736f, 0.9612617f));//74
	positions.push_back(glm::vec2(0.25881905f, 0.96592583f));//75
	positions.push_back(glm::vec2(0.2419219f, 0.97029573f));//76
	positions.push_back(glm::vec2(0.22495105f, 0.97437006f));//77
	positions.push_back(glm::vec2(0.20791169f, 0.9781476f));//78
	positions.push_back(glm::vec2(0.190809f, 0.98162718f));//79
	positions.push_back(glm::vec2(0.17364818f, 0.98480775f));//80
	positions.push_back(glm::vec2(0.15643447f, 0.98768834f));//81
	positions.push_back(glm::vec2(0.1391731f, 0.99026807f));//82
	positions.push_back(glm::vec2(0.12186934f, 0.99254615f));//83
	positions.push_back(glm::vec2(0.10452846f, 0.9945219f));//84
	positions.push_back(glm::vec2(0.08715574f, 0.9961947f));//85
	positions.push_back(glm::vec2(0.06975647f, 0.99756405f));//86
	positions.push_back(glm::vec2(0.05233596f, 0.99862953f));//87
	positions.push_back(glm::vec2(0.0348995f, 0.99939083));//88
	positions.push_back(glm::vec2(0.01745241f, 0.9998477f));//89
	positions.push_back(glm::vec2(0.0f, 1.0f));//90
	positions.push_back(glm::vec2(-0.01745241f, 0.9998477f));//89
	positions.push_back(glm::vec2(-0.0348995f, 0.99939083));//88
	positions.push_back(glm::vec2(-0.05233596f, 0.99862953f));//87
	positions.push_back(glm::vec2(-0.06975647f, 0.99756405f));//86
	positions.push_back(glm::vec2(-0.08715574f, 0.9961947f));//85
	positions.push_back(glm::vec2(-0.10452846f, 0.9945219f));//84
	positions.push_back(glm::vec2(-0.12186934f, 0.99254615f));//83
	positions.push_back(glm::vec2(-0.1391731f, 0.99026807f));//82
	positions.push_back(glm::vec2(-0.15643447f, 0.98768834f));//81
	positions.push_back(glm::vec2(-0.17364818f, 0.98480775f));//80
	positions.push_back(glm::vec2(-0.190809f, 0.98162718f));//79
	positions.push_back(glm::vec2(-0.20791169f, 0.9781476f));//78
	positions.push_back(glm::vec2(-0.22495105f, 0.97437006f));//77
	positions.push_back(glm::vec2(-0.2419219f, 0.97029573f));//76
	positions.push_back(glm::vec2(-0.25881905f, 0.96592583f));//75
	positions.push_back(glm::vec2(-0.27563736f, 0.9612617f));//74
	positions.push_back(glm::vec2(-0.2923717f, 0.95630476f));//73
	positions.push_back(glm::vec2(-0.30901699f, 0.94551858f));//72														
	positions.push_back(glm::vec2(-0.32556815f, 0.93969262f));//71														
	positions.push_back(glm::vec2(-0.34202014f, 0.93358043f));//70														
	positions.push_back(glm::vec2(-0.35836795f, 0.92718385f));//69														
	positions.push_back(glm::vec2(-0.37460659f, 0.92050485f));//68														
	positions.push_back(glm::vec2(-0.39073113f, 0.91354546f));//67														 
	positions.push_back(glm::vec2(-0.40673664f, 0.90630779f));//66														 
	positions.push_back(glm::vec2(-0.42261826f, 0.89879405f));//65														 
	positions.push_back(glm::vec2(-0.43837115f, 0.89100652f));//64														 
	positions.push_back(glm::vec2(-0.4539905f, 0.88294759f));//63														 
	positions.push_back(glm::vec2(-0.46947156f, 0.87461971f));//62
	positions.push_back(glm::vec2(-0.48480962f, 0.8660254f));//61
	positions.push_back(glm::vec2(-0.5f, 0.8660254f));//60
	positions.push_back(glm::vec2(-0.51503807f, 0.8571673f));//59
	positions.push_back(glm::vec2(-0.52991926f, 0.8480481f));//58
	positions.push_back(glm::vec2(-0.54463904f, 0.83867057f));//57
	positions.push_back(glm::vec2(-0.5591929f, 0.82903757f));//56
	positions.push_back(glm::vec2(-0.57357644f, 0.81915204f));//55
	positions.push_back(glm::vec2(-0.58778525f, 0.80901699f));//54
	positions.push_back(glm::vec2(-0.60181502f, 0.79863551f));//53
	positions.push_back(glm::vec2(-0.61566148f, 0.78801075f));//52
	positions.push_back(glm::vec2(-0.62932039f, 0.77714596f));//51
	positions.push_back(glm::vec2(-0.64278761f, 0.76604444f));//50
	positions.push_back(glm::vec2(-0.65605903f, 0.75470958f));//49														
	positions.push_back(glm::vec2(-0.66913061f, 0.74314483f));//48														 
	positions.push_back(glm::vec2(-0.68199836f, 0.7313537f));//47														 
	positions.push_back(glm::vec2(-0.69465837f, 0.7193398f));//46														 
	positions.push_back(glm::vec2(-0.70710678f, 0.70710678f));//45														 
	positions.push_back(glm::vec2(-0.7193398f, 0.69465837f));//44														 
	positions.push_back(glm::vec2(-0.7313537f, 0.68199836f));//43														 
	positions.push_back(glm::vec2(-0.74314483f, 0.66913061f));//42														 
	positions.push_back(glm::vec2(-0.75470958f, 0.65605903f));//41														 
	positions.push_back(glm::vec2(-0.76604444f, 0.64278761f));//40														 
	positions.push_back(glm::vec2(-0.77714596f, 0.62932039f));//39														 
	positions.push_back(glm::vec2(-0.78801075f, 0.61566148f));//38														 
	positions.push_back(glm::vec2(-0.79863551f, 0.60181502f));//37														 
	positions.push_back(glm::vec2(-0.80901699f, 0.58778525f));//36														 
	positions.push_back(glm::vec2(-0.81915204f, 0.57357644f));//35														 
	positions.push_back(glm::vec2(-0.82903757f, 0.5591929f));//34														 
	positions.push_back(glm::vec2(-0.83867057f, 0.54463904f));//33														 
	positions.push_back(glm::vec2(-0.8480481f, 0.52991926f));//32														 
	positions.push_back(glm::vec2(-0.8571673f, 0.51503807f));//31														 
	positions.push_back(glm::vec2(-0.8660254f, 0.5f));//30	
	positions.push_back(glm::vec2(-0.87461971f, 0.48480962f));//29
	positions.push_back(glm::vec2(-0.88294759f, 0.46947156f));//28														 
	positions.push_back(glm::vec2(-0.89100652f, 0.4539905f));//27														 
	positions.push_back(glm::vec2(-0.89879405f, 0.43837115f));//26														 
	positions.push_back(glm::vec2(-0.90630779f, 0.42261826f));//25														 
	positions.push_back(glm::vec2(-0.91354546f, 0.40673664f));//24														 
	positions.push_back(glm::vec2(-0.92050485f, 0.39073113f));//23														 
	positions.push_back(glm::vec2(-0.92718385f, 0.37460659f));//22														 
	positions.push_back(glm::vec2(-0.93358043f, 0.35836795f));//21														 
	positions.push_back(glm::vec2(-0.93969262f, 0.34202014f));//20														 
	positions.push_back(glm::vec2(-0.94551858f, 0.32556815f));//19														 
	positions.push_back(glm::vec2(-0.95105652f, 0.30901699f));//18														 
	positions.push_back(glm::vec2(-0.95630476f, 0.2923717f));//17														
	positions.push_back(glm::vec2(-0.9612617f, 0.27563736));//16														 
	positions.push_back(glm::vec2(-0.96592583f, 0.25881905f));//15														 
	positions.push_back(glm::vec2(-0.97029573f, 0.2419219f));//14														 
	positions.push_back(glm::vec2(-0.97437006f, 0.22495105f));//13														 
	positions.push_back(glm::vec2(-0.9781476f, 0.20791169f));//12														 
	positions.push_back(glm::vec2(-0.98162718f, 0.190809f));//11														 
	positions.push_back(glm::vec2(-0.98480775f, 0.17364818f));//10														 
	positions.push_back(glm::vec2(-0.98768834f, 0.15643447f));//9														 
	positions.push_back(glm::vec2(-0.99026807f, 0.1391731f));//8														 
	positions.push_back(glm::vec2(-0.99254615f, 0.12186934f));//7														 
	positions.push_back(glm::vec2(-0.9945219f, 0.10452846f));//6														 
	positions.push_back(glm::vec2(-0.9961947f, 0.08715574f));//5														 
	positions.push_back(glm::vec2(-0.99756405f, 0.06975647f));//4														 
	positions.push_back(glm::vec2(-0.998629534755f, 0.052335956243f));//3														 
	positions.push_back(glm::vec2(-0.999390827019f, 0.034899496703f));//2														
	positions.push_back(glm::vec2(-0.999847695156f, 0.017452406437f)); //1																 
	positions.push_back(glm::vec2(-1.0f, 0.0f));
	positions.push_back(glm::vec2(-0.999847695156f, -0.017452406437f)); //1
	positions.push_back(glm::vec2(-0.999390827019f, -0.034899496703f));//2
	positions.push_back(glm::vec2(-0.998629534755f, -0.052335956243f));//3
	positions.push_back(glm::vec2(-0.99756405f, -0.06975647f));//4
	positions.push_back(glm::vec2(-0.9961947f, -0.08715574f));//5
	positions.push_back(glm::vec2(-0.9945219f, -0.10452846f));//6
	positions.push_back(glm::vec2(-0.99254615f, -0.12186934f));//7
	positions.push_back(glm::vec2(-0.99026807f, -0.1391731f));//8
	positions.push_back(glm::vec2(-0.98768834f, -0.15643447f));//9
	positions.push_back(glm::vec2(-0.98480775f, -0.17364818f));//10
	positions.push_back(glm::vec2(-0.98162718f, -0.190809f));//11
	positions.push_back(glm::vec2(-0.9781476f, -0.20791169f));//12
	positions.push_back(glm::vec2(-0.97437006f, -0.22495105f));//13
	positions.push_back(glm::vec2(-0.97029573f, -0.2419219f));//14
	positions.push_back(glm::vec2(-0.96592583f, -0.25881905f));//15
	positions.push_back(glm::vec2(-0.9612617f, -0.27563736));//16
	positions.push_back(glm::vec2(-0.95630476f, -0.2923717f));//17
	positions.push_back(glm::vec2(-0.95105652f, -0.30901699f));//18
	positions.push_back(glm::vec2(-0.94551858f, -0.32556815f));//19
	positions.push_back(glm::vec2(-0.93969262f, -0.34202014f));//20
	positions.push_back(glm::vec2(-0.93358043f, -0.35836795f));//21
	positions.push_back(glm::vec2(-0.92718385f, -0.37460659f));//22
	positions.push_back(glm::vec2(-0.92050485f, -0.39073113f));//23
	positions.push_back(glm::vec2(-0.91354546f, -0.40673664f));//24
	positions.push_back(glm::vec2(-0.90630779f, -0.42261826f));//25
	positions.push_back(glm::vec2(-0.89879405f, -0.43837115f));//26
	positions.push_back(glm::vec2(-0.89100652f, -0.4539905f));//27
	positions.push_back(glm::vec2(-0.88294759f, -0.46947156f));//28
	positions.push_back(glm::vec2(-0.87461971f, -0.48480962f));//29
	positions.push_back(glm::vec2(-0.8660254f, -0.5f));//30
	positions.push_back(glm::vec2(-0.8571673f, -0.51503807f));//31
	positions.push_back(glm::vec2(-0.8480481f, -0.52991926f));//32
	positions.push_back(glm::vec2(-0.83867057f, -0.54463904f));//33
	positions.push_back(glm::vec2(-0.82903757f, -0.5591929f));//34
	positions.push_back(glm::vec2(-0.81915204f, -0.57357644f));//35
	positions.push_back(glm::vec2(-0.80901699f, -0.58778525f));//36
	positions.push_back(glm::vec2(-0.79863551f, -0.60181502f));//37
	positions.push_back(glm::vec2(-0.78801075f, -0.61566148f));//38
	positions.push_back(glm::vec2(-0.77714596f, -0.62932039f));//39
	positions.push_back(glm::vec2(-0.76604444f, -0.64278761f));//40
	positions.push_back(glm::vec2(-0.75470958f, -0.65605903f));//41
	positions.push_back(glm::vec2(-0.74314483f, -0.66913061f));//42
	positions.push_back(glm::vec2(-0.7313537f, -0.68199836f));//43
	positions.push_back(glm::vec2(-0.7193398f, -0.69465837f));//44
	positions.push_back(glm::vec2(-0.70710678f, -0.70710678f));//45
	positions.push_back(glm::vec2(-0.69465837f, -0.7193398f));//46
	positions.push_back(glm::vec2(-0.68199836f, -0.7313537f));//47
	positions.push_back(glm::vec2(-0.66913061f, -0.74314483f));//48
	positions.push_back(glm::vec2(-0.65605903f, -0.75470958f));//49
	positions.push_back(glm::vec2(-0.64278761f, -0.76604444f));//50
	positions.push_back(glm::vec2(-0.62932039f, -0.77714596f));//51
	positions.push_back(glm::vec2(-0.61566148f, -0.78801075f));//52
	positions.push_back(glm::vec2(-0.60181502f, -0.79863551f));//53
	positions.push_back(glm::vec2(-0.58778525f, -0.80901699f));//54
	positions.push_back(glm::vec2(-0.57357644f, -0.81915204f));//55
	positions.push_back(glm::vec2(-0.5591929f, -0.82903757f));//56
	positions.push_back(glm::vec2(-0.54463904f, -0.83867057f));//57
	positions.push_back(glm::vec2(-0.52991926f, -0.8480481f));//58
	positions.push_back(glm::vec2(-0.51503807f, -0.8571673f));//59
	positions.push_back(glm::vec2(-0.5f, -0.8660254f));//60
	positions.push_back(glm::vec2(-0.48480962f, -0.8660254f));//61
	positions.push_back(glm::vec2(-0.46947156f, -0.87461971f));//62
	positions.push_back(glm::vec2(-0.4539905f, -0.88294759f));//63
	positions.push_back(glm::vec2(-0.43837115f, -0.89100652f));//64
	positions.push_back(glm::vec2(-0.42261826f, -0.89879405f));//65
	positions.push_back(glm::vec2(-0.40673664f, -0.90630779f));//66
	positions.push_back(glm::vec2(-0.39073113f, -0.91354546f));//67
	positions.push_back(glm::vec2(-0.37460659f, -0.92050485f));//68
	positions.push_back(glm::vec2(-0.35836795f, -0.92718385f));//69
	positions.push_back(glm::vec2(-0.34202014f, -0.93358043f));//70
	positions.push_back(glm::vec2(-0.32556815f, -0.93969262f));//71
	positions.push_back(glm::vec2(-0.30901699f, -0.94551858f));//72
	positions.push_back(glm::vec2(-0.2923717f, -0.95630476f));//73
	positions.push_back(glm::vec2(-0.27563736f, -0.9612617f));//74
	positions.push_back(glm::vec2(-0.25881905f, -0.96592583f));//75
	positions.push_back(glm::vec2(-0.2419219f, -0.97029573f));//76
	positions.push_back(glm::vec2(-0.22495105f, -0.97437006f));//77
	positions.push_back(glm::vec2(-0.20791169f, -0.9781476f));//78
	positions.push_back(glm::vec2(-0.190809f, -0.98162718f));//79
	positions.push_back(glm::vec2(-0.17364818f, -0.98480775f));//80
	positions.push_back(glm::vec2(-0.15643447f, -0.98768834f));//81
	positions.push_back(glm::vec2(-0.1391731f, -0.99026807f));//82
	positions.push_back(glm::vec2(-0.12186934f, -0.99254615f));//83
	positions.push_back(glm::vec2(-0.10452846f, -0.9945219f));//84
	positions.push_back(glm::vec2(-0.08715574f, -0.9961947f));//85
	positions.push_back(glm::vec2(-0.06975647f, -0.99756405f));//86
	positions.push_back(glm::vec2(-0.05233596f, -0.99862953f));//87
	positions.push_back(glm::vec2(-0.0348995f, -0.99939083));//88
	positions.push_back(glm::vec2(-0.01745241f, -0.9998477f));//89
	positions.push_back(glm::vec2(0.0f, -1.0f));//90
	positions.push_back(glm::vec2(0.01745241f, -0.9998477f));//89
	positions.push_back(glm::vec2(0.0348995f, -0.99939083));//88
	positions.push_back(glm::vec2(0.05233596f, -0.99862953f));//87
	positions.push_back(glm::vec2(0.06975647f, -0.99756405f));//86
	positions.push_back(glm::vec2(0.08715574f, -0.9961947f));//85
	positions.push_back(glm::vec2(0.10452846f, -0.9945219f));//84
	positions.push_back(glm::vec2(0.12186934f, -0.99254615f));//83
	positions.push_back(glm::vec2(0.1391731f, -0.99026807f));//82
	positions.push_back(glm::vec2(0.15643447f, -0.98768834f));//81
	positions.push_back(glm::vec2(0.17364818f, -0.98480775f));//80
	positions.push_back(glm::vec2(0.190809f, -0.98162718f));//79
	positions.push_back(glm::vec2(0.20791169f, -0.9781476f));//78
	positions.push_back(glm::vec2(0.22495105f, -0.97437006f));//77
	positions.push_back(glm::vec2(0.2419219f, -0.97029573f));//76
	positions.push_back(glm::vec2(0.25881905f, -0.96592583f));//75
	positions.push_back(glm::vec2(0.27563736f, -0.9612617f));//74
	positions.push_back(glm::vec2(0.2923717f, -0.95630476f));//73
	positions.push_back(glm::vec2(0.30901699f, -0.94551858f));//72														
	positions.push_back(glm::vec2(0.32556815f, -0.93969262f));//71														
	positions.push_back(glm::vec2(0.34202014f, -0.93358043f));//70														
	positions.push_back(glm::vec2(0.35836795f, -0.92718385f));//69														
	positions.push_back(glm::vec2(0.37460659f, -0.92050485f));//68														
	positions.push_back(glm::vec2(0.39073113f, -0.91354546f));//67														 
	positions.push_back(glm::vec2(0.40673664f, -0.90630779f));//66														 
	positions.push_back(glm::vec2(0.42261826f, -0.89879405f));//65														 
	positions.push_back(glm::vec2(0.43837115f, -0.89100652f));//64														 
	positions.push_back(glm::vec2(0.4539905f, -0.88294759f));//63														 
	positions.push_back(glm::vec2(0.46947156f, -0.87461971f));//62
	positions.push_back(glm::vec2(0.48480962f, -0.8660254f));//61
	positions.push_back(glm::vec2(0.5f, -0.8660254f));//60
	positions.push_back(glm::vec2(0.51503807f, -0.8571673f));//59
	positions.push_back(glm::vec2(0.52991926f, -0.8480481f));//58
	positions.push_back(glm::vec2(0.54463904f, -0.83867057f));//57
	positions.push_back(glm::vec2(0.5591929f, -0.82903757f));//56
	positions.push_back(glm::vec2(0.57357644f, -0.81915204f));//55
	positions.push_back(glm::vec2(0.58778525f, -0.80901699f));//54
	positions.push_back(glm::vec2(0.60181502f, -0.79863551f));//53
	positions.push_back(glm::vec2(0.61566148f, -0.78801075f));//52
	positions.push_back(glm::vec2(0.62932039f, -0.77714596f));//51
	positions.push_back(glm::vec2(0.64278761f, -0.76604444f));//50
	positions.push_back(glm::vec2(0.65605903f, -0.75470958f));//49														
	positions.push_back(glm::vec2(0.66913061f, -0.74314483f));//48														 
	positions.push_back(glm::vec2(0.68199836f, -0.7313537f));//47														 
	positions.push_back(glm::vec2(0.69465837f, -0.7193398f));//46														 
	positions.push_back(glm::vec2(0.70710678f, -0.70710678f));//45														 
	positions.push_back(glm::vec2(0.7193398f, -0.69465837f));//44														 
	positions.push_back(glm::vec2(0.7313537f, -0.68199836f));//43														 
	positions.push_back(glm::vec2(0.74314483f, -0.66913061f));//42														 
	positions.push_back(glm::vec2(0.75470958f, -0.65605903f));//41														 
	positions.push_back(glm::vec2(0.76604444f, -0.64278761f));//40														 
	positions.push_back(glm::vec2(0.77714596f, -0.62932039f));//39														 
	positions.push_back(glm::vec2(0.78801075f, -0.61566148f));//38														 
	positions.push_back(glm::vec2(0.79863551f, -0.60181502f));//37														 
	positions.push_back(glm::vec2(0.80901699f, -0.58778525f));//36														 
	positions.push_back(glm::vec2(0.81915204f, -0.57357644f));//35														 
	positions.push_back(glm::vec2(0.82903757f, -0.5591929f));//34														 
	positions.push_back(glm::vec2(0.83867057f, -0.54463904f));//33														 
	positions.push_back(glm::vec2(0.8480481f, 0-.52991926f));//32														 
	positions.push_back(glm::vec2(0.8571673f, -0.51503807f));//31														 
	positions.push_back(glm::vec2(0.8660254f, -0.5f));//30	
	positions.push_back(glm::vec2(0.87461971f, -0.48480962f));//29
	positions.push_back(glm::vec2(0.88294759f, -0.46947156f));//28														 
	positions.push_back(glm::vec2(0.89100652f, -0.4539905f));//27														 
	positions.push_back(glm::vec2(0.89879405f, -0.43837115f));//26														 
	positions.push_back(glm::vec2(0.90630779f, -0.42261826f));//25														 
	positions.push_back(glm::vec2(0.91354546f, -0.40673664f));//24														 
	positions.push_back(glm::vec2(0.92050485f, -0.39073113f));//23														 
	positions.push_back(glm::vec2(0.92718385f, -0.37460659f));//22														 
	positions.push_back(glm::vec2(0.93358043f, -0.35836795f));//21														 
	positions.push_back(glm::vec2(0.93969262f, -0.34202014f));//20														 
	positions.push_back(glm::vec2(0.94551858f, -0.32556815f));//19														 
	positions.push_back(glm::vec2(0.95105652f, -0.30901699f));//18														 
	positions.push_back(glm::vec2(0.95630476f, -0.2923717f));//17														
	positions.push_back(glm::vec2(0.9612617f, -0.27563736));//16														 
	positions.push_back(glm::vec2(0.96592583f, -0.25881905f));//15														 
	positions.push_back(glm::vec2(0.97029573f, -0.2419219f));//14														 
	positions.push_back(glm::vec2(0.97437006f, -0.22495105f));//13														 
	positions.push_back(glm::vec2(0.9781476f, -0.20791169f));//12														 
	positions.push_back(glm::vec2(0.98162718f, -0.190809f));//11														 
	positions.push_back(glm::vec2(0.98480775f, -0.17364818f));//10														 
	positions.push_back(glm::vec2(0.98768834f, -0.15643447f));//9														 
	positions.push_back(glm::vec2(0.99026807f, -0.1391731f));//8														 
	positions.push_back(glm::vec2(0.99254615f, -0.12186934f));//7														 
	positions.push_back(glm::vec2(0.9945219f, -0.10452846f));//6														 
	positions.push_back(glm::vec2(0.9961947f, -0.08715574f));//5														 
	positions.push_back(glm::vec2(0.99756405f, -0.06975647f));//4														 
	positions.push_back(glm::vec2(0.998629534755f, -0.052335956243f));//3														 
	positions.push_back(glm::vec2(0.999390827019f, -0.034899496703f));//2														
	positions.push_back(glm::vec2(0.999847695156f, -0.017452406437f)); //1
	positions.push_back(glm::vec2(1.0f, 0.0f));
																	 
																	 
																	 //rreglo de colores en el cpu

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
	
	
	

	
	//queremos generar 1 manager
	glGenVertexArrays(1, &vao);
	//utilizar el vao. a partir de este momento, todos los VBOs creados y configurados
	//se van a asociar
	glBindVertexArray(vao);


	//identificador de vbo de posiciones
	GLuint positionsVBO;


	//creacion del vbo de posiciones
	glGenBuffers(1, &positionsVBO);
	//ACTIVAMOS EL BUFFER DE POSICIONES PARA PODER UTILIZARO
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//Creamos la memoria y la inicializamos con os datos del atributo de posiciones
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//activamos el atributo en la tarjeta de video
	glEnableVertexAttribArray(0);
	//configuramo los atributos de la tarjeta de video
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//Ya no vamos a utilizar ese VBO en este momento
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//desactivamos el manager
	glBindVertexArray(0);
	//creamos un objeto para leer archivos de texto
	Inputfile ifile;
	//vertex shader
	ifile.Read("Default.vert"
	);
	//obtenemos el codigo fuente y lo guardamos en un string
	std::string vertexSource = ifile.GetContents();
	//creamos un shader de tipo vertex, guardamos su identificador en una variable
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	//obtener losd atos en el formato correcto
	const GLchar*vertexSource_c = (const GLchar*)vertexSource.c_str();
	//le estamos dando el codigo fuente a opengl para que se lo asigne al shader
	glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr);
	//compilamos el shader en busca de errores
	//vamos a asumir que no hay ningun error(osea no vamso a comprobar el estatus de compilacion)
	glCompileShader(vertexShaderHandle);

	ifile.Read("Default.frag");
	std::string fragmentSource = ifile.GetContents();
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar *fragmentSource_c = (const GLchar*)fragmentSource.c_str();
	glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
	glCompileShader(fragmentShaderHandle);

	//creamos el identificador para el manager de los shaders
	shaderProgram = glCreateProgram();
	//adjutamos el vertex shader al manager (van a trabajar juntos)
	glAttachShader(shaderProgram, vertexShaderHandle);
	// adjutamos el fragment shader al manager (van a trabajar juntos)
	glAttachShader(shaderProgram, fragmentShaderHandle);
	//asociamos un buffer con indice 0 (posiciones) a la variable VertexPosition
	glBindAttribLocation(shaderProgram, 0, "VertexPosition");
	//asociamos un buffer con indice 1 (colores) a la variable VertexColor
	glBindAttribLocation(shaderProgram, 1, "VertexColor");
	//ejecutamos el proceso de linker (aseguramos que el vertex y el fragment son compatibles)
	glLinkProgram(shaderProgram);
}
void GameLoop()
{
	//limpiamos el buffer de color y el de profundidad
	//siempre hacero al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Activamos el vertex shader y el fragment shader utilizando el manager
	glUseProgram(shaderProgram);

	//activamos el manager, en este momento se activa todos los Vbos asociados automaticamente
	glBindVertexArray(vao);
	//fundion de dibujado sin indices
	glDrawArrays(GL_TRIANGLE_FAN, 0, 364);
	//terminamos de utilizar el manager
	glBindVertexArray(0);
	//desactivamos el manager
	glUseProgram(0);

	//cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	//solicitando una version especifica de OpenGL.
	glutInitContextVersion(4, 5);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicación
	// gráfica.
	// En este caso estamos trabajando con el pipeline clásico.
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un título.
	glutCreateWindow("Hello World GL");
	// Asociamos una función de render. Esta función se mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);

	// Inicializar GLEW. Esta librería se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	
	
	//configuracion inicial de uestro programa.
	Initialize();

	// Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}
