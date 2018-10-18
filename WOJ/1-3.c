#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[10010];

int find(int lp)
{
    int cc = 1, ans = lp;
    while(cc){
        char c = s[++ans];
		if (c=='[')
			cc++;
		if (c==']')
			cc--;
    }
    return ans;
}

int cmp(const void *a, const void *b)
{
    if (*((int *)a) < *((int *)b))
        return -1;
    else
        return 1;
}

int ans(int st, int ed)
{
    int a[5000], nd, lp, rp, v;
    if (s[st + 1]=='[')
    {
        nd = 0;
        lp = st + 1;
        while(lp < ed){
            rp = find(lp);
            a[nd++] = ans(lp, rp);
            lp = rp + 1;
        }
        qsort(a, nd, sizeof(int), cmp);
        v = 0;
        int i;
        for(i = 0; i < (nd + 1) / 2; i++)
            v += a[i];
        return v;
    }
    else
    {
        sscanf(&s[st + 1], "%d", &v);
        return (v + 1) / 2;
    }
}

int main()
{
    int n, i;
    scanf("%d\n", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s\n", s);
        printf("%d\n", ans(0, strlen(s) - 1));
    }
    return 0;
}