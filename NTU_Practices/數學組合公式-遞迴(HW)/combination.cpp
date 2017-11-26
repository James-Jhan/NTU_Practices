#include <stdio.h>
#include <stdlib.h>

int comb(int, int);

int main(int argc, char *argv[])
{
    int numN;
    int numM;
    int ans;

    scanf("%d", &numN) ;
    scanf("%d", &numM) ;

    if (numN >= numM)
    {
        ans = comb(numN, numM);
        printf("%d\n", ans);
    }
    else
        printf("input error\n");

    return 0;
}

int comb(int numN, int numM)
{
    if (numN == numM || numM == 0)
        return 1;

    return (comb(numN-1,numM)+comb(numN-1,numM-1));
}
