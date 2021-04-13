#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

int k = 0;

class Points {
public:
    float x, y, z;

    void setxy(float p, float q) {
        x = p;
        y = q;
    }

    void DDA(int x1, int y1, int x2, int y2);
};

Points p, arr[20];


void Points::DDA(int x1, int y1, int x2, int y2) {
    float xinc, yinc;

    int dx, dy, steps;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
        xinc = (float) dx / steps;
        yinc = (float) dy / steps;
    } else {
        steps = abs(dy);
        xinc = (float) dx / steps;
        yinc = (float) dy / steps;
    }
    glColor3f(0, 1, 0);
    float x = x1, y = y1;
    glVertex2f(x, y);
    for (int i = 0; i < steps; i++) {
        x += xinc;
        y += yinc;
        glVertex2f(x, y);
    }
}

void init() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(0, 640, 480, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void display() {
    glBegin(GL_POINTS);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "Enter co-ordinates of outer square : ";
    x1 = arr[0].x;
    y1 = arr[0].y;
    x2 = arr[1].x;
    y2 = arr[1].y;

    x3 = arr[2].x;
    y3 = arr[2].y;
    x4 = arr[3].x;
    y4 = arr[3].y;


    p.DDA(x1, y1, x2, y2);
    p.DDA(x2, y2, x3, y3);
    p.DDA(x3, y3, x4, y4);
    p.DDA(x4, y4, x1, y1);

    int mx1, my1, mx2, my2, mx3, my3, mx4, my4;
    mx1 = (x1 + x2) / 2;
    my1 = (y1 + y2) / 2;
    mx2 = (x2 + x3) / 2;
    my2 = (y2 + y3) / 2;
    mx3 = (x3 + x4) / 2;
    my3 = (y3 + y4) / 2;
    mx4 = (x4 + x1) / 2;
    my4 = (y4 + y1) / 2;

    p.DDA(mx1, my1, mx2, my2);
    p.DDA(mx2, my2, mx3, my3);
    p.DDA(mx3, my3, mx4, my4);
    p.DDA(mx4, my4, mx1, my1);

    p.DDA((mx1 + mx2) / 2, (my1 + my2) / 2, (mx2 + mx3) / 2, (my2 + my3) / 2);
    p.DDA((mx2 + mx3) / 2, (my2 + my3) / 2, (mx3 + mx4) / 2, (my3 + my4) / 2);
    p.DDA((mx3 + mx4) / 2, (my3 + my4) / 2, (mx4 + mx1) / 2, (my4 + my1) / 2);
    p.DDA((mx4 + mx1) / 2, (my4 + my1) / 2, (mx1 + mx2) / 2, (my1 + my2) / 2);
    glEnd();
    glFlush();
    k = 0;
}

void mymouse(int button, int state, int x, int y) {
    if (k == 4) {
        glutPostRedisplay();
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        arr[k++].setxy((float) x, (float) (y));
        glColor3f(1, 0, 0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
    }

}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);                  //To initialise glutWindow
    glutInitWindowPosition(0, 0);           //To set window position on screen
    glutInitWindowSize(640, 480);           //To set Window Size on screen
    glutCreateWindow("Rectangle Pattern");  //Creates window with the name of window as the formal argument
    init();                                 //Calls init function
    glutMouseFunc(mymouse);
    glutDisplayFunc(display);               //Call Display function containing the main program logic
    glutMainLoop();                         //Run GLUT main loop

}
