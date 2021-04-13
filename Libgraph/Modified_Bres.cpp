#include<iostream>
#include<graphics.h>

using namespace std;
int dx, dy, D, x, y;

void plotLineLow(int x0, int y0, int x1, int y1) {
    dx = x1 - x0;
    dy = y1 - y0;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }

    D = 2 * dy - dx;
    y = y0;
    for (x = x0; x < x1; x++) {
        putpixel(x, y, 1);
        if (D > 0) {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
    }
}

void plotLineHigh(int x0, int y0, int x1, int y1) {
    dx = x1 - x0;
    dy = y1 - y0;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    D = 2 * dx - dy;
    x = x0;
    for (y = y0; y < y1; y++) {
        putpixel(x, y, 1);
        if (D > 0) {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
    }
}

void plotLin(int x0, int y0, int x1, int y1) {
    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1)
            plotLineLow(x1, y1, x0, y0);
        else
            plotLineLow(x0, y0, x1, y1);
    } else {
        if (y0 > y1)
            plotLineHigh(x1, y1, x0, y0);
        else
            plotLineHigh(x0, y0, x1, y1);
    }
}

int main() {
    int x1, y1, x0, y0;
    int gd = DETECT, gm;
    cout << "\nEnter the starting point x1 and y1: ";
    cin >> x0;
    cin >> y0;
    cout << "\nEnter the ending points x2 and y2: ";
    cin >> x1 >> y1;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    plotLin(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}

