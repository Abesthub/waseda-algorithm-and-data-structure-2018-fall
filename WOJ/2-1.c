#include<stdio.h>

int printAns(int n)
{
    switch (n)
    {
        case 0:
            printf("N\n");
            break;

        case 45:
            printf("NW\n");
            break;

        case 90:
            printf("W\n");
            break;

        case 135:
            printf("SW\n");
            break;

        case 180:
            printf("S\n");
            break;

        case 225:
            printf("SE\n");
            break;

        case 270:
            printf("E\n");
            break;

        case 315:
            printf("NE\n");
            break;
    
        default:
            break;
    }
    return 0;
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d\n", &n);
        if (n==-1)
            break;
        printAns(n);
    }
    return 0;
}