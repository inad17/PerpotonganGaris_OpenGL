#include <windows.h>
#include <GL/glut.h>

void init(){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glPointSize(10.0);
	glLoadIdentity();
	glLineWidth(4.0f);
	gluOrtho2D(0.0, 300, 0.0, 300.0);
}

void perpotongan() {
	float ax = 125, ay = 50, bx= 50, by = 200, cx = 42, cy = 160, dx = 208, dy = 160, ex = 200, ey = 200,
	fx = 125, fy = 50, gx = 28, gy = 90, hx = 222, hy =90, a1 = 50, a2 = 202, a3 = 200, a4 = 202, a5 = 20,
	a6 = 49, a7 = 230, a8 = 49, a9 = 20, a10 = 48, a11 = 50, a12 = 203, a13 = 230, a14 = 48, a15 = 200, a16 = 203,
	Mab, Mcd, Mef, Mgh, Cab, Ccd, Cef, Cgh, px, py, pz, pi, pa, pb, pc, pd;

	glClear(GL_COLOR_BUFFER_BIT);
	
	// Garis Kuning
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(ax, ay);
	glVertex2f(bx, by);
	glEnd();

	//Garis Biru
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(cx, cy);
	glVertex2f(dx, dy);
	glEnd();

    //Garis Hijau
    glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(ex, ey);
	glVertex2f(fx, fy);
	glEnd();

	//Garis Merah
    glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(gx, gy);
	glVertex2f(hx, hy);
	glEnd();

	//Bentuk Trapesium
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(a1, a2);
	glVertex2f(a3, a4);
    glVertex2f(a5, a6);
	glVertex2f(a7, a8);
	glVertex2f(a9, a10);
	glVertex2f(a11, a12);
    glVertex2f(a13, a14);
	glVertex2f(a15, a16);
	glEnd();

	//Rumus
	Mab = (by - ay) / (bx - ax);
	Mcd = (dy - cy) / (dx - cx);
	Mef = (fy - ey) / (fx - ex);
	Mgh = (hy - gy) / (hx - gx);
	Cab = ay - (ax * Mab);
	Ccd = cy - (cx * Mcd);
	Cef = ey - (ex * Mef);
	Cgh = gy - (gx * Mgh);

	//Titik Potong
	px = (Ccd - Cab) / (Mab - Mcd);
	py = (Mab * px) + Cab;
	pz = (Cgh - Cab) / (Mab - Mgh);
	pi = (Mgh * pz) + Cgh;
	pa = (Ccd - Cef) / (Mef - Mcd);
	pb = (Mef * pa) + Cef;
	pc = (Cgh - Cef) / (Mef - Mgh);
	pd = (Mgh * pc) + Cgh;

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(px, py);
	glVertex2f(pz, pi);
	glVertex2f(pa, pb);
	glVertex2f(pc, pd);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Ramadani_672020308");
	init();
	glutDisplayFunc(perpotongan);
	glutMainLoop();
}
