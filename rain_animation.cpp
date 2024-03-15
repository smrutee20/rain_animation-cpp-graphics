#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

void rain(int x1, int y1, int x2, int y2) {
    int s, dx, dy, m, c = 0, t = 1;
    float xi, yi, x, y;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
        s = abs(dx);
    else
        s = abs(dy);
    xi = dx / (float)s;
    yi = dy / (float)s;
    x = x1;
    y = y1;
    putpixel(x1 + 0.5, y1 + 0.5, 9);
    for (m = 0; m < s; m++) {
        c++;
        x += xi;
        y += yi;
        if (getpixel(x, y) == 4)
            break;
        if (c % 10 == 0)
            t++;
        putpixel(x + 0.5, y + 0.5, 0);
        if (t % 2 == 0)
            putpixel(x + 0.5, y + 0.5, 9);
    }
}

int main() {
    int gd = DETECT, gm = DETECT, c = -200, i = 0, x = 40, l = 15, h = 15, ht = 0;

    initgraph(&gd, &gm, "");
    cleardevice();
    setcolor(BROWN);
    line(0, 201, 600, 201);

cont:
    while (!kbhit()) {
        setcolor(4);
        ellipse(x, 100, 0, 180, 50, 30);
        line(x - 50, 100, x + 50, 100);
        line(x, 100, x, 150);
        circle(x - 20, 115, 15);
        line(x - 20, 130, x - 20, 175);
        line(x - 20, 175, x - 20 - l, 200);
        line(x - 20, 175, x - 20 + l, 200);
        line(x - 20, 140, x, 150);
        line(x - 20, 140, x - 20 - h, 160);
        for (i = 0; i < 620; i += 20) {
            rain(i, c, i, 200);
        }
        c++;
        if (c == 0)
            c = -100;
        setcolor(0);
        delay(50);
        ellipse(x, 100, 0, 180, 50, 30);
        line(x - 50, 100, x + 50, 100);
        line(x, 100, x, 150);
        circle(x - 20, 115, 15);
        line(x - 20, 130, x - 20, 175);
        line(x - 20, 175, x - 20 - l, 200);
        line(x - 20, 175, x - 20 + l, 200);
        line(x - 20, 140, x, 150);
        line(x - 20, 140, x - 20 - h, 160);
        line(x + 50, 100, x + 50, 200);
        x++;
        l--;
        if (l == -15)
            l = 15;
        if (ht == 1)
            h++;
        else
            h--;
        if (h == 15)
            ht = 0;
        else if (h == -15)
            ht = 1;
    }

    if (getch() == ' ') {
        while (!kbhit())
            ;
        getch();
        goto cont;
    }

    closegraph();
    return 0;
}

