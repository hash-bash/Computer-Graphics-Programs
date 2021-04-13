#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Line {
public:
    int x1, x2, y1, y2;

    void get() {
        cout << "\n Enter the co-ordinate :";
        cout << "\n\tEnter the x1 and y1 : ";
        cin >> x1 >> y1;
        cout << "\n\tEnter the x2 and y2 : ";
        cin >> x2 >> y2;
    }

    void dda() {
        int steps, i;
        float xi, yi, x, y;
        int dx, dy;
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) > abs(dy)) {
            steps = abs(dx);
        } else
            steps = abs(dy);
        xi = (dx / (float) steps);
        yi = (dy / (float) steps);
        x = x1;
        y = y1;
        putpixel(x, y, RED);
        for (i = 0; i < steps; i++) {
            x = x + xi;
            y = y + yi;
            delay(10);
            putpixel(round(x), round(y), RED);
        }
    }

    void dda2() {
        int steps, i;
        float xi, yi, x, y;
        int dx, dy;
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) > abs(dy)) {
            steps = abs(dx);
        } else
            steps = abs(dy);
        xi = (dx / (float) steps);
        yi = (dy / (float) steps);
        x = x1;
        y = y1;
        putpixel(x, y, RED);
        for (i = 0; i < steps; i++) {
            x = x + xi;
            y = y + yi;
            delay(10);
            if (i % 2 != 0) {
                putpixel(round(x), round(y), RED);
            }
        }
    }

    void dda3() {
        int steps, i;
        float xi, yi, x, y;
        int dx, dy;
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) > abs(dy)) {
            steps = abs(dx);
        } else
            steps = abs(dy);
        xi = (dx / (float) steps);
        yi = (dy / (float) steps);
        x = x1;
        y = y1;
        putpixel(x, y, RED);
        for (i = 0; i < steps; i++) {
            x = x + xi;
            y = y + yi;
            delay(10);
            if (i % 6 != 0) {
                putpixel(round(x), round(y), RED);
            }
        }
    }

    void dda4() {
        int steps, i;
        float xi, yi, x, y;
        int dx, dy;
        dx = x2 - x1;
        dy = y2 - y1;
        if (abs(dx) > abs(dy)) {
            steps = abs(dx);
        } else
            steps = abs(dy);
        xi = (dx / (float) steps);
        yi = (dy / (float) steps);
        x = x1;
        y = y1;
        putpixel(x, y, RED);
        for (i = 0; i < steps; i++) {
            x = x + xi;
            y = y + yi;
            delay(10);
            if (i % 2 != 0 || i % 3 == 0) {
                putpixel(round(x), round(y), RED);
            }
        }
    }
};

int main() {
    Line l;
    l.get();
    cout << "Enter choice for the line - \n 1. Solid line \n 2. Dotted line \n 3. Dashed line \n 4. Dotted Dash line";
    int ch;
    cin >> ch;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(YELLOW);
    switch (ch) {
        case 1:
            l.dda();
        case 2:
            l.dda2();
        case 3:
            l.dda3();
        case 4:
            l.dda4();
    }
    getch();
    closegraph();
}

