#include <iostream>
using namespace std;

#include <cmath>
#include <ctime>
#include "glut.h" 
#include <time.h>

static int angle = 0;

void myTimerFunc(int val);
void drawSun();
void drawMercury();
void drawVenus();
void drawEarth();
void drawMoon();
void drawMars();
void drawJupiter();
void drawSaturn();
void drawUranus();
void drawNeptune();
void drawOrbit(unsigned int para);
void myDisplay();

void myTimerFunc(int val) {
	angle++;
	if (angle >= 50000)
		angle = 0;
	myDisplay();
	glutTimerFunc(10, myTimerFunc, 0);
}

void drawSun() {
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 0.0, -1.0);
	glutSolidSphere(20000000, 50, 50);
	glPopMatrix();
}

void drawMercury() {
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glRotatef(10.0 * angle, -0.0, 0.0, -1.0);
	glTranslatef(58000000.0, 0.0, 0.0);
	glutSolidSphere(4800000, 50, 50);
	glPopMatrix();
	drawOrbit(58000000);
}

void drawVenus() {
	glPushMatrix();
	glColor3f(1.00, 0.8, 0.0);
	glRotatef(5.0*angle, 0.0, 0.0, -1.0);
	glTranslatef(100000000, 0.0, 0.0);
	glutSolidSphere(12100000, 50, 50);
	glPopMatrix();
	drawOrbit(100000000);
}

void drawEarth() {
	glPushMatrix();
	glColor3f(0.0, 0.8, 1.0);
	glRotatef(4.0*angle, 0.0, 0.0, -1.0);
	glTranslatef(150000000, 0.0, 0.0);
	glutSolidSphere(12700000, 50, 50);
	glPopMatrix();
	drawOrbit(150000000);
}

void drawMoon() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(4.0*angle, 0.0, 0.0, -1.0);
	glTranslatef(150000000, 0.0, 0.0);
	glRotatef(48.0*angle, 0.0, 0.0, -1.0);
	glTranslatef(20000000, 0.0, 0.0);
	glutSolidSphere(5000000, 50, 50);
	glPopMatrix();
}

void drawMars() {
	glPushMatrix();
	glColor3f(1.0, 0.7, 0.2);
	glRotatef(3.0*angle, 0.0, 0.0, -1.0);
	glTranslatef(230000000, 0.0, 0.0);
	glutSolidSphere(6700000, 50, 50);
	glPopMatrix();
	drawOrbit(230000000);
}

void drawJupiter() {
	glPushMatrix();
	glColor3f(0.8, 0.5, 0.3);
	glRotatef(1.0*angle, 0.0, 0.0, -1.0);
	glTranslatef(400000000, 0.0, 0.0);
	glutSolidSphere(14200000, 50, 50);
	glPopMatrix();
	drawOrbit(400000000);
}

void drawSaturn() {
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.5);
	glRotatef(0.9*angle, 0.0, 0.0, -1.0);
	glTranslatef(550000000, 0.0, 0.0);
	glutSolidSphere(12000000, 50, 50);
	glutSolidTorus(2000000, 20000000, 50, 50);
	glPopMatrix();
	drawOrbit(550000000);
}

void drawUranus() {
	glPushMatrix();
	glColor3f(0.0, 0.4, 1.0);
	glRotatef(0.8 * angle, 0.0, 0.0, -1.0);
	glTranslatef(700000000, 0.0, 0.0);
	glutSolidSphere(5100000, 50, 50);
	glPopMatrix();
	drawOrbit(700000000);
}

void drawNeptune() {
	glPushMatrix();
	glColor3f(0.0, 0.8, 1.0);
	glRotatef(0.7*angle, 0.0, 0.0, -1.0);
	glTranslatef(850000000, 0.0, 0.0);
	glutSolidSphere(4900000, 50, 50);
	glPopMatrix();
	drawOrbit(850000000);
}

void drawOrbit(unsigned int para) {
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glutSolidTorus(100000, para, 50, 50);
	glPopMatrix();
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//刷新颜色缓冲
	glMatrixMode(GL_PROJECTION);//投影模式
	glLoadIdentity();//加载单位阵
	gluPerspective(62.0, 1.0, 1, 1000000000);
	glMatrixMode(GL_MODELVIEW);//模型试图
	glLoadIdentity();
	gluLookAt(0, -600000000, 600000000, 0, 0, 0, 0, 0, 1);
	
	drawSun();
	drawMercury();
	drawVenus();
	drawEarth();
	drawMoon();
	drawMars();
	drawJupiter();
	drawSaturn();
	drawUranus();
	drawNeptune();
	glutSwapBuffers();//交换缓冲区
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("SolarSystem");
	glutDisplayFunc(&myDisplay);
	glutTimerFunc(10, myTimerFunc, 0);
	glutMainLoop();
	return 0;
}
