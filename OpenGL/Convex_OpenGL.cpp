#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

bool complete = false;
int k = 0;

struct Color {
    float r, g, b;
};

class Poly {
public:
    int x, y, z;

    void setxy(int p, int q) {
        x = p;
        y = q;
    }

    void setpixel(int x, int y, Color newcolor);

    void floodfill(int x, int y, Color oldcolor, Color newcolor);

    void dda_line(int, int, int, int);
};

Poly p[10];

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(0, 640, 0, 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

Color getpixel(int x, int y) {
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void Poly::setpixel(int x, int y, Color newcolor) {
    glColor3f(newcolor.r, newcolor.g, newcolor.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();

}

void Poly::dda_line(int xini, int yini, int xend, int yend) {
    glPointSize(1.0);
    double dx = (xend - xini);
    double dy = (yend - yini);
    double steps;
    float xInc, yInc, x = xini, y = yini;
    steps = (abs(dx) > abs(dy)) ? (abs(dx)) : (abs(dy));
    xInc = dx / (float) steps;
    yInc = dy / (float) steps;
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
}

void Poly::floodfill(int x, int y, Color oldcolor, Color newcolor) {
    Color col;
    col = getpixel(x, y);
    if (col.r == oldcolor.r && col.g == oldcolor.g && col.b == oldcolor.b) {
        setpixel(x, y, newcolor);
        floodfill(x + 1, y, oldcolor, newcolor);
        floodfill(x, y + 1, oldcolor, newcolor);
        floodfill(x - 1, y, oldcolor, newcolor);
        floodfill(x, y - 1, oldcolor, newcolor);
    }
}

void mymouse(int button, int state, int x, int y) {
    if (!complete && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        y = 480 - y;
        p[k++].setxy(x, y);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        if (k > 1) {
            glPointSize(1);
            glBegin(GL_POINTS);
            p[0].dda_line(p[k - 2].x, p[k - 2].y, p[k - 1].x, p[k - 1].y);

            glEnd();
            glFlush();
        }
    }

    if (!complete && button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        complete = true;
        glPointSize(1);
        glBegin(GL_POINTS);
        p[0].dda_line(p[k - 1].x, p[k - 1].y, p[0].x, p[0].y);
        glEnd();
        glFlush();
    }

    if (complete && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        y = 480 - y;
        Color oldcolor;
        oldcolor.r = oldcolor.g = oldcolor.b = 0;

        Color newcolor;
        newcolor.r = 0;
        newcolor.g = newcolor.b = 1;

        p[0].floodfill(x, y, oldcolor, newcolor);
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Seed Fill");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}
