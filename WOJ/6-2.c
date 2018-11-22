#include<stdio.h>
#include<math.h>

int dp[1002][1002], board[1002][1002], prime[1000001];

int init()
{
    int i, j, dir, x, y, nowx, nowy;
    prime[2] = 1;
    for (i = 3; i <= 1000000; i += 2)
        prime[i] = 1;
    for (i = 3; i * i <= 1000000; i += 2)
        if (prime[i])
            for(j = i * i; j <= 1000000; j += i)
                prime[j] = 0;
    for (i = 0; i < 1002; i++)
    {
        board[0][i] = 1;
        board[i][0] = 1;
        board[1001][i] = 1;
        board[i][1001] = 1;
    }
    dir = 0;
    x = 0;
    y = 1;
    for (i = 1000000; i >= 0; i--)
    {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        nowx = x + dx[dir];
        nowy = y + dy[dir];
        if (board[nowy][nowx])
        {
            dir = (dir + 1) % 4;
            nowx = x + dx[dir];
            nowy = y + dy[dir];
        }
        board[nowy][nowx] = i;
        x = nowx;
        y = nowy;
    }
    return 0;
}

int print()
{
    int i, j, q, x, y, m = 1039, n = 1;
    for (x = 1; x < 1001; x++)
        for (y = 1; y < 1001; y++)
            if (board[y][x] == n)
                goto BREAK;
    BREAK:
    q = sqrt(m) / 2 + 1;
    printf("%d %d\n", y, x);
    for (i = 0; y + i < 501 + q; i++)
        for (j = 0; x + j < 501 + q; j++)
            printf("%4d ", board[y + i][x + j]);
    return 0;
}

int main()
{
    int i, j, k, m, n, x, y, ans, max, q;
    init();
    while (scanf("%d %d", &m, &n), m + n)
    {
        for (x = 1; x < 1001; x++)
            for (y = 1; y < 1001; y++)
                if (board[y][x] == n)
                    goto BREAK;
        BREAK:
        for (i = 1; i < 1001; i++)
            for (j = 1; j < 1001; j++)
                dp[i][j] = 0;
        dp[y][x] = (prime[n] == 1);
        max = dp[y][x];
        ans = (max ? n : 0);
        q = sqrt(m - 1) / 2 + 1;
        i = y;
        while ((i < q + 501)&&(i < 1000))
        {
            j = x - (i - y);
            if (j <= 0)
                j = 1;
            while ((j <= x + (i - y))&&(j <= 1001))
            {
                for (k = -1; k < 2; k++)
                {
                    if (board[i + 1][j + k] > m)
                        continue;
                    if ((j + k == 0)||(j + k == 1001))
                        continue;
                    if (dp[i][j] + prime[board[i + 1][j + k]] > dp[i + 1][j + k])
                        dp[i + 1][j + k] = dp[i][j] + prime[board[i + 1][j + k]];
                    if ((max == dp[i + 1][j + k])&&(prime[board[i + 1][j + k]]))
                        if (ans < board[i + 1][j + k])
                            ans = board[i + 1][j + k];
                    if (max < dp[i + 1][j + k])
                    {
                        max = dp[i + 1][j + k];
                        ans = board[i + 1][j + k];
                    }
                }
                j++;
            }
            i++;
        }
        printf("%d %d\n", max, ans);
    }
    return 0;
}