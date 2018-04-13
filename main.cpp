//
// 50.017 Graphics and Visualization Project
// Janine Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include "tree.h"

using namespace std;

GLuint cmdList;
float height = 0.5;
float base = 0.15;
int iterations = 0;

// Most of this file is just OpenGL boilerplate cobbled together
// from the assignments as well as StackOverflow.
// See tree.cpp for the actual recursive tree code.

void init()
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST | GL_DEPTH | GL_LIGHTING);
}

void display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClearDepth(10);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotatef(0.0, 1.0, 0.0, 0.0);
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glCallList(cmdList);

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
	glTranslatef(0, -8.0f, -50.0f);
}

void stepSystem(float height) {
	cmdList = glGenLists(1);
	glNewList(cmdList, GL_COMPILE);

	makeTree(height, base, 1, 8);

	glEndList();
}

void timerFunc(int t)
{
	stepSystem(height);
	height += 0.008;
	base += 0.00025;

	iterations++;

	// After 500 size increases, we've reached our target tree size
	if (iterations < 500)
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
    
    // Depth and Lighting
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    
    GLfloat lightPos[] = {0.0, 0.0, 15.0};
    GLfloat greenColor[] = {0.42, 0.56, 0.14};
    
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,greenColor);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,greenColor);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,greenColor);
    glLightfv(GL_LIGHT0,GL_SPECULAR,greenColor);
    
    // Trigger timerFunc every 20 msec
    stepSystem(height);
    glutTimerFunc(20, timerFunc, 20);
    glutMainLoop();
    return 0;
}
