#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the color to red
    setcolor(YELLOW);

    // Draw a curve using connected line segments
    for (int i = 0; i <= 360; i++) {
        int x = i;
        int y = 50 * sin(i * 3.14 / 180) + 100;
        if (i == 0) {
            // Move the pen to the starting point of the curve
            moveto(x+15, y+200);
        } else {
            // Draw a line segment from the previous point to the current point
            lineto(x+15, y+200);
        }
    }

    getch();
    closegraph();

    return 0;
}
