//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Zuno Sánchez Ricardo *********************************//
//*************	Práctica #6										******//
//*************	Visual Studio 2017										******//
//*************	Instrucciones: tecla w desplaza al frente	******//
//*************	Tecla s: desplaza hacia atrás ******//
//*************	Tecla d: desplaza a la derecha ******//
//*************	Tecla a: desplaza a la izquierda ******//
//*************	Tecla flecha derecha: rotacion positiva respecto al eje Y ******//
//*************	Tecla flecha izquierda: rotacion negativa respecto al eje Y ******//
//*************	Tecla flecha arriba: rotacion positiva respecto al eje X ******//
//*************	Tecla flecha abajo: rotacion negativa respecto al eje X ******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
float camaraZ = 0.0;
float camaraX = 0.0;
float rotY = 0.0;
float rotX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX-0,0.0,-50.0+camaraZ);			//camara
	glRotatef(rotY, 0, 1, 0);
	glRotatef(rotX, 0, 0, 1);

	//Sol
	glPushMatrix();
		glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
		glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
		glutSolidSphere(15,25,25);  //Draw Sun (radio,H,V);
	glPopMatrix();

	//Mercurio
	
	glPushMatrix();
		glRotatef(-sol, 0, 1, 0);
		glTranslatef(22.0, 0.0, 0.0);
		glRotatef(sol, 0.0, 1.0, 0.0);	
		glColor3f(0.909, 0.333, 0.047);	
		glutSolidSphere(0.5, 25, 25);  
	glPopMatrix();

	//Venus
	glPushMatrix();
		glRotatef(-venus, 0, 1, 0);
		glTranslatef(40.0, 0.0, 0.0);	
		glRotatef(venus, 0.0, 1.0, 0.0);
		glColor3f(1.0, 0.788, 0.101);
		glutSolidSphere(1.5, 25, 25);
	glPopMatrix();
	
	//Tierra
	glPushMatrix();
		glRotatef(-tierra, 0, 1, 0);
		glTranslatef(70.0, 0.0, 0.0);
		glRotatef(-tierra, 0.0, 1.0, 1.0);
		glColor3f(0.0, 1.0, 0.741);
		glutSolidSphere(4.5, 25, 25);

		glPushMatrix();
			glTranslatef(10.0, 0.0, 0.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.5, 25, 25);
		glPopMatrix();
	glPopMatrix();

	//Marte
	glPushMatrix();
		glRotatef(-marte, 0, 1, 0);
		glTranslatef(135.0, 0.0, 0.0);
		glRotatef(-marte, 1.0, 1.0, 0.0);
		glColor3f(1.0, 0.0, 0.0);
		glutSolidSphere(8.0, 25, 25);

		glPushMatrix();
			glTranslatef(10.0, 0.0, 0.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.3, 6, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 0.0, 13.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.5, 3, 10);
		glPopMatrix();
	glPopMatrix();

	//Jupiter
	glPushMatrix();
		glRotatef(-jupiter, 0, 1, 0);
		glTranslatef(190.0, 0.0, 0.0);
		glRotatef(-jupiter, 0.0, 1.0, 0.0);
		glColor3f(0.811, 0.537, 0.305);
		glutSolidSphere(10.0, 25, 25);

		glPushMatrix();
			glTranslatef(11.0, 0.0, 0.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.3, 6, 15);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(11.0, 4.0, 1.0);
			glRotatef(luna, 0.0, 1.0, 1.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.5, 13, 9);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-11.0, -6.0, 3.0);
			glRotatef(luna, 0.0, 1.0, 1.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.7, 13, 9);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-5.0, 3.5, -12.0);
			glRotatef(luna, 0.0, 1.0, 1.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.2, 13, 9);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-4.5, 2.5, 10.0);
			glRotatef(luna, 0.0, 1.0, 1.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.45, 13, 9);
		glPopMatrix();
	glPopMatrix();

	//Saturno
	glPushMatrix();
		glRotatef(-saturno, 0, 1, 0);
		glTranslatef(260.0, 0.0, 0.0);
		glRotatef(-saturno, 0.0, 1.0, 0.0);
		glColor3f(0.984, 0.615, 0.282);
		glutSolidSphere(13.0, 25, 25);

		//Anillos
		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glRotatef(-45, 1, 0, 0);
			glColor3f(0.984, 0.850, 0.701);
			glutSolidTorus(3, 18, 2, 30);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glRotatef(-45, 1, 0, 0);
			glColor3f(0.909, 0.8, 0.670);
			glutSolidTorus(1, 23, 2, 30);
		glPopMatrix();

		//Lunas
		glPushMatrix();
			glRotatef(-luna, 0.0, 1.0, 0.0);
			glTranslatef(13.0, 3.0, 5.0);
			glRotatef(-luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.3, 20, 15);
		glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 0.0);
			glTranslatef(13.0, -4.0, -5.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.4, 20, 15);
		glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 0.0);
			glTranslatef(-15.0, -6.0, 0.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.5, 20, 15);
		glPopMatrix();
	glPopMatrix();

	//Urano
	glPushMatrix();
		glRotatef(-saturno, 0, 1, 0);
		glTranslatef(100.0, 0.0, -250.0);
		glRotatef(-saturno, 1.0, 0.0, 0.0);
		glColor3f(0.372, 0.596, 0.909);
		glutSolidSphere(7.0, 25, 25);

		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glRotatef(90, 0, 1, 0);
			glColor3f(0.219, 0.352, 0.541);
			glutSolidTorus(1, 20, 2, 30);
		glPopMatrix();

		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 0.0);
			glTranslatef(10.0, -4.0, 5.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.4, 20, 15);
		glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 0.0, 1.0);
			glTranslatef(7.0, 4.0, -5.0);
			glRotatef(luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.4, 20, 15);
		glPopMatrix();
		glPushMatrix();
			glRotatef(-luna, 1.0, 0.0, 0.0);
			glTranslatef(8.0, -4.0, -5.0);
			glRotatef(-luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.5, 20, 15);
		glPopMatrix();
	glPopMatrix();

	//Neptuno
	glPushMatrix();
		glRotatef(-saturno, 0, 1, 0);
		glTranslatef(200.0, 0.0, 200.0);
		glRotatef(-saturno, 1.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		glutSolidSphere(5.0, 25, 25);

		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glRotatef(45, 0, 0, 1);
			glColor3f(0.541, 0.149, 0.188);
			glutSolidTorus(0.2, 9, 2, 30);
		glPopMatrix();
			glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			glRotatef(45, 0, 0, 1);
			glColor3f(0.541, 0.149, 0.188);
			glutSolidTorus(0.2, 10, 2, 30);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-luna, 1.0, 0.0, 0.0);
			glTranslatef(6.0, -2.0, -1.5);
			glRotatef(-luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.3, 20, 10);
		glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 0.0);
			glTranslatef(-7.0, 3.0, -1.5);
			glRotatef(-luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.3, 24, 15);
		glPopMatrix();
		glPushMatrix();
			glRotatef(luna, 0.0, 1.0, 0.0);
			glTranslatef(5.0, 1.0, 3.55);
			glRotatef(-luna, 0.0, 1.0, 0.0);
			glColor3f(0.643, 0.294, 0.650);
			glutSolidSphere(0.2, 14, 15);
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 35)
	{
		sol = (sol - 10) % 360;
		venus = (venus - 9) % 360;
		tierra = (tierra - 5) % 360;
		luna = (luna - 4) % 360;
		marte = (marte - 3) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		rotY += 1.5;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		rotY -= 1.5;
		break;
	case GLUT_KEY_LEFT:
		rotX += 1.5;
		break;
	case GLUT_KEY_RIGHT:
		rotX -= 1.5;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}