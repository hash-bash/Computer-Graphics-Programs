#include<iostream>
#include<graphics.h>
#include<cstdlib>

int main() {
    int x1, x2, y1, y2;
    int gd = DETECT, gm;
    int a[8] = {200, 200, 300, 50, 400, 200, 200, 200};
    int b[6] = {300, 50, 500, 50, 600, 200};
    int c[10] = {250, 400, 250, 300, 350, 300, 350, 400, 250, 400};

    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    setcolor(BLUE);
    rectangle(200, 200, 400, 400);
    rectangle(400, 200, 600, 400);
    rectangle(450, 250, 550, 350);
    line(475, 250, 475, 350);
    line(500, 250, 500, 350);
    line(525, 250, 525, 350);
    line(450, 275, 550, 275);
    line(450, 300, 550, 300);
    line(450, 325, 550, 325);

    drawpoly(4, a);
    drawpoly(3, b);
    drawpoly(5, c);
    circle(300, 150, 25);

    getch();
    closegraph();
    return 0;
}

