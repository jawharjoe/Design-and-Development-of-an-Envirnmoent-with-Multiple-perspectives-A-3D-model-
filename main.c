#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
float angle = 0.0f;
float lx=0.0f,lz=-1.0f, ly = 0.0f;
float x=0.0f, z=5.0f, y = 1.75f;
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;
int h,w;
int frame;
long time, timebase;
char s[50];
int mainWindow, subWindow1,subWindow2,subWindow3;
int border = 6;
void init();
void setProjection(int w1, int h1)
{
	float ratio;
	ratio = 1.0f * w1 / h1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
        glViewport(0, 0, w1, h1);
	gluPerspective(45,ratio,0.1,1000);
	glMatrixMode(GL_MODELVIEW);
}

void changeSize(int w1,int h1) {

	if(h1 == 0)
		h1 = 1;
	w = w1;
	h = h1;
	glutSetWindow(subWindow1);
	glutPositionWindow(border,border);
	glutReshapeWindow(w-2*border, h/2 - border*3/2);
	setProjection(w-2*border, h/2 - border*3/2);
	glutSetWindow(subWindow2);
	glutPositionWindow(border,(h+border)/2);
	glutReshapeWindow(w/2-border*3/2, h/2 - border*3/2);
	setProjection(w/2-border*3/2,h/2 - border*3/2);
	glutSetWindow(subWindow3);
	glutPositionWindow((w+border)/2,(h+border)/2);
	glutReshapeWindow(w/2-border*3/2,h/2 - border*3/2);
	setProjection(w/2-border*3/2,h/2 - border*3/2);
}

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();
	glColor3f(1.0f, 0.5f, 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
	glColor3f(1.0f, 1.0f, 1.0f);

}
void box(){
 glTranslatef(1.5f, 0.0f, -7.0f);

   glBegin(GL_QUADS);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
      glColor3f(1.0f, 0.5f, 0.0f);
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();
}
void pyramid(){
glTranslatef(-1.5f, 0.0f, -6.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glColor3f(1.0f,0.0f,0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);
      glVertex3f(-1.0f,-1.0f, 1.0f);
      glEnd();
}

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	glLoadIdentity();

	gluOrtho2D(0, w, h, 0);

	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}


void renderScene2() {



	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	int i,j;
	for(i=-3;i<3;i++)
		for(j=-3;j<3;j++)
		{
			glPushMatrix();
			glTranslatef(i*10.0f, 0.0f, j * 10.0f);
           drawSnowMan();
			glPopMatrix();
		}
}


void renderScene() {
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}


void renderScenesw1() {

	glutSetWindow(subWindow1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z,
		  x + lx,y + ly,z + lz,
		  0.0f,1.0f,0.0f);
	renderScene2();
 	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"PPES - FPS:%4.2f",
			frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(5,30,0,GLUT_BITMAP_HELVETICA_12,s);
	glPopMatrix();

	restorePerspectiveProjection();

	glutSwapBuffers();
}

void renderScenesw2() {

	glutSetWindow(subWindow2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y+15, z,
		  x ,y - 1,z,
		  lx,0,lz);

	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();
	renderScene2();
	glutSwapBuffers();
}


void renderScenesw3() {

	glutSetWindow(subWindow3);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x-lz*10 , y, z+lx*10,
		  x ,y ,z ,
		  0.0f,1.0f,0.0f);
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();
	renderScene2();
	glutSwapBuffers();
}


void renderSceneAll() {


	if (deltaMove) {
		computePos(deltaMove);
		glutSetWindow(mainWindow);
		glutPostRedisplay();
	}

	renderScene();
	renderScenesw1();
	renderScenesw2();
	renderScenesw3();
}

void rS2() {



	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	int i,j;
	for(i = -3; i < 3; i++)
		for(j=-3; j < 3; j++)
		{
			glPushMatrix();
			glTranslatef(i*10.0f, 0.0f, j * 10.0f);
            box();
			glPopMatrix();
		}
}


void rS() {
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}


void rSw1() {

	glutSetWindow(subWindow1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z,
		  x + lx,y + ly,z + lz,
		  0.0f,1.0f,0.0f);
	rS2();
 	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"PPES - FPS:%4.2f",
			frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(5,30,0,GLUT_BITMAP_HELVETICA_12,s);
	glPopMatrix();

	restorePerspectiveProjection();

	glutSwapBuffers();
}

void rSw2() {

	glutSetWindow(subWindow2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y+15, z,
		  x ,y - 1,z,
		  lx,0,lz);

	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();
	rS2();
	glutSwapBuffers();
}


void rSw3() {

	glutSetWindow(subWindow3);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x-lz*10 , y, z+lx*10,
		  x ,y ,z ,
		  0.0f,1.0f,0.0f);
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();
	rS2();
	glutSwapBuffers();
}


void rSA() {


	if (deltaMove) {
		computePos(deltaMove);
		glutSetWindow(mainWindow);
		glutPostRedisplay();
	}

	rS();
	rSw1();
	rSw2();
	rSw3();
}

void reSe2() {



	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	int i,j;
	for(i = -3; i < 3; i++)
		for(j=-3; j < 3; j++)
		{
			glPushMatrix();
			glTranslatef(i*10.0f, 0.0f, j * 10.0f);
            pyramid();
			glPopMatrix();
		}
}


void reSe() {
	glutSetWindow(mainWindow);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}


void reSew1() {

	glutSetWindow(subWindow1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z,
		  x + lx,y + ly,z + lz,
		  0.0f,1.0f,0.0f);
	reSe2();
 	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"PPES - FPS:%4.2f",
			frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}
	setOrthographicProjection();
	glPushMatrix();
	glLoadIdentity();
	renderBitmapString(5,30,0,GLUT_BITMAP_HELVETICA_12,s);
	glPopMatrix();

	restorePerspectiveProjection();

	glutSwapBuffers();
}

void reSew2() {

	glutSetWindow(subWindow2);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y+15, z,
		  x ,y - 1,z,
		  lx,0,lz);

	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();
	reSe2();
	glutSwapBuffers();
}


void reSew3() {

	glutSetWindow(subWindow3);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x-lz*10 , y, z+lx*10,
		  x ,y ,z ,
		  0.0f,1.0f,0.0f);
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(x,y,z);
	glRotatef(180-(angle+deltaAngle)*180.0/3.14,0.0,1.0,0.0);
	glutSolidCone(0.2,0.8f,4,4);
	glPopMatrix();
	reSe2();
	glutSwapBuffers();
}


void reSeA() {


	if (deltaMove) {
		computePos(deltaMove);
		glutSetWindow(mainWindow);
		glutPostRedisplay();
	}

	reSe();
	reSew1();
	reSew2();
	reSew3();
}



void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
	}
	glutSetWindow(mainWindow);
	glutPostRedisplay();

}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}



void mouseMove(int x, int y) {


	if (xOrigin >= 0) {

		deltaAngle = (x - xOrigin) * 0.001f;


		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);

		glutSetWindow(mainWindow);
		glutPostRedisplay();
	}
}

void mouseButton(int button, int state, int x, int y) {


	if (button == GLUT_LEFT_BUTTON) {


		if (state == GLUT_UP) {
			angle += deltaAngle;
			deltaAngle = 0.0f;
			xOrigin = -1;
		}
		else  {
			xOrigin = x;

		}
	}
}
void processNormalKeys(unsigned char key, int xx, int yy) {

	if (key == 98) {
		rSA();
		init();
		}
	else if(key == 112){
	   reSeA();
	   init();
	}

		else if(key == 115){
	   renderSceneAll();
	}
	
	if (key==27)
		exit(0);
}
void init() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
}

void sub(){
	subWindow1 = glutCreateSubWindow(mainWindow, border,border,w-2*border, h/2 - border*3/2);
	glutDisplayFunc(renderScenesw1);
	init();

	subWindow2 = glutCreateSubWindow(mainWindow, border,(h+border)/2,w/2-border*3/2, h/2 - border*3/2);
	glutDisplayFunc(renderScenesw2);
	init();

	subWindow3 = glutCreateSubWindow(mainWindow, (w+border)/2,(h+border)/2,w/2-border*3/2,h/2 - border*3/2);
	glutDisplayFunc(renderScenesw3);
	init();
}
void sub1(){
  mainWindow = glutCreateWindow("PPES");
	subWindow1 = glutCreateSubWindow(mainWindow, border,border,w-2*border, h/2 - border*3/2);
	glutDisplayFunc(rSw1);
	init();

	subWindow2 = glutCreateSubWindow(mainWindow, border,(h+border)/2,w/2-border*3/2, h/2 - border*3/2);
	glutDisplayFunc(rSw2);
	init();

	subWindow3 = glutCreateSubWindow(mainWindow, (w+border)/2,(h+border)/2,w/2-border*3/2,h/2 - border*3/2);
	glutDisplayFunc(rSw3);
	init();
}

void sub2(){
  mainWindow = glutCreateWindow("PPES");
	subWindow1 = glutCreateSubWindow(mainWindow, border,border,w-2*border, h/2 - border*3/2);
	glutDisplayFunc(reSew1);
	init();

	subWindow2 = glutCreateSubWindow(mainWindow, border,(h+border)/2,w/2-border*3/2, h/2 - border*3/2);
	glutDisplayFunc(reSew2);
	init();

	subWindow3 = glutCreateSubWindow(mainWindow, (w+border)/2,(h+border)/2,w/2-border*3/2,h/2 - border*3/2);
	glutDisplayFunc(reSew3);
	init();
}



int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	mainWindow = glutCreateWindow("PPES");
	glutDisplayFunc(renderSceneAll);
	glutReshapeFunc(changeSize);
	init();
        sub();
	glutMainLoop();

	return 1;
}
