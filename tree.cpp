//
// 50.017 Graphics and Visualization Project
// Janine Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include "tree.h"
#include "branch.h"

void makeTree(double height, double diameter, int alpha, int depth) {
	makeBranch(height, diameter);

	glTranslatef(0.0, height, 0.0);
	height -= height * .25;
	diameter -= diameter * .25;

	for (int a = 0; a < 3; a++) {
		int angle = (alpha * depth * a) % 50 + 20;

		if (angle > 48 || alpha % 2 == 0)
			angle = -((alpha * depth * a) % 50 + 20);

		if (depth > 0 && height > .25) {

			glPushMatrix();
			glRotatef(angle, 1, 0, 1);
			makeTree(height, diameter, a, depth - 1);
			glPopMatrix();

		}
	}

}
