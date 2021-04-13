#include<iostream>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

void ffill(int x, int y, int fc, int bc) {
    int c;
    c = getpixel(x, y);
    if ((c == bc) && (c != fc)) {
        putpixel(x, y, fc);
        delay(1);
        ffill(x + 1, y, fc, bc);
        ffill(x, y + 1, fc, bc);
        ffill(x - 1, y, fc, bc);
        ffill(x, y - 1, fc, bc);
    }
}

void bfill(int x, int y, int fc, int bc) {
    int c;
    c = getpixel(x, y);
    if ((c != bc) && (c != fc)) {
        putpixel(x, y, fc);
        delay(1);
        bfill(x + 1, y, fc, bc);
        bfill(x, y + 1, fc, bc);
        bfill(x - 1, y, fc, bc);
        bfill(x, y - 1, fc, bc);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1, y1, x2, y2;
    setcolor(1);
    line(100, 50, 200, 50);
    setcolor(2);
    line(200, 50, 200, 100);
    setcolor(3);
    line(200, 100, 100, 100);
    setcolor(4);
    line(100, 100, 100, 50);

    ffill(150, 70, 4, 0);
//    bfill(150,70,8,0);
    getch();
    closegraph();
    return 0;
}
