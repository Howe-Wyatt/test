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
    initgraph(640, 480, SHOWCONSOLE);// ��ʼ��ͼ��ģʽ
   
    setbkcolor(WHITE);
    cleardevice();


    double x0, y0, x, y, k;
    double temp;
    printf("DDAֱ�������㷨:��Ĭ����ѧ����ԭ������Ļ��200��200������\n ");
    printf("��������㣨x0��y0): ");
    scanf_s("%lf,%lf", &x0, &y0);
    printf("�������յ㣨x��y): ");
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
    printf("ֱ�߻��ƽ���\n");

    _getch();
    closegraph();
    return 0;
}
