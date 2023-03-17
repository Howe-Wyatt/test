#include <graphics.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 65535
int main()
{
    initgraph(640, 480, SHOWCONSOLE);// 初始化图形模式
   
    setbkcolor(WHITE);
    cleardevice();


    double x0, y0, x, y, k;
    double temp;
    printf("DDA直线生成算法:（默认数学坐标原点在屏幕（200，200）处）\n ");
    printf("请输入起点（x0，y0): ");
    scanf_s("%lf,%lf", &x0, &y0);
    printf("请输入终点（x，y): ");
    scanf_s("%lf,%lf", &x, &y);

    k = (y - y0) / (x - x0);
    if (k <= 1 && k >= -1) {
        if (k == 0) {
            if (x0 < x) {
                while (x0 <= x) {
                    putpixel(200+x0,200-y0,RED);
                    x0++;
                }
            }
            else {
                while (x0 >= x) {
                    putpixel(200+x0, 200-y0, RED);
                    x0--;
                }
            }
        }
        else {
            if (x0 <= x) {
                while (x0 <= x) {
                    putpixel(200+x0, 200-round(y0), RED);
                    x0++;
                    y0 = y0 + k;
                }
            }
            else {
                temp = x0;
                x0 = x;
                x = temp;
                while (x0 <= x) {
                    putpixel(200 + x0, 200 - round(y0), RED);
                    x0++;
                    y0 = y0 + k;
                }
            }
        }
    }
    else {
        if (k>MAX) {
            if (y0 < y) {
                while (y0 <= y) {
                    putpixel(200 + x0, 200 - y0, RED);
                    y0++;
                }
            }
            else {
                while (y0 >= y) {
                    putpixel(200 + x0, 200 - y0, RED);
                    y0--;
                }
            }
        }
        else {
            if (y0 <= y) {
                while (y0 <= y) {
                    putpixel(200 + round(x0), 200 - y0, RED);
                    y0++;
                    x0 = x0 + 1 / k;
                }
            }
            else {
                temp = x0;
                x0 = x;
                x = temp;
                while (y0 <= y) {
                    putpixel(200 + round(x0), 200 - y0, RED);
                    y0++;
                    x0 = x0 + 1 / k;
                }
            }
        }
    }
    printf("直线绘制结束\n");

    _getch();
    closegraph();
    return 0;
}
