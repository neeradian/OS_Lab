// LRU ALGORITHM

#include <stdio.h>
#include<conio.h>

int f[30], fs;
int cnt[30];
int flag, ps[30];
int main()
{
    int p, i, pos = 0, j, k, max, s, pf = 0;
    float pfr;
    void increment();
    int check();
    // clrscr();
    printf("Enter no. of pages: ");
    scanf("%d", &p);
    printf("Enter the pages: \n");
    for (i = 0; i < p; i++)
        scanf("%d", &ps[i]);
    printf("Enter the frame size: ");
    scanf("%d", &fs);
    for (k = 0; k < fs; k++)
        f[k] = -999;
    for (i = 0, j = 0; i < p; i++)
    {
        flag = 0;
        if (f[i] == -999)
        {
            check(j, ps[j]);
            if (flag == 0)
            {
                f[j] = ps[i];
                pf++;
                for (k = 0; k <= j; k++)
                    cnt[k] += 1;
                j++;
            }
        }
        else
        {
            check(fs, ps[i]);
            if (flag == 0)
            {
                max = cnt[0], pos = 0;
                for (k = 1; k < fs; k++)
                    if (max < cnt[k])
                        max = cnt[k], pos = k;
                f[pos] = ps[i], pf++;
                increment(ps[i]);
            }
        }
        for (k = 0; k < fs; k++)
            printf("%4d\t", f[k]);
        printf("\n");
    }
    pfr = (float)pf / p;
    printf("Total no of page faults: %d\n", pf);
    printf("Page faults rare: %0.2f", pfr);
    getch();
}

void increment(int ele)
{
    int k;
    for (k = 0; k < fs; k++)
    {
        if (f[k] == ele)
            cnt[k] = 1;
        else
            cnt[k] += 1;
    }
}

int check(int pos, int ele)
{
    int k, s;
    for (k = 0; k < fs; k++)
        if (f[k] == ele)
        {
            cnt[k] = 1;
            for (s = 0; s < pos; s++)

                if (s != k)
                    cnt[s] += 1;
            flag = 1;
        }
}