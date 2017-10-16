#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include "Camera.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform;
Camera _camera;

void Initialize()
{
	// Creando toda la memoria que el programa va a utilizar.

	// Creaci�n del atributo de posiciones de los v�rtices.
	// Lista de vec2
	// Claramente en el CPU y RAM
	std::vector<glm::vec3> positions;
	std::vector<unsigned int> indices ={
		0,  1,  2,  0,  2,  3,   //front
		4,  6,  5,  4,  7,  6,   //right
		8,  10,  9, 8,  11, 10,  //back
		12, 13, 14, 12, 14, 15,  //left
		16, 18, 17, 16, 19, 18,  //up
		20, 21, 22, 20, 22, 23 }; //bottom

							
	//front					
	positions.push_back(glm::vec3(-6.0f, -6.0f, 6.0f));//0
	positions.push_back(glm::vec3(6.0f, -6.0f, 6.0f));//1
	positions.push_back(glm::vec3(6.0f, 6.0f, 6.0f));//2
	positions.push_back(glm::vec3(-6.0f, 6.0f, 6.0f));//3

    //right
	positions.push_back(glm::vec3(6.0f, 6.0f, 6.0f));//4
	positions.push_back(glm::vec3(6.0f, 6.0f, -6.0f));//5
	positions.push_back(glm::vec3(6.0f, -6.0f, -6.0f));//6
	positions.push_back(glm::vec3(6.0f, -6.0f, 6.0f));//7
	
	//back
	positions.push_back(glm::vec3(-6.0f, -6.0f, -6.0f));//8
	positions.push_back(glm::vec3(6.0f, -6.0f, -6.0f));//9
	positions.push_back(glm::vec3(6.0f, 6.0f, -6.0f));//10
	positions.push_back(glm::vec3( - 6.0f, 6.0f, -6.0f));//11

	//left
	positions.push_back(glm::vec3(-6.0f, -6.0f, -6.0f));//12
	positions.push_back(glm::vec3(-6.0f, -6.0f, 6.0f));//13
	positions.push_back(glm::vec3(-6.0f, 6.0f, 6.0f));//14
	positions.push_back(glm::vec3(-6.0f, 6.0f, -6.0f));//15

// up
	positions.push_back(glm::vec3(6.0f, 6.0f, 6.0f));//16
	positions.push_back(glm::vec3(-6.0f, 6.0f, 6.0f));//17
	positions.push_back(glm::vec3(-6.0f, 6.0f, -6.0f));//18
	positions.push_back(glm::vec3(6.0f, 6.0f, -6.0f));//19

	//bottom
	positions.push_back(glm::vec3(-6.0f, -6.0f, -6.0f));//20
	positions.push_back(glm::vec3(6.0f, -6.0f, -6.0f));//21
	positions.push_back(glm::vec3(6.0f, -6.0f, 6.0f));//22
	positions.push_back(glm::vec3(-6.0f, -6.0f, 6.0f));//23



											   // Arreglo de colores en el cpu
	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //0
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));//1
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));//2
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));//3
	
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//4
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//5
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//6
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//7
	
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));//8
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));//9
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));//10
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));//11
	
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f)); //12
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));//13
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));//14
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));//15
	
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));//16
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));//17
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));//18
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));//19
	
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));//20
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));//21
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));//22
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));//23

	_mesh.CreateMesh(24);

	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();

	_transform.SetRotation(90.0f, 90.0f, 90.0f);

	_camera.MoveForward(25.0f);

}

void GameLoop()
{
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//_camera.MoveForward(.01f);

	_transform.Rotate(0.0f, 1.0f, 0.5f, false);

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*_transform.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();

	// Cuando terminamos de renderear, cambiamos los buffers.
	glutSwapBuffers();
}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	// Solicitando una versi�n espec�fica de OpenGL.
	glutInitContextVersion(4, 4);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicaci�n
	// gr�fica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un t�tulo.
	glutCreateWindow("Hello World GL");
	// Asociamos una funci�n de render.
	//Esta funci�n se mandar� a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una funci�n para el cambio de resoluci�n
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tama�o de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la funci�n que se mandar� a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librer�a se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometr�as.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configuraci�n inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicaci�n. El main se pausar� en esta l�nea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}