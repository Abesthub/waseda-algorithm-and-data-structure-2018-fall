#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double lenTriangleA(int s, double a)
{
    return sqrt(s * s - a * a);
}

double lenTriangleB(int a, int b)
{
    return sqrt(a * a + b * b);
}

double lenSquare(int x1, int y1, int x2, int y2)
{
    return lenTriangleB(x1 - x2, y1 - y2);
}

int cross(int x1, int y1, double r1, int x2, int y2, double r2)
{
    if (r1 + r2 - lenSquare(x1, y1, x2, y2) >= -0.0000001)
        return 1;
    else
        return 0;
}

int legal(double h, int n, int (*p)[3])
{
    int i, j, k;
    for (i = 0; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
            for (k = j + 1; k < n; k++)
            {
                
                if 
                    return 1;
            }
    return 0;
}

double search(double l, double r, int n, int (*p)[3])
{
    if (r - l < 0.000001)
        return r;
    else
    {
        double m = (r + l) / 2.0;
        printf("%lf %lf %lf\n", l, m, r);
        if (legal(m, n, p))
            return search(m, r ,n ,p);
        else
            return search(l, m, n, p);
    }
}

int main()
{
    while(1)
    {
        int n, i, p[10][3], max = 1000000;
        scanf("%d\n", &n);
        if (n==0)
            break;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d\n", &p[i][1], &p[i][2], &p[i][0]);
            if (p[i][0]<max)
                max = p[i][0];
        }
        printf("%.6lf\n", search(1.0, max, n, p));
    }
    return 0;
}