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
Transform _transform2;
Transform _transform3;
Transform _transform4;
Transform _transform5;
Camera _camera;

void Initialize()
{
	// Creando toda la memoria que el programa va a utilizar.

	// Creación del atributo de posiciones de los vértices.
	// Lista de vec2
	// Claramente en el CPU y RAM
	std::vector<glm::vec3> positions;
	std::vector<unsigned int> indices = {
		0,  2,  1,  0,  3,  2,   //base
		0,  3,  4,  0,  4,  3,   //front
		3,  2,  4, 3,  4, 2,  //right
		2, 1, 4, 2, 4, 1,  //back
		1, 0, 1, 1, 4, 0,  //left

	};
							
	//base				
	positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));//0
	positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));//1
	positions.push_back(glm::vec3(1.0f,-1.0f, -1.0f));//2
	positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));//3

    //front
	positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//4
	


											   // Arreglo de colores en el cpu
	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //0
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));//1
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));//2
	colors.push_back(glm::vec3(0.0f, 0.0f, 0.0f));//3
	
	colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));//4
	
	_mesh.CreateMesh(5);

	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetIndices(indices, GL_STATIC_DRAW);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();
	
	_transform2.SetScale(0.5f, 0.5f, 0.5f);
	//_transform.SetRotation(90.0f, 90.0f, 90.0f);

	//_transform.Translate(40.0f, 6.0f, -21.0f, false);
	//_transform2.Translate(-20.0f, 6.0f, 30.0f, false);
	_transform.SetScale(3.0f,3.0f,3.0f);
	//_transform2.SetScale(0.5f, 0.5f, 0.5f);

	//_transform.SetPosition(0.0f, 0.0f, 0.0f);


	_camera.SetPosition(0.0f, 0.0f, 25.0f);
	//_camera.MoveForward(60.0f);
	


}

void GameLoop()
{
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	

	_transform.Rotate(1.0f, 1.0f, 1.0f, true);
	_transform2.Rotate(-1.0f, -1.0f, -1.0f, false);

	float i = 0.0f;
	float r = 5.0f;
	float tetha = glm::radians(i), x = r*(glm::cos(tetha)), y = r* (glm::sin(tetha)), z = 0.0f;

	_transform.SetPosition(x, y, z);
	i = i + 1.0f;
	
	//_transform2.SetScale(1.0f, 1.0f, 1.0f);
	
	float s = 0.5f;
	
	_transform2.SetScale(s, s, s);

	if (s < 1.0f) {
		s = s + 1.0f;
		_transform2.SetScale(s, s, s);
	}
	else
	{
		s = s - 1.0f;
		_transform2.SetScale(s, s, s);
	}
	
	
	//activar shader
	_shaderProgram.Activate();
	//mandar informacion al shader
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*_transform.GetModelMatrix());
	//dibujamos
	_mesh.Draw(GL_TRIANGLES);

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()*_transform2.GetModelMatrix());
	_mesh.Draw(GL_TRIANGLES);

	
	
//borramos el mesh
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
	// Solicitando una versión específica de OpenGL.
	glutInitContextVersion(4, 4);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicación
	// gráfica.
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
	// Creamos la ventana y le damos un título.
	glutCreateWindow("Hello World GL");
	// Asociamos una función de render.
	//Esta función se mandará a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librería se encarga de obtener el API de OpenGL de
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
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configuración inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicación. El main se pausará en esta línea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}