#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int num[3], min = 10000000, j, k;
        scanf("%d %d %d", &num[0], &num[1], &num[2]);
        for(j = 0; j < 2; j++)
        {
            for(k = j + 1; k < 3; k++)
            {
                if (abs(num[j] - num[k]) < min)
                    min = abs(num[j] - num[k]);
            }
        }
        printf("%d\n", min);
    }
    return 0;
}