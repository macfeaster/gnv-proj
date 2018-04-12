//
// 50.017 Graphics and Visualization Project
// Janine Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include <cstdlib>
#include "tree.h"
#include "branch.h"
#include "leaf.h"

void makeTree(float height, float base){

	float angle;
	makeBranch(height, base);
	glTranslatef(0.0, height, 0.0);
	height -= height * .2;
	base-= base * 0.3;

	for (int a = 0; a < 3; a++) {
		angle = rand() % 50 + 20;

		if (angle > 48)
			angle = -(rand() % 50 + 20);

		if (height >1){
			glPushMatrix();
			glRotatef(angle, 1, 0.0, 1);
			makeTree(height, base);
			glPopMatrix();

		} else {
			makeLeaf(height, base);
		}
	}

}
