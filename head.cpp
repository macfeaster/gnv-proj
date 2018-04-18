//
// 50.017 Graphics and Visualization Project
// Ruoyuan Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include "head.h"

void makeHead(float height, float base){
	GLUquadric *obj = gluNewQuadric();
	glPushMatrix();
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(obj, base, base-(0.2*base), height, 4, 4);
	glPopMatrix();
}
