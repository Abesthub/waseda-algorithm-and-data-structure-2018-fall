#include<stdio.h>

int is[5001];

int judge(int n)
{
    int i;
    for (i = 2; i < 5001; i++)
        if ((is[i])&&(n % i == 0)&&(is[n / i]))
        {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}

int main()
{
    int i, j;
    for (i = 1; i < 5001; i++)
        is[i] = 1;
    is[1] = 0;
    for (i = 2; i < 5001; i++)
        if (is[i])
        {
            is[i] = 1;
            for(j = 2; j < 5001; j++)
                if (i * j < 5001)
                    is[i * j] = 0;
                else
                    break;
        }
    while(1)
    {
        int n;
        scanf("%d", &n);
        if (n==0)
            break;
        judge(n);
    }
    return 0;
}