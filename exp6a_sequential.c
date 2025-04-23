//  SEQUENTIAL FILE ALLOCATION

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int f[50], i, st, j, len, c, k;
    // clrscr()
    for (i = 0; i < 50; i++)
        f[i] = 0;
X:
    printf("\nEnter the Starting block and Length of file: ");
    scanf("%d%d", &st, &len);
    for (j = st; j < (st + len); j++)
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d -> %d", j, f[j]);
        }
        else
        {
            printf("Block already allocated");
            break;
        }
    if (j == (st + len))
        printf("\n The file is allocated to disk ");
    printf("\n if u want to enter more files (y-1/n-0)? : ");
    scanf("%d", &c);
    if (c == 1)
        goto X;
    else
        exit(0);
    getch();
}