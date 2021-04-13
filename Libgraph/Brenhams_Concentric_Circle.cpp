#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;
int t;

class circl {
public:
    void circleDDA(int xc, int yc, int r) {
        float xc1, xc2, yc1, yc2, eps, sx, sy;
        int val, i;
        xc1 = r;
        yc1 = 0;
        sx = xc1;
        sy = yc1;
        i = 0;
        do {
            val = pow(2, i);
            i++;
        } while (val < r);
        eps = 1 / pow(2, i - 1);
        do {
            xc2 = xc1 + yc1 * eps;
            yc2 = yc1 - eps * xc2;
            if (t < 3)
                delay(10);
            putpixel(xc + xc2, yc - yc2, 3);
            xc1 = xc2;
            yc1 = yc2;
        } while ((yc1 - sy) < eps || (sx - xc1) > eps);
    }

    void drawCircle(int xc, int yc, int x, int y) {
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc - y, yc + x, RED);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc - y, yc - x, RED);
    }

    void circleBres(int xc, int yc, int r) {
        int x = 0, y = r;
        int d = 3 - 2 * r;
        drawCircle(xc, yc, x, y);
        while (y >= x) {
            x++;
            if (d > 0) {
                y--;
                d = d + 4 * (x - y) + 10;
            } else
                d = d + 4 * x + 6;
            drawCircle(xc, yc, x, y);
            if (t < 3)
                delay(50);
        }
    }
};

int main() {
    while (1) {
        circl c;
        int xc, yc, r;
        int gd = DETECT, gm;
        cout << "\n**************************************MENU**************************************";
        cout
                << "\n1. Circle using Bresenhams\n2. Circle using DDA\n3. Concentric Circle (Bresenhams)\n4. Concentric Circle (DDA) \n5. Exit\nEnter the choice: ";
        cin >> t;
        cout << "Enter the co-ordinates of center: ";
        cin >> xc >> yc;
        switch (t) {
            case 1:
                cout << "\nEnter the radius of circle: ";
                cin >> r;
                initgraph(&gd, &gm, NULL);
                c.circleBres(xc, yc, r);
                getch();
                break;

            case 2:
                cout << "\nEnter the radius of circle: ";
                cin >> r;
                initgraph(&gd, &gm, NULL);
                c.circleDDA(xc, yc, r);
                getch();
                break;
            case 3:
                initgraph(&gd, &gm, NULL);
                c.circleBres(xc, yc, 10);
                delay(1000);
                c.circleBres(xc, yc, 20);
                delay(1000);
                c.circleBres(xc, yc, 30);
                delay(1000);
                c.circleBres(xc, yc, 40);
                delay(1000);
                c.circleBres(xc, yc, 50);
                delay(1000);
                c.circleBres(xc, yc, 60);
                delay(1000);
                c.circleBres(xc, yc, 70);
                delay(1000);
                c.circleBres(xc, yc, 80);
                break;
            case 4:
                initgraph(&gd, &gm, NULL);
                c.circleDDA(xc, yc, 10);
                delay(1000);
                c.circleDDA(xc, yc, 20);
                delay(1000);
                c.circleDDA(xc, yc, 30);
                delay(1000);
                c.circleDDA(xc, yc, 40);
                delay(1000);
                c.circleDDA(xc, yc, 50);
                delay(1000);
                c.circleDDA(xc, yc, 60);
                delay(1000);
                c.circleDDA(xc, yc, 70);
                delay(1000);
                c.circleDDA(xc, yc, 80);
                break;
            case 5:
                return 0;
                break;
        }
    }
    return 0;
}
