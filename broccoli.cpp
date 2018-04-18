//
// 50.017 Graphics and Visualization Project
// Ruoyuan Liao and Mauritz Zachrisson
//

#include <GLUT/glut.h>
#include "broccoli.h"
#include "head.h"

void makeBroccoli(double height, double diameter, int alpha, int depth) {
	makeHead(height, diameter);

	glTranslatef(0.0, height, 0.0);
	height -= height * 0.25;
	diameter -= diameter * 0.25;

	for (int a = 0; a < 3; a++) {
		int angle = (alpha * depth * a) % 50 + 20;

		if (angle > 48 || alpha % 2 == 0)
			angle = -((alpha * depth * a) % 50 + 20);

		if (depth == 8)
			angle = 15;

		if (depth > 0 && height > .25) {

			glPushMatrix();
			glRotatef(angle, 1, 0, 1);
			makeBroccoli(height, diameter, a, depth - 1);
			glPopMatrix();

		}
	}

}
