#include<graphics.h>
#include<math.h>
#include<iostream>

using namespace std;

class Cir {
public:
    float e, s_x, s_y, r, val, i, x2, y2, x1, y1, y0, x0;

    void acc() {
        cout << "Enter the x, y and radius respectively:\n";
        cin >> x0 >> y0 >> r;
    }

    void dis() {
        x1 = r * cos(0);
        y1 = r * sin(0);
        s_x = x1;
        s_y = y1;
        i = 0;
        do {
            val = pow(2, i);
            i++;
        } while (val < r);
        e = 1 / pow(2, i - 1);
        do {
            x2 = x1 + y1 * e;
            y2 = y1 - e * x2;
            putpixel(200 - x2, 200 + y2, 7);
            x1 = x2;
            y1 = y2;
            delay(15);
        } while ((y1 - s_y) < e || (s_x - x1) > e);
    }
};

int main() {
    float e, s_x, s_y, r, val, i, x2, y2, x1, y1, y0, x0;
    Cir c1;
    c1.acc();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    c1.dis();
    getch();
    closegraph();
    return 0;
}
