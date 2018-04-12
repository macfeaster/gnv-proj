//
// 50.017 Graphics and Visualization Project
// Janine Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include "branch.h"

void makeBranch(float height, float base){
	GLUquadric *obj = gluNewQuadric();
	glColor3f(0.64f, 0.16, 0.16f);
	glPushMatrix();
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(obj, base, base - (0.2 * base), height, 20, 20);
	glPopMatrix();
	glutSwapBuffers();
}