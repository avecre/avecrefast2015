#include<stdio.h>
#include<math.h>

int main(void)
{
    double num = 10
    double x[num];
    double u[num-2];

    for (i=0; i<=num-1; i++)
    {
        x[i] = cos(2*i*M_PI/10);
    }
    for (i=0; i<=num-3; i++)
    {
        u[i] = (x[i]+x[i+1]+x[i+2])/3
    }
    return 0;
}
