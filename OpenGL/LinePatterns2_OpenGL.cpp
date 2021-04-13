#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

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

class lines {
public:
    double xini, yini, xend, yend;
    double X1, Y1, X2, Y2;

    void Solid(double X1_, double Y1_, double X2_, double Y2_);

    void Dashed(double X1_, double Y1_, double X2_, double Y2_);

    void Dotted(double X1_, double Y1_, double X2_, double Y2_);

    int sign(int a);
} l;

void createmenu() {
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("SOLID LINE", 2);
    glutAddMenuEntry("DASHED LINE", 3);
    glutAddMenuEntry("DOTTED", 4);
    glutAddMenuEntry("CLEAR", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int lines::sign(int a) {
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}

void lines::Solid(double X1_, double Y1_, double X2_, double Y2_) {
    int x1 = xini, y1 = yini, x2 = xend, y2 = yend;
    x1 = X1_;
    y1 = Y1_;
    x2 = X2_;
    y2 = Y2_;
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

void lines::Dashed(double X1_, double Y1_, double X2_, double Y2_) {
    int x1 = xini, y1 = yini, x2 = xend, y2 = yend;
    x1 = X1_;
    y1 = Y1_;
    x2 = X2_;
    y2 = Y2_;
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

            if (i % 6 != 0) {
                glVertex2i(x2, y2);
            }
        }
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

            if (i % 6 != 0) {
                glVertex2i(x2, y2);
            }
        }
    }
    glEnd();
    glFlush();
    xini = yini = xend = yend = initial = 0;
}

void lines::Dotted(double X1_, double Y1_, double X2_, double Y2_) {
    int x1 = xini, y1 = yini, x2 = xend, y2 = yend;
    x1 = X1_;
    y1 = Y1_;
    x2 = X2_;
    y2 = Y2_;
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
            l.X1 = a;
            l.Y1 = b;
            glColor3f(1, 0, 0);
            glBegin(GL_POINTS);
            glVertex2i(a, b);
            glEnd();
            glFlush();
            initial = 1;
        } else {
            l.X2 = a;
            l.Y2 = b;
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
        l.Solid(l.X1, l.Y1, l.X2, l.Y2);
    else if (value == 3)
        l.Dashed(l.X1, l.Y1, l.X2, l.Y2);
    else if (value == 4)
        l.Dotted(l.X1, l.Y1, l.X2, l.Y2);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Patterns");
    init();
    createmenu();
    glutMouseFunc(mymouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
