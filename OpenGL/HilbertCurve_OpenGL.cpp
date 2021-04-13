#include<iostream>
#include<GL/glut.h>
#include<unistd.h>

using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(0, 600, 0, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

class Hilbert {
public:
    int r, l, u, d, h, x, y, n;
    int x1, y1;

    Hilbert() {
        u = 1;
        r = 2;
        d = 3;
        l = 4;
        h = 10;
    }

    void DDA(int, int, int, int);

    void createhilbert(int, int, int, int, int, int, int &x, int &y);

    void draw(int, int, int &x, int &y);
} H;

void Hilbert::DDA(int xini, int yini, int xend, int yend) {
    float xinc, yinc, x, y, dx, dy;
    x = xini;
    y = yini;
    dx = xend - xini;
    dy = yend - yini;
    float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xinc = dx / (float) steps;
    yinc = dy / (float) steps;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    for (int i = 0; i < steps; i++) {
        x += xinc;
        y += yinc;
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}

void Hilbert::draw(int v, int h, int &x, int &y) {
    x1 = x;
    y1 = y;

    if (v == 1) {
        y += h;
    } else if (v == 2) {
        x += h;
    } else if (v == 3) {
        y -= h;
    } else
        x -= h;

    DDA(x1, y1, x, y);
    x1 = x;
    y1 = y;

    usleep(10000);
}

void Hilbert::createhilbert(int r, int d, int l, int u, int i, int h, int &x, int &y) {
    if (i > 0) {
        i--;
        createhilbert(d, r, u, l, i, h, x, y);
        draw(r, h, x, y);
        createhilbert(r, d, l, u, i, h, x, y);
        draw(d, h, x, y);
        createhilbert(r, d, l, u, i, h, x, y);
        draw(l, h, x, y);
        createhilbert(u, l, d, r, i, h, x, y);
    }
}

void display() {

}

void menu(int p) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        H.x = x;
        H.y = 600 - y;
        cout << "hi";
        H.createhilbert(H.r, H.d, H.l, H.u, H.n, H.h, H.x, H.y);
    }

    glutCreateMenu(menu);
    glutAddMenuEntry("Clear the screen", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
}

int main(int argc, char **argv) {
    cout << "Enter the number of iterations:\n";
    cin >> H.n;

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hilbert Curve");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
