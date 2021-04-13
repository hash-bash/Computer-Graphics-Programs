#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<stack>

#define WIDTH 500
#define HEIGHT 500

#define HALFWIDTH 250
#define HALFHEIGHT 250

bool draw0;
bool draw2;

struct Point {
    Point(float x1, float y1) {
        x = x1;
        y = y1;
    }

    float x;
    float y;
};

std::vector<Point> chessboard;


void calculate_chessboard() {
    chessboard.clear();
    float onefourthw = WIDTH / 4;
    float onefourthh = HEIGHT / 4;
    for (int i = -2; i <= 2; i++) {
        chessboard.push_back(Point((float) (-WIDTH) / 2, onefourthh * i));
        chessboard.push_back(Point((float) WIDTH / 2, onefourthh * i));
    }

    for (int j = -2; j <= 2; j++) {
        chessboard.push_back(Point(onefourthw * j, -HEIGHT / 2));
        chessboard.push_back(Point(onefourthw * j, HEIGHT / 2));
    }
}

void rotate_chessboard(float angle) {
    int n = chessboard.size();
    float theta = angle * (3.14159265 / 180.0);

    for (int i = 0; i < n; i++) {
        float new_x = chessboard[i].x * std::cos(theta) + chessboard[i].y * std::sin(theta);
        float new_y = chessboard[i].x * (-std::sin(theta)) + chessboard[i].y * std::cos(theta);
        chessboard[i].x = new_x;
        chessboard[i].y = new_y;
    }
}

void init() {
    draw0 = false;
    draw2 = false;

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
    glMatrixMode(GL_MODELVIEW);
}

void boundary_fill(int x1, int y1, float *filla, float *boundary, bool **visited) {
    std::stack<Point> s;
    s.push(Point(x1, y1));

    while (s.size() != 0) {
        Point p = s.top();
        s.pop();

        int x = p.x;
        int y = p.y;

        if (x <= 0 || x >= WIDTH || y <= 0 || y >= HEIGHT) {
            continue;
        }
        if (visited[y][x]) {
            continue;
        }

        float color[3];
        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);

        if (!(color[0] == filla[0] && color[1] == filla[1] && color[2] == filla[2]) &&
            !(color[0] == boundary[0] && color[1] == boundary[1] && color[2] == boundary[2])) {
            glColor3f(filla[0], filla[1], filla[2]);
            glBegin(GL_POINTS);
            glVertex2i(-HALFWIDTH + x, -HALFHEIGHT + y);
            glEnd();
            glFlush();
            visited[y][x] = true;
            s.push(Point(x + 1, y));
            s.push(Point(x - 1, y));
            s.push(Point(x, y + 1));
            s.push(Point(x, y - 1));
        }
    }
}

void display() {
    if (!draw2) {
        glClear(GL_COLOR_BUFFER_BIT);

        if (chessboard.size() == 0) {
            calculate_chessboard();
        }

        if (draw0) {
            glColor3f(1.0, 0.0, 0.0);
            glLineWidth(5);

            glBegin(GL_LINES);
            glVertex2f(-WIDTH / 2, -HEIGHT / 2);
            glVertex2f(-WIDTH / 2, HEIGHT / 2);
            glVertex2f(-WIDTH / 2, -HEIGHT / 2);
            glVertex2f(WIDTH / 2, -HEIGHT / 2);
            glVertex2f(-WIDTH / 2, HEIGHT / 2);
            glVertex2f(WIDTH / 2, HEIGHT / 2);
            glVertex2f(WIDTH / 2, -HEIGHT / 2);
            glVertex2f(WIDTH / 2, HEIGHT / 2);
            glEnd();

            glBegin(GL_LINES);
            int n = chessboard.size();
            for (int i = 0; i < n; i++) {
                glVertex2f(chessboard[i].x, chessboard[i].y);
            }
            glEnd();
        }

        glFlush();
    }
}

void start_boundary_fill(int x, int y) {
    float boundary[] = {1.0, 0.0, 0.0};
    float filla[] = {0.0, 0.0, 0.0};

    bool **visited = new bool *[HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        visited[i] = new bool[WIDTH];
        for (int j = 0; j < WIDTH; j++) {
            visited[i][j] = false;
        }
    }
    boundary_fill(x, y, filla, boundary, visited);
    glutPostRedisplay();
}

void menu(int value) {
    if (value == 0) {
        draw0 = true;
        glutPostRedisplay();
    } else {
        if (draw0) {
            if (value == 1) {
                rotate_chessboard(45.0);
                glutPostRedisplay();
            }

            if (value == 2) {
                draw2 = true;
                start_boundary_fill(3, 162);
                start_boundary_fill(249, 25);
                start_boundary_fill(221, 25);
                start_boundary_fill(208, 27);
                start_boundary_fill(5, 340);
                start_boundary_fill(172, 163);
                start_boundary_fill(167, 160);
                start_boundary_fill(169, 339);
                start_boundary_fill(341, 162);
                start_boundary_fill(190, 493);
                start_boundary_fill(345, 337);
            }
        } else {
            std::cout << "\nDraw chessboard first" << std::endl;
        }
    }
}

void mouse(int button, int state, int x, int y) {
    if (draw2) {
        if (state == GLUT_DOWN) {
            if (button == GLUT_LEFT_BUTTON) {
                std::cout << x << "," << y << std::endl;
                start_boundary_fill(x, HEIGHT - y);
            }
        }
    }
}

void create_menu() {
    glutCreateMenu(menu);
    glutAddMenuEntry("Draw Chessboard", 0);
    glutAddMenuEntry("Rotate by 45 Degrees", 1);
    glutAddMenuEntry("Fill Black Squares", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(WIDTH - 1, HEIGHT - 1);
    glutCreateWindow("4X4 Chess Board");

    init();
    create_menu();

    glutReshapeFunc(reshape);
    glutReshapeWindow(WIDTH, HEIGHT);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
