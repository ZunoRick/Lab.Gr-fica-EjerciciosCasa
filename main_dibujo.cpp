//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Zuno Sánchez Ricardo					******//
//*************	Práctica #2								******//
//*************	Visual Studio 2017						******//
//************************************************************//
#include "Main.h"
void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	
	//Gorra:
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(106.0f, -78.0f, 0.0f);
	glVertex3f(106.0f, -60.0f, 0.0f);
	glVertex3f(124.0f, -60.0f, 0.0f);
	glVertex3f(124.0f, -42.0f, 0.0f);
	glVertex3f(211.0f, -42.0f, 0.0f);
	glVertex3f(211.0f, -60.0f, 0.0f);
	glVertex3f(265.0f, -60.0f, 0.0f);
	glVertex3f(265.0f, -78.0f, 0.0f);
	glVertex3f(106.0f, -78.0f, 0.0f);
	glEnd();

	//Manga derecha:
	glBegin(GL_QUADS);
	glVertex3f(282.0f, -78.0f, 0.0f);
	glVertex3f(282.0f, -132.0f, 0.0f);
	glVertex3f(300.0f, -132.0f, 0.0f);
	glVertex3f(300.0f, -78.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(282.0f, -78.0f, 0.0f);
	glVertex3f(282.0f, -114.0f, 0.0f);
	glVertex3f(247.0f, -114.0f, 0.0f);
	glVertex3f(247.0f, -78.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(265.0f, -132.0f, 0.0f);
	glVertex3f(282.0f, -132.0f, 0.0f);
	glVertex3f(282.0f, -168.0f, 0.0f);
	glVertex3f(265.0f, -168.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(246.0f, -150.0f, 0.0f);
	glVertex3f(246.0f, -168.0f, 0.0f);
	glVertex3f(265.0f, -168.0f, 0.0f);
	glVertex3f(265.0f, -150.0f, 0.0f);
	glEnd();

	//Manga izquierda
	glBegin(GL_QUADS);
	glVertex3f(70.0f, -168.0f, 0.0f);
	glVertex3f(142.0f, -168.0f, 0.0f);
	glVertex3f(142.0f, -204.0f, 0.0f);
	glVertex3f(70.0f, -204.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(142.0f, -186.0f, 0.0f);
	glVertex3f(158.0f, -186.0f, 0.0f);
	glVertex3f(158.0f, -224.0f, 0.0f);
	glVertex3f(142.0f, -224.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(158.0f, -204.0f, 0.0f);
	glVertex3f(158.0f, -224.0f, 0.0f);
	glVertex3f(106.0f, -224.0f, 0.0f);	
	glVertex3f(106.0f, -204.0f, 0.0f);
	glEnd();

	//Cabello:
	glColor3f(0.301f, 0.152f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(106.0f, -78.0f, 0.0f);
	glVertex3f(106.0f, -96.0f, 0.0f);
	glVertex3f(124.0f, -96.0f, 0.0f);
	glVertex3f(124.0f, -78.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(124.0f, -78.0f, 0.0f);
	glVertex3f(124.0f, -132.0f, 0.0f);
	glVertex3f(141.0f, -132.0f, 0.0f);
	glVertex3f(141.0f, -78.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(141.0f, -78.0f, 0.0f);
	glVertex3f(159.0f, -78.0f, 0.0f);
	glVertex3f(159.0f, -96.0f, 0.0f);
	glVertex3f(141.0f, -96.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(141.0f, -132.0f, 0.0f);
	glVertex3f(159.0f, -132.0f, 0.0f);
	glVertex3f(159.0f, -115.0f, 0.0f);
	glVertex3f(141.0f, -115.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(88.0f, -96.0f, 0.0f);
	glVertex3f(106.0f, -96.0f, 0.0f);
	glVertex3f(106.0f, -150.0f, 0.0f);
	glVertex3f(88.0f, -150.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(88.0f, -150.0f, 0.0f);
	glVertex3f(123.0f, -150.0f, 0.0f);
	glVertex3f(123.0f, -132.0f, 0.0f);
	glVertex3f(88.0f, -132.0f, 0.0f); 
	glEnd();

	//Ojo:
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(193.0f, -78.0f, 0.0f);
	glVertex3f(193.0f, -114.0f, 0.0f);
	glVertex3f(212.0f, -114.0f, 0.0f);
	glVertex3f(212.0f, -78.0f, 0.0f);
	glEnd();

	//Bigote
	glBegin(GL_POLYGON);
	glVertex3f(193.0f, -132.0f, 0.0f);
	glVertex3f(193.0f, -150.0f, 0.0f);
	glVertex3f(265.0f, -150.0f, 0.0f);
	glVertex3f(265.0f, -132.0f, 0.0f); 
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(212.0f, -114.0f, 0.0f);
	glVertex3f(230.0f, -114.0f, 0.0f);
	glVertex3f(230.0f, -132.0f, 0.0f);
	glVertex3f(212.0f, -132.0f, 0.0f);
	glEnd();

	//Oreja:
	glColor3f(1.0f, 0.729f, 0.505f);
	glBegin(GL_QUADS);
	glVertex3f(106.0f, -96.0f, 0.0f);
	glVertex3f(106.0f, -132.0f, 0.0f);
	glVertex3f(124.0f, -132.0f, 0.0f);
	glVertex3f(124.0f, -96.0f, 0.0f);
	glEnd();
	
	//Mano1:
	glBegin(GL_QUADS);
	glVertex3f(265.0f, -78.0f, 0.0f);
	glVertex3f(301.0f, -78.0f, 0.0f);
	glVertex3f(301.0f, -60.0f, 0.0f);
	glVertex3f(265.0f, -60.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(247.0f, -60.0f, 0.0f);
	glVertex3f(301.0f, -60.0f, 0.0f);	
	glVertex3f(301.0f, -42.0f, 0.0f);
	glVertex3f(247.0f, -42.0f, 0.0f);
	glEnd();

	//Mano 2
	/*glBegin(GL_QUADS);
	glVertex3f(18.0f, -60.0f, 0.0f);
	glVertex3f(301.0f, -60.0f, 0.0f);
	glVertex3f(301.0f, -42.0f, 0.0f);
	glVertex3f(247.0f, -42.0f, 0.0f);
	glEnd();*/

	//Cara:
	glBegin(GL_QUADS);
	glVertex3f(141.0f, -96.0f, 0.0f);
	glVertex3f(159.0f, -96.0f, 0.0f);
	glVertex3f(159.0f, -115.0f, 0.0f);
	glVertex3f(141.0f, -115.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(212.0f, -114.0f, 0.0f);
	glVertex3f(193.0f, -114.0f, 0.0f);
	glVertex3f(193.0f, -132.0f, 0.0f);
	glVertex3f(212.0f, -132.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(159.0f, -78.0f, 0.0f);
	glVertex3f(194.0f, -78.0f, 0.0f);
	glVertex3f(194.0f, -168.0f, 0.0f);
	glVertex3f(159.0f, -168.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(123.0f, -168.0f, 0.0f);
	glVertex3f(123.0f, -132.0f, 0.0f);
	glVertex3f(193.0f, -132.0f, 0.0f);
	glVertex3f(193.0f, -168.0f, 0.0f); 
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(193.0f, -150.0f, 0.0f);
	glVertex3f(246.0f, -150.0f, 0.0f);
	glVertex3f(246.0f, -168.0f, 0.0f);
	glVertex3f(193.0f, -168.0f, 0.0f);
	glEnd(); 

	//Nariz:
	glBegin(GL_QUADS);
	glVertex3f(212.0f, -78.0f, 0.0f);
	glVertex3f(230.0f, -78.0f, 0.0f);
	glVertex3f(230.0f, -114.0f, 0.0f);
	glVertex3f(212.0f, -114.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(230.0f, -97.0f, 0.0f);
	glVertex3f(265.0f, -97.0f, 0.0f);
	glVertex3f(265.0f, -114.0f, 0.0f);
	glVertex3f(230.0f, -114.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(230.0f, -132.0f, 0.0f);
	glVertex3f(230.0f, -114.0f, 0.0f);
	glVertex3f(282.0f, -114.0f, 0.0f);
	glVertex3f(282.0f, -132.0f, 0.0f);
	glEnd();

	//zap der
	glColor3f(0.301f, 0.152f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(282.0f, -259.0f, 0.0f);
	glVertex3f(318.0f, -259.0f, 0.0f);
	glVertex3f(318.0f, -168.0f, 0.0f);
	glVertex3f(300.0f, -168.0f, 0.0f);
	glVertex3f(300.0f, -186.0f, 0.0f);	
	glVertex3f(282.0f, -186.0f, 0.0f);
	glVertex3f(282.0f, -259.0f, 0.0f);
	glEnd();

	//zap izq
	glBegin(GL_QUADS);
	glVertex3f(71.0f, -295.0f, 0.0f);
	glVertex3f(106.0f, -295.0f, 0.0f);
	glVertex3f(106.0f, -259.0f, 0.0f);
	glVertex3f(71.0f, -259.0f, 0.0f);
	glVertex3f(71.0f, -295.0f, 0.0f);
	glEnd();

	glFlush();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(0, 350, -300, 0, -1, 2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitWindowSize(800, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 2"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutMainLoop();          // 

	return 0;
}

