// LINKED FILE ALLOCATION

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int f[50], p, i, j, k, a, st, len, n, c;
    // clrscr();
    for (i = 0; i < 50; i++)
        f[i] = 0;
    printf("\nEnter how many blocks that are already allocated : ");
    scanf("%d", &p);
    printf("\nEnter the blocks no's that are already allocated : ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a);
        f[a] = 1;
    }
X:
    printf("Enter the Starting index block & length: ");
    scanf("%d%d", &st, &len);
    k = len;
    for (j = st; j < (k + st); j++)
    {
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d -> %d", j, f[j]);
        }
        else
        {
            printf("\n %d -> file is already allocated", j);
            k++;
        }
    }
    printf("\n If u want to enter one more file (yes-1/no-0) ? : ");
    scanf("%d", &c);
    if (c == 1)
        goto X;
    else
        exit(0);
    getch();
}