#include <stdio.h>

int main()
{
    int n, all = 0, x, i=1;

    (void)scanf("%d", &n);

    for(i; i <= n; i++)
    {
        (void)scanf("%d", &x);
        if(x < 0)
        {
            all++;
        }

    }
    printf("%d", all);
    return 0;
}