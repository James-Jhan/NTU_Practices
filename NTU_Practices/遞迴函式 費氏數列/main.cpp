#include <stdio.h>
#include <stdlib.h>

int fib(int);

int main(int argc, char *argv[])
{
    int in;
    int ans;

    scanf("%d", &in) ;

    ans = fib(in);
    printf("%d\n", ans);

    return 0;
}

int fib(int in)
{
    if (in == 1 || in == 2)
        return 1;

    return (fib(in-2)+fib(in-1));
}
