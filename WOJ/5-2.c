#include<stdio.h>

int main()
{
    while(1)
    {
        int l, i;
        char p = 'a', s[500];
        scanf("%d %s\n", &l, s);
        if (l==0)
            break;
        for(i = 0; i < l; i++)
        {
            switch (s[i])
            {
                case '+':
                    if (p=='z')
                        p = 'a';
                    else
                        p++;
                    break;
                case '-':
                    if (p=='a')
                        p = 'z';
                    else
                        p--;
                    break;
                default:
                    printf("%c", p);
            }
        }
        printf("\n");
    }
    return 0;
}