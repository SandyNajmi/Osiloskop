// Osiloskop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "glut.h"
#include "cstdlib"
#include "math.h"

typedef struct{
	float x;
	float y;
} point2D_t;

typedef struct
{
	float r;
	float g;
	float b;
}color_t;

void setColor(color_t col)
{
	glColor3f(col.r, col.g, col.b);
}

static int tick = 0;

void drawPolyline(point2D_t p[], int n){
	int i;
	glBegin(GL_LINE_STRIP);
	for (i = 0; i<n; i++){
		glVertex2f(p[i].x, p[i].y);
	}
	glEnd();
}

void drawLine(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(1000, timer, 90);
}


void userdraw(void){

	//Garis Kotak-kotak Biru
	//glColor3f(0, 0, 1);
	//for (float x = 0; x <= 360; x += 10)
		//drawLine(x, -1.1, x, 1.1);
	//for (float y = -1.1; y<1.1; y += 0.1)
		//drawLine(0, y, 360, y);

	glColor3f(0, 1, 1);
	drawLine(0, 0, 360, 0);
	drawLine(0, -1.1, 0, 1.1);

	point2D_t p[360];
	glColor3f(0, 0, 1);
	for (int i = 0; i<360; i++){
		p[i].x = (float)i;
		p[i].y = (float)sin(((float)i) * 16 / 57.3+tick)*(1 + 0.5*sin((float)i * 4 / 57.3));
	}
	drawPolyline(p, 360);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	userdraw();
	tick++;
	glutSwapBuffers();
	glutTimerFunc(1000, timer, 0);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(740, 580);
	glutCreateWindow("Seria Reni | 2110151027");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//gluOrtho2D(-1.,1.,-1.,1.);
	gluOrtho2D(0., 360., -1.1, 1.1);
	
	glutIdleFunc(display);
	glutTimerFunc(100000, timer, 0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}