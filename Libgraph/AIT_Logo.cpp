#include<iostream>
#include<cstdlib>
#include<graphics.h>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    setcolor(BLUE);

    int a[8] = {200, 150, 169, 205, 232, 205, 200, 150};
    int b[18] = {169, 230, 232, 230, 232, 250, 211, 250, 211, 275, 190, 275, 190, 250, 169, 250, 169, 230};

    fillpoly(4, a);
    drawpoly(9, b);
    floodfill(195, 250, BLUE);

    circle(200, 200, 150);
    line(99, 275, 200, 100);
    line(200, 100, 301, 275);
    line(166, 275, 99, 275);
    line(301, 275, 234, 275);

    line(159, 230, 159, 250);
    line(159, 250, 149, 250);
    line(149, 250, 159, 230);

    line(242, 230, 242, 250);
    line(242, 250, 252, 250);
    line(242, 230, 252, 250);

    getch();
    closegraph();
    return 0;
}
