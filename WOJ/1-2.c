#include<stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int m, j, k, ans = 0;
        char block[40][40];;
        scanf("%d", &m);
        for(j = 0; j < m + 4; j++)
        {
            for(k = 0; k < m + 4; k++)
            {
                block[j][k] = '0';
            }
        }
        for(j = 2; j < m + 2; j++)
        {
            for(k = 2; k < m + 2; k++)
            {
                scanf("%c", &block[j][k]);
                if (block[j][k]==10)
                    scanf("%c", &block[j][k]);
            }
        }
        for(j = 2; j < m + 2; j++)
        {
            for(k = 2; k < m + 2; k++)
            {
                if ((block[j][k]=='W')&&(block[j][k+1]=='S')&&(block[j][k+2]=='D'))
                    ans++;
                if ((block[j][k]=='W')&&(block[j][k-1]=='S')&&(block[j][k-2]=='D'))
                    ans++;
                if ((block[j][k]=='W')&&(block[j+1][k]=='S')&&(block[j+2][k]=='D'))
                    ans++;
                if ((block[j][k]=='W')&&(block[j-1][k]=='S')&&(block[j-2][k]=='D'))
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}