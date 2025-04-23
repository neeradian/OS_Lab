#include <stdio.h>

void main(int agrc, char *argv[])
{
    int temp, i, n, j, p[10], burst[10], b[10], wait[10], turn[10], b1[10], p1[10];
    float w = 0, t = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    burst[0] = 0;
    for (i = 1; i <= n; i++)
    {
        printf("Enter the Burst Time and Priority ");
        scanf("%d%d", &b1[i], &p[i]);
    }
    for (i = 1; i <= n; i++)
    {
        p1[i] = p[i];
    }
    for (j = 1; j <= n; j++)
    {
        p1[j] = p[j];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d", p[i]);
    }
    printf("\n\t\t\t Gantt Chart\n");
    printf("\t___________________________________________________________\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (p[i] == p[j])
            {
                b[i] = b1[j];
                printf("\t\tP%d", j);
            }
        }
    }
    printf("\t\n\t_________________________________________________________\n\t");
    j = 0;
    for (i = 1; i <= n; i++)
    {
        j = j + b[i];
        wait[i + 1] = j;
        turn[i] = j;
        printf("%d\t\t", j);
    }
    for (i = 1; i <= n; i++)
    {
        t = t + turn[i];
    }
    w = w + wait[i];
    w = w / n;
    t = t / n;
    printf("\nThe average waiting time is %0.2f", w);
    printf("\nThe average turn around time is %0.2f", t);
}