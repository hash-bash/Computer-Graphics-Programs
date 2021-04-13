#include<bits/stdc++.h>
#include<GL/glut.h>
#include<math.h>

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
    double X1, Y1, X2, Y2;

    void Solid(double X1_, double Y1_, double X2_, double Y2_);

    void Dashed(double X1_, double Y1_, double X2_, double Y2_);

    void Dotted(double X1_, double Y1_, double X2_, double Y2_);
} l;

void createmenu() {
    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("SOLID", 2);
    glutAddMenuEntry("DASHED", 3);
    glutAddMenuEntry("DOTTED", 4);
    glutAddMenuEntry("CLEAR", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void lines::Solid(double X1_, double Y1_, double X2_, double Y2_) {
    double dx = (X2_ - X1_);
    double dy = (Y2_ - Y1_);
    double steps;
    float xInc, yInc, x = X1_, y = Y1_;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;

    glBegin(GL_POINTS);

    glVertex2d(x, y);
    int k;

    for (k = 0; k < steps; k++) {
        x += xInc;
        y += yInc;

        glVertex2d(x, y);
    }
    glEnd();

    glFlush();
    X1 = Y1 = X2 = Y2 = initial = 0;
}


void lines::Dashed(double X1_, double Y1_, double X2_, double Y2_) {
    double dx = (X2_ - X1_);
    double dy = (Y2_ - Y1_);
    double steps;
    float xInc, yInc, x = X1_, y = Y1_;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;
    glBegin(GL_POINTS);

    glVertex2d(x, y);
    int k;
    for (k = 0; k < steps; k++) {
        x += xInc;
        y += yInc;
        if (k % 6 != 0) {
            glVertex2d(x, y);
        }
    }
    glEnd();

    glFlush();
    X1 = Y1 = X2 = Y2 = initial = 0;
}


void lines::Dotted(double X1_, double Y1_, double X2_, double Y2_) {
    double dx = (X2_ - X1_);
    double dy = (Y2_ - Y1_);
    double steps;
    float xInc, yInc, x = X1_, y = Y1_;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;
    glBegin(GL_POINTS);

    glVertex2d(x, y);
    int k;

    for (k = 0; k < steps; k++) {
        x += xInc;
        y += yInc;
        if (k % 2 != 0 || k % 3 == 0) {
            glVertex2d(x, y);
        }
    }
    glEnd();

    glFlush();
    X1 = Y1 = X2 = Y2 = initial = 0;
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
