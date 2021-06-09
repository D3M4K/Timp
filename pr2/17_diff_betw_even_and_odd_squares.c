#include <stdio.h>
#include <math.h>
int main()
{
int n;
int i =1;
int x;
int summ =0;


(void)scanf("%d", &n);

for(i; i <= n; i++)
{
    (void)scanf("%d", &x);
summ += pow(-1, (double)i)*x*x;
}
printf("%d", summ);
return 0;
} 