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
        xi = dx / (float) steps;
        yi = dy / (float) steps;
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

    void bre() {
        int dx, dy;
        int p, xe, x, y;
        dx = x2 - x1;
        dy = y2 - y1;
        p = 2 * dy - dx;
        if (x1 > x2) {
            x = x2;
            y = y2;
            xe = x1;
        } else {
            x = x1;
            y = y1;
            xe = x2;
        }
        putpixel(x, y, 7);
        while (x < xe) {
            x++;
            if (p < 0)
                p = p + (2 * dy);
            else {
                y++;
                p = p + 2 * (dy - dx);
                delay(10);
                putpixel(x, y, BLUE);
            }
        }
    }
};

int main() {
    Line l;
    l.get();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(YELLOW);
    l.dda();
    l.bre();
    getch();
    closegraph();
}

