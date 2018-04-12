//
// 50.017 Graphics and Visualization Project
// Janine Liao and Mauritz Zachrisson
//

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <GLUT/glut.h>
#include "tree.h"

using namespace std;

GLuint makeaTree;
float height = 0.5;
float base = 0.15;

void init()
{
	srand(time(NULL));
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
}

void display(){
	glClearColor(1.0,1.0,1.0,1.0);
	glClearDepth(10);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glCallList(makeaTree);

	glPopMatrix();
	glutSwapBuffers();
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (GLfloat) w / (GLfloat) h, 0.001, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, -8.0, -50.0);
}

void stepSystem(float height) {
	makeaTree = glGenLists(1);
	glNewList(makeaTree, GL_COMPILE);

	srand(1);
	makeTree(height, base);

	glEndList();
}

void timerFunc(int t)
{
	stepSystem(height);
	height += 0.008;
	base += 0.00025;

	glutTimerFunc(t, &timerFunc, t);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("50.017 GnV Project");
	init();
	glutReshapeFunc(reshape);

	glutDisplayFunc(display);

	// Trigger timerFunc every 20 msec
	stepSystem(height);
	glutTimerFunc(20, timerFunc, 20);
	glutMainLoop();
	return 0;
}