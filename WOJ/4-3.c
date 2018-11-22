#include<stdio.h>

int h, w, c, max, xd[] = {1, 0, -1, 0}, yd[] = {0, 1, 0, -1};

int changeColor(int bfr[10][10], int panel[10][10], int color, int x, int y)
{
    int i, cnt = 1;
    panel[y][x] = color;
    for (i = 0; i < 4; i++)
        if ((bfr[y + yd[i]][x + xd[i]]==bfr[y][x])&&(panel[y + yd[i]][x + xd[i]]!=color))
            cnt += changeColor(bfr, panel, color, x + xd[i], y + yd[i]);
    return cnt;
}

void dfs(int time, int color, int bfr[10][10])
{
    int panel[10][10], i, j, cnt = 0;
    for(i = 0; i < 10; i++)
    for(j = 0; j < 10; j++)
        panel[i][j] = bfr[i][j];
    if (time < 4)
    {
        for (i = 1; i <= 6; i++)
        {
            if (i==color)
                continue;
            cnt = changeColor(bfr, panel, i, 1, 1);
            dfs(time + 1, i, panel);
        }
    }
    else if (time==4)
    {
        cnt = changeColor(bfr, panel, c, 1, 1);
        dfs(time + 1, c, panel);
    }
    else if (time==5){
        cnt = changeColor(bfr, panel, 7, 1, 1);
        if (max < cnt)
            max = cnt;
    }
}

int main()
{
    int i, j;
    while(1)
    {
        max = 0;
        int panel[10][10] = {};
        scanf("%d %d %d", &h, &w, &c);
        if ((h==0)&&(w==0)&&(c==0)) 
            break;
        for (i = 1; i <= h; i++)
            for(j = 1; j <= w; j++)
                scanf("%d", &panel[i][j]);
        dfs(0, panel[1][1], panel);
        printf("%d\n", max);
    }
    return 0;
}