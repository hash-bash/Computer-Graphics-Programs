#include<iostream>
#include<GL/glut.h>

using namespace std;

void display() {
    char q;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0);
    glVertex3f(0.6, -0.75, 0);
    glColor3f(0, 0, 1);
    glVertex3f(0, 0.75, 0);
    glEnd();
    glFlush();
    cout << "Do you want to terminate? ";
    cin >> q;
}

void keyboard(unsigned char q, int x, int y) {
    if (q == '27') {
        exit(0);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Triangle");
    glutReshapeWindow(600, 600);
    glutInitWindowPosition(80, 90);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
