#include<iostream>
#include<GL/glut.h>
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>
#include<GL/freeglut.h>
#include<stdlib.h>
using namespace std;


void display(void);
void display1();
int flag=0;
 void frontscreen(void)
{
 	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(35,90);
	glColor3f(0,0,1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"PESIT BANGALORE SOUTH CAMPUS");
	glRasterPos2i(30,82);
	glColor3f(1,0.5,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glRasterPos2i(38,70);
	glColor3f(1,0,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"A MINI PROJECT ON ");
	glRasterPos2i(33,60);
	glColor3f(1,0.5,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"PERCEIVING PERSPECTIVES OF AN ENVIRONMENT");
	glRasterPos2i(10,34);
	glColor3f(0.5,0,0.5);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"BY ");
	glRasterPos2i(10,29);
	glColor3f(0,0,1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"Mohammed Jawhar			1PE14CS074");
	glRasterPos2i(10,25);
	glColor3f(0,0,1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"Mohinish Reddy 		1PE14CS075");
	
	glRasterPos2i(50,15);
	glColor3f(0,0,1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"PRESS ENTER TO CONTINUE");
	
	glRasterPos2i(50,7);
	glColor3f(0,0,1);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)"PRESS ESC TO EXIT");
	

}

void myKeyboardFunc( unsigned char key, int x, int y )

{
 switch(key)
 {
 	case 13:if(flag==0) //Ascii of 'enter' key is 13
    		flag=1;
 		 break;
 	case 27:if(flag==0||flag==1)
 			flag=2;
 		 break;
 }
 display();
}

void display(void)
{
 	glClear(GL_COLOR_BUFFER_BIT);
 	if(flag==0)
 	{
		 frontscreen();
		 glFlush();
	}
		
 	if(flag==1)
 	{
  		system("g++ main.c -lGL -lGLU -lglut -o main");
  		system("./main");
 	}

 	if(flag==2)
 		exit(0);
}

/*
void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2i(38,70);
	glColor3f(1,0,0);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)" ~~~***UNDERCONSTRUCTION***~~~ ");
	glFlush();
	
}
*/

void myinit()
{
    	glClearColor(0,0,0,1);
    	glColor3f(1,0,0);
    	glPointSize(1.0);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluOrtho2D(0,99,0,99);
}
int main(int argc,char **argv)
{

    	glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    	glutInitWindowSize(1000,2000);
    	glutInitWindowPosition(0,0);
    	glutCreateWindow("front page");
    	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboardFunc);
   	 myinit();
    	glutMainLoop();
    	return 0;
}



