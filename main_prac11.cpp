//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Zuno Sánchez Ricardo *********************************//
//*************	 Práctica #11										******//
//*************	 Visual Studio 2017										******//
//***Instrucciones: tecla L,l inicia la animación*****//
//************************************************************//
#include "Main.h"
#include <string.h>

#define MAX_FRAMES 5
char path[] = "archivo.txt";
int i_max_steps = 1500;
int i_curr_steps = 0;

float transZ = -5.0f;
float transX = -5.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angCodo = 0.0;
float angMu = 0.0;
float angPu = 0.0;
float angIn = 0.0;
float angMed = 0.0;
float angAn = 0.0;
float angMen = 0.0;

typedef struct mano {
	float angPu;
	float angIn;
	float angMed;
	float angAn; 
	float angMen;

	float angPuInc;
	float angInInc;
	float angMedInc;
	float angAnInc;
	float angMenInc;
}MANO;

MANO KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	for (int i = 0; i < MAX_FRAMES; i++){
		KeyFrame[i].angAn = 0;
		KeyFrame[i].angAnInc = 0;
		KeyFrame[i].angIn = 0;
		KeyFrame[i].angInInc = 0;
		KeyFrame[i].angMed = 0;
		KeyFrame[i].angMedInc = 0;
		KeyFrame[i].angMen = 0;
		KeyFrame[i].angMenInc = 0;
		KeyFrame[i].angPu = 0;
		KeyFrame[i].angPuInc = 0;
	}
}

void leerArchivo(char path[]) {
	FILE *archivo;

	archivo = fopen(path, "r");

	if (archivo != NULL) {
		while (!feof(archivo) && FrameIndex < MAX_FRAMES) {
			fscanf(archivo, "%f\n", &angPu);
			fscanf(archivo, "%f\n", &angIn);
			fscanf(archivo, "%f\n", &angMed);
			fscanf(archivo, "%f\n", &angAn);
			fscanf(archivo, "%f\n", &angMen);

			KeyFrame[FrameIndex].angPu = angPu;
			KeyFrame[FrameIndex].angIn = angIn;
			KeyFrame[FrameIndex].angMed = angMed;
			KeyFrame[FrameIndex].angAn = angAn;
			KeyFrame[FrameIndex].angMen = angMen;
			printf("frameindex %d\n", FrameIndex);
			FrameIndex++;
		}
	}
	fclose(archivo);
	printf("Cierre archivo %d  ", FrameIndex);
}

void saveFrames(){
	if (FrameIndex < MAX_FRAMES) {
		leerArchivo(path);

		printf("Total de frames: %d\n", FrameIndex);
		for (int i = 0; i < FrameIndex; i++) {
			printf("%d %f\n", i, KeyFrame[i].angPu);
			printf("%d %f\n", i, KeyFrame[i].angIn);
			printf("%d %f\n", i, KeyFrame[i].angMed);
			printf("%d %f\n", i, KeyFrame[i].angAn);
			printf("%d %f\n", i, KeyFrame[i].angMen);
		}
	}
}

void resetElements() {
	angPu = KeyFrame[0].angPu;
	angIn = KeyFrame[0].angIn;
	angMed = KeyFrame[0].angMed;
	angAn = KeyFrame[0].angAn;
	angMen = KeyFrame[0].angMen;
}

void interpolation() {
	KeyFrame[playIndex].angPuInc = (KeyFrame[playIndex + 1].angPu - KeyFrame[playIndex].angPu) / i_max_steps;
	KeyFrame[playIndex].angInInc = (KeyFrame[playIndex + 1].angIn - KeyFrame[playIndex].angIn) / i_max_steps;
	KeyFrame[playIndex].angMedInc = (KeyFrame[playIndex + 1].angMed - KeyFrame[playIndex].angMed) / i_max_steps;
	KeyFrame[playIndex].angAnInc = (KeyFrame[playIndex + 1].angAn - KeyFrame[playIndex].angAn) / i_max_steps;
	KeyFrame[playIndex].angMenInc = (KeyFrame[playIndex + 1].angMen - KeyFrame[playIndex].angMen) / i_max_steps;
}

void animacion() {
	if (play) {
		if (i_curr_steps >= i_max_steps){
			playIndex++;
			if (playIndex > FrameIndex - 2){
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else {
			angPu += KeyFrame[playIndex].angPuInc;
			angIn += KeyFrame[playIndex].angInInc;
			angMed += KeyFrame[playIndex].angMedInc;
			angAn += KeyFrame[playIndex].angAnInc;
			angMen += KeyFrame[playIndex].angMenInc;
			i_curr_steps++;
		}
	}
	glutPostRedisplay();
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.
	glPushMatrix();
	//brazo
	glPushMatrix();
	//comienza a dibujar el hombro
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	//glScalef();
	prisma();
	glPopMatrix();
	glTranslatef(1.5, 0.0, 0.0);
	//bicep
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(2.0, 1.0, 1.0);
	prisma();
	glPopMatrix();
	glTranslatef(1, 0, 0);
	glRotatef(angCodo, 0, 1, 0); //articulacion codo
	glTranslatef(1, 0, 0);

	//antebrazo
	glPushMatrix();
	glColor3f(0, 0, 1);
	glScalef(2, 1, 1);
	prisma();
	glPopMatrix();
	glTranslatef(1, 0, 0);
	glRotatef(angMu, 0, 1, 0); //articulacion muñeca
	glTranslatef(0.5, 0, 0);

	//Palma
	glPushMatrix();
	glColor3f(0, 1, 1);
	glScalef(1, 1, 0.5);
	prisma();
	glPopMatrix();

	//PULGAR
	glPushMatrix();
	glTranslatef(-0.4, 0.5, 0);
	glRotatef(angPu, 1, 0, 0);
	glTranslatef(0, 0.1, 0);
	//falange 1
	glPushMatrix();
	glColor3f(0.5, 0.4, 0.7);
	glScalef(0.2, 0.2, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0, 0.1, 0);
	glRotatef(angPu*0.3f, 1, 0, 0);
	glTranslatef(0, 0.1, 0);
	//falange 2
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.3);
	glScalef(0.2, 0.2, 0.2);
	prisma();
	glPopMatrix();
	glPopMatrix();

	//indice
	glPushMatrix();
	glTranslatef(0.5, 0.45, 0);
	glRotatef(angIn, 0, 1, 0);
	glTranslatef(0.15, 0.0, 0);
	//falange 1
	glPushMatrix();
	glColor3f(0.9, 0.7, 0.1);
	glScalef(0.3, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.15, 0, 0);
	glRotatef(angIn*0.3f, 0, 1, 0);
	glTranslatef(0.15, 0, 0);
	//falange 2
	glPushMatrix();
	glColor3f(0.54, 0.214, 0.172);
	glScalef(0.3, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.15, 0, 0);
	glRotatef(angIn*0.6f, 0, 1, 0);
	glTranslatef(0.15, 0, 0);
	//falange 3
	glPushMatrix();
	glColor3f(0.481, 0.985, 0.15);
	glScalef(0.3, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glPopMatrix();

	//Medio
	glPushMatrix();
	glTranslatef(0.5, 0.22, 0);
	glRotatef(angMed, 0, 1, 0);
	glTranslatef(0.2, 0.0, 0);
	//falange 1
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(0.4, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0);
	glRotatef(angMed*0.3f, 0, 1, 0);
	glTranslatef(0.2, 0.0, 0);
	//falange 2
	glPushMatrix();
	glColor3f(0, 0, 1);
	glScalef(0.4, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0);
	glRotatef(angMed*0.6f, 0, 1, 0);
	glTranslatef(0.2, 0.0, 0);
	//falange 3
	glPushMatrix();
	glColor3f(1.0, 0.509, 0.0);
	glScalef(0.4, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glPopMatrix();

	//Anular
	glPushMatrix();
	glTranslatef(0.5, -0.02, 0);
	glRotatef(angAn, 0, 1, 0);
	glTranslatef(0.15, 0, 0);
	//falange 1
	glPushMatrix();
	glColor3f(0.349, 0.047, 0.909);
	glScalef(0.3, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.15, 0, 0);
	glRotatef(angAn*0.3f, 0, 1, 0);
	glTranslatef(0.15, 0, 0);
	//falange 2
	glPushMatrix();
	glColor3f(1.0, 0.397, 0.0);
	glScalef(0.3, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.15, 0, 0);
	glRotatef(angAn*0.6f, 0, 1, 0);
	glTranslatef(0.15, 0, 0);
	//falange 3
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.462);
	glScalef(0.3, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glPopMatrix();

	//Meñique
	glPushMatrix();
	glTranslatef(0.5, -0.26, 0);
	glRotatef(angMen, 0, 1, 0);
	glTranslatef(0.05, 0, 0);
	//falange 1
	glPushMatrix();
	glColor3f(0.525, 0.772, 0.172);
	glScalef(0.1, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.05, 0, 0);
	glRotatef(angMen*0.3f, 0, 1, 0);
	glTranslatef(0.05, 0, 0);
	//falange 2
	glPushMatrix();
	glColor3f(0.698, 0, 0.121);
	glScalef(0.1, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glTranslatef(0.05, 0, 0);
	glRotatef(angMen*0.6f, 0, 1, 0);
	glTranslatef(0.05, 0, 0);
	//Falange 3
	glPushMatrix();
	glColor3f(0.054, 0.556, 0.729);
	glScalef(0.1, 0.12, 0.2);
	prisma();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
	// Swap The Buffers
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

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'l':
	case 'L':
		leerArchivo(path);
		if (play == false && (FrameIndex > 1))
		{
			resetElements();			
			interpolation();
			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;

	case 'p':
		if (angMen <= 90)
			angMen += 0.8f;
			printf("%f\n", angMen);
		break;
	case 'P':
		if (angMen >= 0)
			angMen -= 0.8f;
			printf("%f\n", angMen);
		break;
	case 'o':
		if (angAn <= 90)
			angAn += 0.8f;
			printf("%f\n", angAn);
		break;
	case 'O':
		if (angAn >= 0)
			angAn -= 0.8f;
			printf("%f\n", angAn);
		break;
	case 'i':
		if (angMed <= 90)
			angMed += 0.8f;
			printf("%f\n", angMed);
		break;
	case 'I':
		if (angMed >= 0)
			angMed -= 0.8f;
			printf("%f\n", angMed);
		break;
	case 'u':
		if (angIn <= 90)
			angIn += 0.8f;
			printf("%f\n", angIn);
		break;
	case 'U':
		if (angIn >= 0)
			angIn -= 0.8f;
			printf("%f\n", angIn);
		break;
	case 'y':
		if (angPu >= -90)
			angPu -= 0.8f;
			printf("%f\n", angPu);
		break;
	case 'Y':
		if (angPu <= 0)
			angPu += 0.8f;
			printf("%f\n", angPu);
		break;
	case 't':
		if (angMu <= 85)
			angMu += 0.8f;
		break;
	case 'T':
		if (angMu >= 0)
			angMu -= 0.8f;
		break;
	case 'r':
		if (angCodo <= 130)
			angCodo += 0.8f;
		break;
	case 'R':
		if (angCodo >= 0)
			angCodo -= 0.8f;
		break;
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 
	return 0;
}

