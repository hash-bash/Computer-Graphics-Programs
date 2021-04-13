#include <iostream>
#include <GL/glut.h>

using namespace std;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 1.0);
    glPointSize(20.0);

    glBegin(GL_POINTS);
    glVertex2i(60, 360);
    glVertex2i(140, 360);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(20, 250);
    glVertex2i(100, 380);
    glVertex2i(180, 250);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(200, 250);
    glVertex2i(200, 380);
    glVertex2i(380, 380);
    glVertex2i(380, 250);
    glEnd();

    glColor3f(10.15, 0.0, 99.0);
    glBegin(GL_POLYGON);
    glVertex2i(90, 30);
    glVertex2i(30, 90);
    glVertex2i(30, 174);
    glVertex2i(90, 234);
    glVertex2i(174, 234);
    glVertex2i(234, 174);
    glVertex2i(234, 90);
    glVertex2i(174, 30);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(260, 30);
    glVertex2i(320, 230);
    glVertex2i(380, 30);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("OpenGL Shapes");
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 800);

    init();
    glutDisplayFunc(drawShapes);
    glutMainLoop();
    return 0;
}
