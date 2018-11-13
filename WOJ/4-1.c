#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int y;
        scanf("%d", &y);
        if ((y - 1896) % 4 != 0)
        {
            printf("-1\n");
            continue;
        }
        y = (y - 1896) / 4 + 1;
        if (y <= 0)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n", y);
    }
    return 0;
}