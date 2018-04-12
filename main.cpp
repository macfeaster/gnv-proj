#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;
#include <GLUT/glut.h>
#include "tree.h"

GLuint makeaTree;

void init()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	makeaTree=glGenLists(1);
	glNewList(makeaTree, GL_COMPILE);
	makeTree(4,0.2);
	glEndList();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glCallList(makeaTree);

	glPopMatrix();
	glutSwapBuffers();
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
	glutMainLoop();
	return 0;
}