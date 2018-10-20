#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    if (*((int *)a) < *((int *)b))
        return -1;
    else
        return 1;
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d\n", &n);
        if (n==0)
            break;
        int i, city[100], sum = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &city[i]);
        qsort(city, n, sizeof(int), cmp);
        for(i = 0; i < n-1; i++)
        {
            sum+=abs(city[i] - city[i+1]);
        }
        printf("%d\n", sum);
    }
    return 0;
}