#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void scanline(vector<pair<int, int> > points, int col) {
    int n = points.size() - 1;
    double slope[n + 1];

    for (int i = 0; i < n; i++) {
        int dx = points[i + 1].first - points[i].first;
        int dy = points[i + 1].second - points[i].second;
        if (dx == 0)
            slope[i] = 0.0;
        if (dy == 0)
            slope[i] = 1.0;
        if (dx != 0 && dy != 0)
            slope[i] = 1.0 * dx / dy;
    }
    for (int y = 0; y < 480; y++) {
        vector<int> vecx;
        for (int i = 0; i < n; i++) {
            if ((points[i].second <= y && points[i + 1].second > y) ||
                (points[i + 1].second <= y && points[i].second > y)) {
                int x = points[i].first + 1.0 * slope[i] * (y - points[i].second);
                vecx.push_back(x);
            }
        }
        setcolor(col);
        sort(vecx.begin(), vecx.end());
        for (int i = 1; i < vecx.size(); i += 2) {
            delay(10);
            line(vecx[i - 1], y, vecx[i], y);
        }
    }
}

signed main() {
    int gd = DETECT, gm;
    int n;
    cout << "\nEnter the number of vertices : ";
    cin >> n;

    vector<pair<int, int> > points(n + 1);
    cout << "\nEnter the co-ordinates of the polygon : ";

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    int col;
    cout << "\nEnter the color : ";
    cin >> col;
    points[n] = points[0];
    initgraph(&gd, &gm, NULL);
    setcolor(15);
    for (int i = 1; i <= n; i++) {
        line(points[i].first, points[i].second, points[i - 1].first, points[i - 1].second);
    }
    scanline(points, col);
    getch();
    closegraph();
    return 0;
}

