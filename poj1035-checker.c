#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char dict[10001][20];
char query[20];

int len[20];
int idx[20][10000];

int m;
int res[10000];

int
compare(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

int
strdist(char *x, char *y)
{
    int i, j, lx, ly, res;

    lx = strlen(x);
    ly = strlen(y);
    res = 0;
    if (lx > ly) return strdist(y, x);
    else if (lx == ly)
    {
        for (i = 0; i < lx; i++)
        {
            if (x[i] != y[i]) res++;
        }
        return res;
    }
    else
    {
        i = j = 0;
        while (i < lx && j < ly)
        {
            if (x[i] != y[j]) j++, res++;
            else i++, j++;
        }
        return res + lx - i + ly - j;
    }
}

int
main()
{
    int i, j, flag;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    for (i = 0; i < 20; i++) len[i] = 0;
    n = 0;
    while (scanf("%s", dict[n]), strcmp(dict[n], "#") != 0)
    {
        idx[strlen(dict[n])][len[strlen(dict[n])]] = n;
        len[strlen(dict[n])]++;
        n++;
    }
    while (scanf("%s", query), strcmp(query, "#") != 0)
    {
        m = 0;
        j = strlen(query);
        flag = 1;
        for (i = 0; i < len[j] && flag; i++)
        {
            int dist = strdist(query, dict[idx[j][i]]);
            if (dist == 0) flag = 0;
            if (dist == 1) res[m++] = idx[j][i];
        }
        for (i = 0; i < len[j - 1] && flag; i++)
        {
            if (strdist(query, dict[idx[j - 1][i]]) == 1) res[m++] = idx[j - 1][i];
        }
        for (i = 0; i < len[j + 1] && flag; i++)
        {
            if (strdist(query, dict[idx[j + 1][i]]) == 1) res[m++] = idx[j + 1][i];
        }

        if (flag == 0) printf("%s is correct\n", query);
        else
        {
            qsort(res, m, sizeof(int), compare);
            printf("%s:", query);
            for (i = 0; i < m; i++) printf(" %s", dict[res[i]]);
            printf("\n");
        }
    }

    return 0;
}
