//
// 50.017 Graphics and Visualization Project
// Janine Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include "branch.h"

void makeBranch(float height, float base){
	GLUquadric *obj = gluNewQuadric();
	glColor3f(.64f, .16f, .16f);
	glPushMatrix();
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(obj, base, base - (0.2 * base), height, 4, 4);
	glPopMatrix();
}