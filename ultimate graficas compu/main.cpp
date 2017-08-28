#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

//identificador del manager al que vamos a asociar todos los VBOs
GLuint vao;

void Initialize() 
{

	//creando la memoria que el programa va a utilizar

	//creacion del atributo de posiciones de los vertices
	//lista de vec2
	//claramente en el cpu y ram
	
	std::vector<glm::vec2> positions;
	
	positions.push_back(glm::vec2(-0.5f, -0.5f));
	positions.push_back(glm::vec2(0.5f, -.5f));
	positions.push_back(glm::vec2(-0.5f, .5f));
	positions.push_back(glm::vec2(0.5f, 0.5f));
	
	
	

	
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
	//desactivamos el manager
	glBindVertexArray(0);
}
void GameLoop()
{
	//limpiamos el buffer de color y el de profundidad
	//siempre hacero al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//activamos el manager, en este momento se activa todos los Vbos asociados automaticamente
	glBindVertexArray(vao);
	//fundion de dibujado sin indices
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//terminamos de utilizar el manager
	glBindVertexArray(0);
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