#include<stdio.h>

int getAns(int *ans, int b, int t)
{
    
    while(t!=0)
    {
        ans[++ans[0]] = t % b;
        t = t / b;
    }
    return 0;
}

char chr(int ord)
{
    if (ord<10)
        return '0' + ord;
    return 'A' + ord - 10;
}

int print(int *ans)
{
    while(ans[0]--)
    {
        printf("%c", chr(ans[ans[0] + 1]));
    }
    printf("\n");
    return 0;
}

int main()
{
    int n;
    scanf("%d\n", &n);
    while(n--)
    {
        int b, t, ans[100];
        scanf("%d %d\n", &b, &t);
        ans[0] = 0;
        getAns(ans, b, t);
        print(ans);
    }
    return 0;
}