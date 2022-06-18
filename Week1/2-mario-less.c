#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0;
    do
    {
        h = get_int("Width: ");
    }
    while (h < 1 || h > 8);
    for (int i = 1; i <= h; i++)
    {
        for (int j = h; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}