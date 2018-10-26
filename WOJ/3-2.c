#include<stdio.h>

int main()
{
    while(1)
    {
        int n;
        scanf("%d\n", &n);
        if (n==0)
            break;
        int ans = 0, disk[100][5], flag = 0;
        while(n--)
        {
            scanf("%d %d %d %d\n", &disk[flag][1], &disk[flag][2], &disk[flag][3], &disk[flag][4]);
            int i;
            for(i = flag -1 ; i > 0; i++)
            {
                if (on(disk, i, flag))
                {
                    disk[flag][0] = i;
                    break;
                }
                if (i==0)
                {
                    disk[flag][0] = -1;
                }
            }
            
        }
    }
    return 0;
}