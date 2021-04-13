#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

int cx, cy, r;

class shape {
public:
    void makecircle(int cx, int cy, int x, int y);

    void BresenhamCircle(int cx, int cy, int r);

    void Pattern(int cx, int cy, int r);

    void dda_line(int, int, int, int);
} p;

void shape::makecircle(int cx, int cy, int x, int y) {
    glColor3f(0, 1, 0);
    glBegin(GL_POINTS);
    glVertex2i(cx + x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx - x, cy - y);
    glVertex2i(cx + y, cy + x);
    glVertex2i(cx + y, cy - x);
    glVertex2i(cx - y, cy + x);
    glVertex2i(cx - y, cy - x);
    glEnd();
}

void shape::BresenhamCircle(int cx, int cy, int r) {
    int x = 0, y = r, d;
    d = 3 - 2 * r;

    while (x <= y) {
        if (d > 0) {
            x++;
            y--;
            d += 4 * x - 4 * y + 10;
        } else {
            x++;
            d += 4 * x + 6;
        }
        makecircle(cx, cy, x, y);
    }

}

void shape::dda_line(int xini, int yini, int xend, int yend) {
    glPointSize(1.0);
    double dx = (xend - xini);
    double dy = (yend - yini);
    double steps;
    float xInc, yInc, x = xini, y = yini;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;
    glLineWidth(10.0);
    glVertex2f(x, y);
    int k;
    for (k = 0; k < steps; k++) {
        x += xInc;
        y += yInc;
        glVertex2f(x, y);
    }
}

void shape::Pattern(int cx, int cy, int r) {
    BresenhamCircle(cx, cy, r);
    glBegin(GL_POINTS);
    p.dda_line(cx, cy - r, cx + r * 0.866, cy + r * 0.5);
    p.dda_line(cx + r * 0.866, cy + r * 0.5, cx - r * 0.866, cy + r * 0.5);
    p.dda_line(cx - r * 0.866, cy + r * 0.5, cx, cy - r);
    glEnd();
    BresenhamCircle(cx, cy, r / 2);
}


void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 640, 480, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void display() {
    glPointSize(1);
    glBegin(GL_POINTS);
    p.Pattern(cx, cy, r);
    glEnd();
    glFlush();
}

void mymouse(int button, int state, int x, int y) {
    glColor3f(1, 0, 0);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        cx = x;
        cy = y;
        glPointSize(4);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        r = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y));
        glutPostRedisplay();
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Circle Pattern");
    init();
    glutMouseFunc(mymouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

