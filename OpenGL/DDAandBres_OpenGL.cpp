#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;
static int menu_id;
static int value = 0;
int initial = 0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 640.0, 480.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1);
}

void menu(int num) {
    value = num;
    glutPostRedisplay();
}

class line {
public:
    double xini, yini, xend, yend;

    void dda_line();

    int sign(int a);

    void breshman_line();

} l;

void createmenu() {
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("DDA Line Generation", 2);
    glutAddMenuEntry("Bresenhams Line Generation", 3);
    glutAddMenuEntry("Clear the screen", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void line::dda_line() {
    glPointSize(1.0);
    double dx = (xend - xini);
    double dy = (yend - yini);
    double steps;
    float xInc, yInc, x = xini, y = yini;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;
    glColor3f(10.0, 0.0, 0.0);
    glLineWidth(10.0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    int k;
    for (k = 0; k < steps; k++) {
        x += xInc;
        y += yInc;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
    xini = yini = xend = yend = initial = 0;
}

int line::sign(int a) {
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}

void line::breshman_line() {
    int x1 = xini, y1 = yini, x2 = xend, y2 = yend;
    int dx, dy, g;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    g = 2 * dy - dx;

    int s1 = sign(x2 - x1);
    int s2 = sign(y2 - y1);

    int x = x1;
    int y = y1;
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    if (dx >= dy) {
        for (int i = 0; i <= dx; i++) {
            glVertex2i(x, y);
            if (g >= 0) {
                x += s1;
                y += s2;
                g += (2 * dy - 2 * dx);
            } else {
                x += s1;
                g += 2 * dy;
            }
        }
        glVertex2i(x2, y2);
    } else {
        g = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            glVertex2i(x, y);
            if (g >= 0) {
                x += s1;
                y += s2;
                g += (2 * dx - 2 * dy);
            } else {
                y += s2;
                g += 2 * dx;
            }
        }
        glVertex2i(x2, y2);
    }
    glEnd();
    glFlush();
    xini = yini = xend = yend = initial = 0;
}

void mymouse(int btn, int state, int x, int y) {

    int a = x, b = y;
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (initial == 0) {
            l.xini = a;
            l.yini = b;
            glColor3f(1, 0, 0);
            glBegin(GL_POINTS);
            glVertex2i(a, b);
            glEnd();
            glFlush();
            initial = 1;
        } else {
            l.xend = a;
            l.yend = b;
            glColor3f(1, 0, 0);
            glBegin(GL_POINTS);
            glVertex2i(a, b);
            glEnd();
            glFlush();
        }
    }
}

void display() {
    glColor3f(1, 0, 0);
    if (value == 1) {
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    } else if (value == 2)
        l.dda_line();
    else if (value == 3)
        l.breshman_line();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA and Bresenhams Line generation");
    init();
    createmenu();
    glutMouseFunc(mymouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




