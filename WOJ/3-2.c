#include <stdio.h>
#include <string.h>

typedef struct
{
    int s, del, m;
} Q;

typedef struct
{
    int x, y, r;
} Disk;

Q q[1000];
Disk disk[25];
int top, col[4][6], clen[4], up[25][25], ulen[25];
char f[5], visited[16777216];

int cover(int a, int b, Disk *disk)
{
    int dx = disk[a].x - disk[b].x, dy = disk[a].y - disk[b].y, rr = disk[a].r + disk[b].r;
	if (dx * dx + dy * dy < rr * rr)
        return 1;
    return 0;
}

int main()
{
	int n;
	while (scanf("%d", &n) && n > 0) {
        int i, j, k, a, c, cmax, l, p, r, s, del, m, ans = 0;
		memset(clen, 0, sizeof(clen));
        memset(f, -1, sizeof(f));
        memset(ulen, 0, sizeof(ulen));
        memset(visited, 0, 1 << n);
        cmax = 0;
		for (i = 0; i < n; i++) {
			scanf("%d%d%d%d", &disk[i].x, &disk[i].y, &disk[i].r, &c);
			if (f[c] >= 0)
                c = f[c];
			else
            {
                f[c] = cmax++;
                c = cmax-1;
            }
			col[c][clen[c]++] = i;
		}
		for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++) {
                if (cover(i, j, disk))
                    up[j][ulen[j]++] = i;
		    }
		q[0].s = 0;
        q[0].del = 0;
        q[0].m = n;
        top = 1;
		while (top) {
			s = q[--top].s, del = q[top].del, m = q[top].m;
			if (m <= 1)
                break;
			if (visited[s])
                continue;
			visited[s] = 1;
			for (c = 0; c < cmax; c++)
                if ((l = clen[c]) >= 2)
                    for (p = 0; p < l; p++) {
                        i = col[c][p];
				        if (s & (1<<i))
                            continue;
				        for (k = 0; k < ulen[i]; k++) {
					        a = up[i][k];
					        if (!(s & (1<<a)))
                                goto next;
				        }
				        for (r = p+1; r < l; r++) {
					        j = col[c][r];
					        if (s & (1<<j))
                                continue;
					        for (k = 0; ; k++) {
						        if (k == ulen[j]) {
							        if (del+2 > ans)
                                        ans = del + 2;
							        q[top].s = s | (1<<i) | (1<<j);
                                    q[top].del = del + 2;
                                    q[top++].m = m - 2;
							        break;
						        }
						        a = up[j][k];
						        if (!(s & (1<<a)))
                                    break;
					        }
				        }
				        next:;
			        }
		}
		printf("%d\n", ans);
	}
	return 0;
}