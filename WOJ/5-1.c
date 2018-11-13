#include<stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int a, b, ans;
        scanf("%d %d", &a, &b);
        ans = a + b;
        if (ans>=90)
            printf("A+\n");
        else if (ans>=80)
            printf("A\n");
        else if (ans>=70)
            printf("B\n");
        else if (ans>=60)
            printf("C\n");
        else if (ans>=1)
            printf("F\n");
        else
            printf("G\n");
    }
    return 0;
}