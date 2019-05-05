//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Zuno Sánchez Ricardo*********************************//
//*************	Práctica 10	ejercicio de casa		******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

//#include "cmodel/CModel.h"


//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera;
GLfloat g_lookupdown = 0.0f; 
float rotX = 0.0, rotY = 0.0, rotZ = 0.0, movX = 0.0, movY = 0.0, movZ = 0.0;
bool dia = true;

								//Luz Ambiente (Cielo)
GLfloat LightAmbient[] = { 1.0f, 0.819f, 0.698f, 1.0f };
GLfloat LightDiffuse[] = { 0.949f, 0.988f, 1.0f, 1.0f };
GLfloat LightSpecular[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat LightPosition[] = { -80.0, 145.0, 0.0, 1.0f };

GLfloat LightAmbient2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat LightDiffuse2[] = { 0.788f, 0.886f, 1.0f, 1.0f };
GLfloat LightSpecular2[] = { 0.5, 0.5, 0.5, 0.0 };
//GLfloat LightPosition2[] = { 0.0f, 100.0f, 0.0f, 0.0f };

//Propiedades de tubos
GLfloat TuboAmbient[] = { 0.19225f, 0.19225f, 0.19225f, 1.0f };
GLfloat TuboDiffuse[] = { 0.50754f, 0.50754f, 0.50754f, 1.0f };
GLfloat TuboSpecular[] = { 0.508273f, 0.508273f, 0.508273f, 1.0f };
GLfloat TuboShininess[] = { 51.2f };

GLfloat TuboAmbient2[] = { 0.736f, 0.557f, 0.163f, 1.0f };
GLfloat TuboDiffuse2[] = { 0.898f, 0.666f, 0.156, 1.0f };
GLfloat TuboSpecular2[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat TuboShininess2[] = { 70.0f };

GLfloat materialAmbient[] = { 0.470f, 0.341f, 0.180f, 1.0f }; 
GLfloat materialDiffuse[] = { 0.736f, 0.557f, 0.163f, 1.0f };
GLfloat matSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat matShininess[] = { 90.0f };

CTexture text1;
CTexture pasto;

CFiguras escenario;
CFiguras Cilindro;
CFiguras cuadroSoporte;
CFiguras suelo;


//Figuras de 3D Studio


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);

	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On

	text1.LoadBMP("forest3.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	pasto.LoadTGA("pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	//Carga de Figuras

	objCamera.Position_Camera(0, 2.5f, 1, 0, 2.5f, 0, 0, 1, 0);
	objCamera.mPos.y = -100;
	objCamera.mView.y = -60;
	objCamera.mPos.z = -200;
	//objCamera.mView.z= -60;
}

void tubo(float diametro, float largo) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, TuboAmbient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, TuboSpecular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, TuboDiffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, TuboShininess);
	Cilindro.cilindro(diametro, largo, 20, 0);
}

void rielCentral(float largo) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, TuboAmbient2);
	glMaterialfv(GL_FRONT, GL_SPECULAR, TuboSpecular2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, TuboDiffuse2);
	glMaterialfv(GL_FRONT, GL_SHININESS, TuboShininess2);
	Cilindro.cilindro(2.0, largo, 20, 0);
}

void soporteDeRielCentral(float altura, float largo, float profundidad, GLuint text) {
	glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, materialDiffuse);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
	cuadroSoporte.prisma3(altura, largo, profundidad, text);
}

void tuboCodo() {
	//Inicia curva arriba
	glPushMatrix();
		glTranslatef(0, 0, 2);
		glPushMatrix();
			glRotatef(87, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0, 1);

		glPushMatrix();
			glRotatef(82, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.1, 1);

		glPushMatrix();
			glRotatef(79, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.2, 1);

		glPushMatrix();
			glRotatef(74, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.3, 1);

		glPushMatrix();
			glRotatef(71, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.3, 1);

		glPushMatrix();
			glRotatef(68, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.4, 1);

		glPushMatrix();
			glRotatef(63, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.5, 1);

		glPushMatrix();
			glRotatef(59, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.6, 1);

		glPushMatrix();
			glRotatef(56, 1, 0, 0);
			tubo(1.0, 1.2);
		glPopMatrix();

		glTranslatef(0, 0.7, 1);

		glPushMatrix();
			glRotatef(53, 1, 0, 0);
			tubo(1.0, 1.3);
		glPopMatrix();

		glTranslatef(0, 0.8, 1);

		glPushMatrix();
			glRotatef(50, 1, 0, 0);
			tubo(1.0, 1.3);
		glPopMatrix();
	glPopMatrix();  //Termina curva arriba
}

void ambiente() {

	//Pasto:
	glPushMatrix();
		glTranslatef(0.0, -180.0, 150.0);
		glScalef(400, 0.01, 80);
		suelo.prisma2(pasto.GLindex, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, -180.0, -150.0);
		glScalef(400, 0.01, 80);
		suelo.prisma2(pasto.GLindex, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-150.0, -180.0, 0.0);
		glScalef(100, 0.01, 220);
		suelo.prisma2(pasto.GLindex, 0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(150.0, -180.0, 0.0);
		glScalef(100, 0.01, 220);
		suelo.prisma2(pasto.GLindex, 0);
	glPopMatrix();
}

void riel() {
	glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);

		glPushMatrix();
			/*glTranslatef(movX, movY, movZ);
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);*/
			//tubo(1.0, 1.0);

			//Riel 1-derecha
			glPushMatrix();
				glTranslatef(80, -90, -9.5);
				glRotatef(90, 1, 0, 0);
				tubo(1.0, 50.0);
			glPopMatrix();

			glTranslatef(80, -90, 38);

			tuboCodo();

			glTranslatef(0, 4, 12);

			glPushMatrix();
				glRotatef(47, 1, 0, 0);
				tubo(1.0, 5.0);
			glPopMatrix();

			glTranslatef(0, 3, 3);

			glPushMatrix();
				glRotatef(40, 1, 0, 0);
				tubo(1.0, 40.0);
			glPopMatrix();

			glTranslatef(0, 30, 20);

			//Inicia curva arriba
			glPushMatrix();
				glTranslatef(0, 0, 5);
				glRotatef(180, 0, 0, 1);
				glRotatef(40, 1, 0, 0);
				glPushMatrix();
					glRotatef(87, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0, 1);

				glPushMatrix();
					glRotatef(82, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.1, 1);

				glPushMatrix();
					glRotatef(79, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.2, 1);

				glPushMatrix();
					glRotatef(74, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.3, 1);

				glPushMatrix();
					glRotatef(71, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.3, 1);

				glPushMatrix();
					glRotatef(68, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.4, 1);

				glPushMatrix();
					glRotatef(63, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.5, 1);

				glPushMatrix();
					glRotatef(59, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.6, 1);

				glPushMatrix();
					glRotatef(56, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.7, 1);

				glPushMatrix();
					glRotatef(53, 1, 0, 0);
					tubo(1.0, 1.3);
				glPopMatrix();

				glTranslatef(0, 0.8, 1);

				glPushMatrix();
					glRotatef(50, 1, 0, 0);
					tubo(1.0, 1.3);
				glPopMatrix();
			glPopMatrix();  //Termina curva arriba

			glTranslatef(0, 3.5, 16);

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				tubo(1.0, 2.0);
			glPopMatrix();

			glTranslatef(0, 0, 2);

			//Inicia curva arriba
			glPushMatrix();
				glRotatef(180, 0, 0, 1);
				glPushMatrix();
					glRotatef(87, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0, 1);

				glPushMatrix();
					glRotatef(82, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.1, 1);

				glPushMatrix();
					glRotatef(79, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.2, 1);

				glPushMatrix();
					glRotatef(74, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.3, 1);

				glPushMatrix();
					glRotatef(71, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.3, 1);

				glPushMatrix();
					glRotatef(68, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.4, 1);

				glPushMatrix();
					glRotatef(63, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.5, 1);

				glPushMatrix();
					glRotatef(59, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.6, 1);

				glPushMatrix();
					glRotatef(56, 1, 0, 0);
					tubo(1.0, 1.2);
				glPopMatrix();

				glTranslatef(0, 0.7, 1);

				glPushMatrix();
					glRotatef(53, 1, 0, 0);
					tubo(1.0, 1.3);
				glPopMatrix();

				glTranslatef(0, 0.8, 1);

				glPushMatrix();
					glRotatef(50, 1, 0, 0);
					tubo(1.0, 1.3);
				glPopMatrix();
			glPopMatrix();  //Termina curva arriba

			glTranslatef(0, -10, 16);

			glPushMatrix();
				glRotatef(-44, 1, 0, 0);
				tubo(1.0, 8.0);
			glPopMatrix();

			glTranslatef(0, 2, -2);

			glPushMatrix();
				glRotatef(43, 1, 0, 0);
				tuboCodo();
			glPopMatrix();

			glTranslatef(0, -5.5, 12);

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				tubo(1.0, 17.0);
			glPopMatrix();

			glTranslatef(0, 0, 17);

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				tubo(1.0, 3.0);
			glPopMatrix();

			glTranslatef(0, 0, 3);

			glPushMatrix();
			glRotatef(90, 1, 0, 0);
			tubo(1.0, 3.0);
			glPopMatrix();

		glPopMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
	glPopMatrix();

}

void radioInt() {
	glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(80, -63, 140);
		glPushMatrix();
			/*glTranslatef(movX, movY, movZ);
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);*/

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				glRotatef(rotZ, 0, 0, 1);
				tubo(1.0, 5.0);
			glPopMatrix();

		glPopMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
	glPopMatrix();
}

void radioExt(){
	glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(80, -63, 140);
		glPushMatrix();
			/*glTranslatef(movX, movY, movZ);
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);*/

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				glRotatef(-4, 0, 0, 1);
				tubo(1.0, 5.0);
			glPopMatrix();

		glPopMatrix();
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
	glPopMatrix();

}

void rielCentro() {
	glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);

		glPushMatrix();
			//glTranslatef(0, movY, 0.0);
			/*glTranslatef(movX, movY, movZ);
			glRotatef(rotX, 1, 0, 0);
			glRotatef(rotY, 0, 1, 0);
			glRotatef(rotZ, 0, 0, 1);*/
		
			glPushMatrix();
				glTranslatef(80, -94, -9.5);
				glRotatef(90, 1, 0, 0);
				rielCentral(50.0);
			glPopMatrix();

			glTranslatef(80, -94, 40);

			//Codo riel central
			glPushMatrix();
				glRotatef(85, 1, 0, 0);
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 0.1, 2);
			glRotatef(80, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 2, 0);
			glRotatef(-8, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 2, 0);
			glRotatef(-8, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 2, 0);
			glRotatef(0, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 2, 0);
			glRotatef(-2, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 2, 0);
			glRotatef(-7, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix();

			glTranslatef(0, 2, 0);
			glRotatef(-4, 1, 0, 0);

			glPushMatrix();
				rielCentral(2.0);
			glPopMatrix(); 
			//Fin del codo riel central

			glTranslatef(0, 2, 0);

			glPushMatrix();
				glRotatef(-10, 1, 0, 0);
				rielCentral(15.0);
			glPopMatrix();

			glTranslatef(0, 14, -2.5);

			glPushMatrix();
				glRotatef(-12, 1, 0, 0);
				rielCentral(22.0);
			glPopMatrix();

		glPopMatrix();

		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
	glPopMatrix();
}

void montanaR() {
	glPushMatrix();
		glTranslatef(0.0, 0.0, -30.0);
		riel();
		radioExt();
		glTranslatef(10.0, 0.0, 0.0);
		riel();
		radioInt();
		glTranslatef(-5.0, 0.0, 0.0);
		rielCentro();
	glPopMatrix();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);

	glPushMatrix();
		glRotatef(g_lookupdown, 1.0f, 0, 0);
		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

		if (dia) {
			glDisable(GL_LIGHT1);
			glEnable(GL_LIGHT0);
			
		}
		else {
			glDisable(GL_LIGHT0);
			glEnable(GL_LIGHT1);
		}

		//Fuente de luz
		glPushMatrix();
			glDisable(GL_TEXTURE_2D);
			glTranslatef(-80.0, 145.0, 0.0);
			glColor3f(1.0, 0.6354, 0.3684);
			glutSolidSphere(5, 20, 20);
			glEnable(GL_TEXTURE_2D);
			glColor3f(1, 1, 1);
		glPopMatrix();

		glPushMatrix(); //Creamos cielo
			glTranslatef(0, 30, 0);
			escenario.skybox(400.0, 400.0, 400.0, text1.GLindex);
			ambiente();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			montanaR();
		glPopMatrix();

		glTranslatef(104, -63, 111);
		glPushMatrix();
		glRotatef(90, 1, 0, 0);
		glutSolidTorus(5, 19, 2, 30);

		glPopMatrix();

		//glEnable(GL_COLOR_MATERIAL);
	
	glPopMatrix();
	glutSwapBuffers();
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

	glFrustum(-0.5, 0.5, -0.5, 0.5, 0.5, 670.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.01);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.01));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.01));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.01);
		break;

	case 'j':
		rotX += 1.0;
		printf("rotX = %f\n", rotX);
		break;
	case 'J':
		rotX -= 1.0;
		printf("rotX = %f\n", rotX);
		break;

	case 'k':
		rotY += 1.0;
		printf("rotY = %f\n", rotY);
		break;
	case 'K':
		rotY -= 1.0;
		printf("rotY = %f\n", rotY);
		break;

	case 'l':
		rotZ += 1.0;
		printf("rotZ = %f\n", rotZ);
		break;
	case 'L':
		rotZ -= 1.0;
		printf("rotZ = %f\n", rotZ);
		break;

	case 'i':
		movX += 1.0;
		printf("movX = %f\n", movX);
		break;
	case 'I':
		movX -= 1.0;
		printf("movX = %f\n", movX);
		break;

	case 'o':
		movY += 1.0;
		printf("movY = %f\n", movY);
		break;
	case 'O':
		movY -= 1.0;
		printf("movY = %f\n", movY);
		break;

	case 'p':
		movZ += 1.0;
		printf("movZ = %f\n", movZ);
		break;
	case 'P':
		movZ -= 1.0;
		printf("movZ = %f\n", movZ);
		break;

	case 'f':
		dia = true;
		break;
	case 'F':
		dia = false;
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
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
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
	glutInitWindowSize(700, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Final"); // Nombre de la Ventana
										//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}