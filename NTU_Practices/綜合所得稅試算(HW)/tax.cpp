#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int in;
    int dis;
    double taxRate;

    scanf("%d", &in);

    if (in >=0 && in <370000)
    {
        dis = 0;
        taxRate = 0.06;
    }
    else if (in >370000 && in <= 990000)
    {
        dis = 25900;
        taxRate = 0.13;
    }
    else if (in > 990000 && in <= 1980000)
    {
        dis = 105100;
        taxRate = 0.21;
    }
    else if (in > 1980000 && in <= 3720000)
    {
        dis = 283300;
        taxRate = 0.3;
    }
    else
    {
        dis = 655300;
        taxRate = 0.4;
    }

    printf("income %d\n", in);
    printf("tax rate %.0f%%\n",taxRate * 100);
    printf("tax %.0f\n", in * taxRate);
    printf("discount %d\n", dis);
    printf("taxpay %.0f\n", in * taxRate - dis);

    return 0;
}
