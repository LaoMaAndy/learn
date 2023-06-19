#include <stdio.h>

int c[8];
int n = sizeof(c) / sizeof(*c);
int total = 0;

int is_ok(int row)
{
    int j;

    for(j = 0; j < row; j++)
    {
        if(c[row] == c[j] || row - c[row] == j - c[j] || row + c[row] == j + c[j])
            return 0;
    }
    return 1;
}
void queen(int row)
{
    int col;

    if(row == n)
        total++;
    else
        for(col = 0; col < n; col++)
        {
            c[row] = col;
            if(is_ok(row))
                queen(row + 1);
        }       
}

int main()
{
    queen(0);
    printf("total: %d\n", total);
    return 0;
}