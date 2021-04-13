#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check = 1;
int i = 0;
int count = 140;
int coll = 0;
GLfloat c1, c2;
GLfloat ba[1000][8] = {{0},
                       {0}};
GLfloat ta[1000][8] = {{0},
                       {0}};
GLfloat u = 100.0, v = 100.0;

GLubyte rasters[218] = {
        0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0,
        0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0,
        0x0c, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x0c, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x0c, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x0c, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x0c, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x0c, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x0f, 0xff, 0xc0, 0x00, 0x00, 0x30,
        0x0f, 0xff, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xc0, 0x00, 0x00, 0x30,
        0x00, 0x00, 0xff, 0xff, 0xff, 0xf0,
        0x00, 0x00, 0xff, 0xff, 0xff, 0xf0,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0xf0, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0xf0, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0xf0, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0xf0, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x3f,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x30,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x30,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x30,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x30,
        0x00, 0x00, 0x00, 0x3f, 0xff, 0xf0,
        0x00, 0x00, 0x00, 0x3f, 0xff, 0xf0
};

void myinit();

void display();

void back_ground();

void game_end(int coll);

void front();

void timer_func(int n);

void timer_func(int n) {
    glutPostRedisplay();
    glutTimerFunc(5, timer_func, 5);
}

void front() {
    timer_func(600);
    char str1[] = "DRAGON QUEST";
    char str2[] = "3210";
    char str3[] = "SAURABH DOME";
    char str4[] = "AKASH KUMAR";
    char str5[] = "";
    char str6[] = "Army Institute of Technology, Pune";
    myinit();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(230.0f, 260.0f);
    for (int i = 0; i < strlen(str1); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int) str1[i]);
    }

    glColor3f(0.5f, 0.0f, 0.0f);
    glRasterPos2f(470.0f, 110.0f);
    for (int i = 0; i < strlen(str3); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int) str3[i]);
    }

    glColor3f(0.5f, 0.0f, 0.0f);
    glRasterPos2f(470.0f, 85.0f);
    for (int i = 0; i < strlen(str4); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int) str4[i]);
    }
    glColor3f(0.0f, 0.0f, 1.0f);
    glRasterPos2f(70.0f, 110.0f);
    for (int i = 0; i < strlen(str5); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int) str5[i]);
    }
    glColor3f(0.7f, 0.0f, 1.0f);
    glRasterPos2f(70.0f, 85.0f);
    for (int i = 0; i < strlen(str6); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int) str6[i]);
    }
    check = 0;
    glFlush();

    for (int i = 0; i <= 3; i++) {

        glColor3f(1.0f, 0.0f, 0.0f);
        glRasterPos2f(270.0f, 190.0f);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int) str2[i]);
        glFlush();
        for (int j = 0; j < 500000000; j++);
        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(270.0f, 190.0f);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int) str2[i]);
        for (int j = 0; j < 500000000; j++);
        glFlush();
    }
}


void mouse(int btn, int state, int x, int y) {
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        v = v + 70;

    if (v > 380)
        v = 380;
}

void game_end(int coll) {
    char string1[20] = "GAME OVER";
    char string2[20] = "YOUR SCORE IS : ";
    int len1 = strlen(string1);

    if (coll == 0) { string2[17] = 48; }
    int rev = 0, var;
    while (coll != 0) {
        var = coll % 10;
        rev = var + rev * 10;
        coll = coll / 10;
    }

    for (int i = 0; rev != 0; i++) {
        var = rev % 10;
        string2[17 + i] = var + 48;
        rev = rev / 10;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glColor3f(0.0f, 0.0f, 1.0f);
    glRasterPos2f(240.0f, 230.0f);

    for (int i = 0; i < len1; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) string1[i]);
    }

    glColor3f(1.0f, 0.0f, 0.0f);
    glRasterPos2f(215.0f, 190.0f);

    for (int i = 0; i <= 19; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int) string2[i]);
    }

    glFlush();
    for (int l = 0; l < 1000000000; l++);
    exit(0);
}

void myinit() {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}

void obstacles() {
    if (count == 140) {
        ba[i][0] = 585.0;
        ba[i][1] = 0.0;
        ba[i][2] = 585.0;
        ba[i][3] = rand() % 200;
        ba[i][4] = 600.0;
        ba[i][5] = ba[i][3];
        ba[i][6] = 600.0;
        ba[i][7] = 0.0;

        ta[i][0] = 585.0;
        ta[i][1] = 400.0;
        ta[i][2] = 585.0;
        ta[i][3] = 400.0 - ba[i][3] - 140.0;
        ta[i][4] = 600.0;
        ta[i][5] = ta[i][3];
        ta[i][6] = 600.0;
        ta[i][7] = 400.0;
        i++;
        count = 0;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    count++;

    for (int m = 0; m < i; m++) {
        if (ba[m][0] == 0 && ta[m][0] == 0)continue;
        glColor3f(1.0, 0.0, 0.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_POLYGON);
        glVertex2f(ba[m][0]--, ba[m][1]);
        glVertex2f(ba[m][2]--, ba[m][3]);
        glVertex2f(ba[m][4]--, ba[m][5]);
        glVertex2f(ba[m][6]--, ba[m][7]);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_POLYGON);
        glVertex2f(ta[m][0]--, ta[m][1]);
        glVertex2f(ta[m][2]--, 400 - ta[m][3]);
        glVertex2f(ta[m][4]--, 400 - ta[m][5]);
        glVertex2f(ta[m][6]--, ta[m][7]);
        glEnd();

        glColor3f(c1, c2, 0.0);
        glRasterPos2i(u, v);
        glBitmap(48, 36, 0.0, 0.0, 0.0, 0.0, rasters);
    }
    glFlush();

    if (ta[coll][4] == 99)coll++;

    if (u <= (ta[coll][2] + 15) && (u + 48) >= ta[coll][2] && v <= (ba[coll][3] + 400 + ta[coll][3]) &&
        (36 + v) >= (140 + ba[coll][3])) {
        game_end(coll);
    }
    if (u <= (ba[coll][0] + 15) && (u + 48) >= ba[coll][0] && v <= (ba[coll][1] + ba[coll][3]) &&
        (36 + v) >= ba[coll][1]) {
        game_end(coll);
    }
}

void display() {
    if (check == 1)front();
    int k = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    v--;
    if (v == 0)
        game_end(coll);

    obstacles();
}

int main(int argc, char **argv) {
    c1 = (GLfloat) rand() / RAND_MAX;
    c2 = (GLfloat) rand() / RAND_MAX;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Dragon Quest (Flappy Bird)");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
