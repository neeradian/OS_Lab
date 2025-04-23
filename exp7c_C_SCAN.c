// C-SCAN DISK SCHEDULING ALGORITHM

#include <stdio.h>
#include <conio.h>

void main()
{
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;
    // clrscr();
    printf("\nEnter the no of tracks to be traversed: ");
    scanf("%d", &n);
    printf("Enter the position of head: ");
    scanf("%d", &h);
    t[0] = 0;
    t[1] = h;
    printf("Enter total tracks: ");
    scanf("%d", &tot);
    t[2] = tot - 1;
    printf("Enter the tracks: ");
    for (i = 3; i <= n + 2; i++)
        scanf("%d", &t[i]);
    for (i = 0; i <= n + 2; i++)
        for (j = 0; j <= (n + 2) - i - 1; j++)
            if (t[j] > t[j + 1])
            {
                for (i = 0; i <= n + 2; i++)
                    if (t[i] == h)
                    {
                        j = i;
                        break;
                    }
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
    p = 0;
    while (t[j] != tot - 1)
    {
        atr[p] = t[j];
        j++;
        p++;
    }
    atr[p] = t[j];
    p++;
    i = 0;
    while (p != (n + 3) && t[i] != t[h])
    {
        atr[p] = t[i];
        i++;
        p++;
    }
    for (j = 0; j < n + 2; j++)
    {
        if (atr[j] > atr[j + 1])
            d[j] = atr[j] - atr[j + 1];
        else
            d[j] = atr[j + 1] - atr[j];
        sum += d[j];
    }
    printf("\nTotal head movement: %d", sum);
    printf("\nAverage head movement: %0.2f", (float)sum / n);
    getch();
}