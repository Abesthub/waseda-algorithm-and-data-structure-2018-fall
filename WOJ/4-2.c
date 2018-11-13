#include<stdio.h>
#include<string.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int ans, j;
        char s[100];
        scanf("%d %s", &ans, s);
        for(j = 0; j < strlen(s); j++)
        {
            if (s[j]=='w')
                ans += 3;
            if (s[j]=='c')
                ans = ans / 2;
            if (ans==0)
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}