#include <stdio.h>
#include <stdlib.h>

 #define H 3
 #define W 3

int main(int argc, char *argv[])
{
    int a[H][W]= {1,2,3,4,5,6,7,8,9};
    int b[H][W]= {2,4,6,8,10,12,14,16,18};
    int c[H][W] = {0};

    int i, j, k;

    for (i = 0; i < H; ++i)
    {
        for(j = 0;j < W; ++j)
        {
            for (k=0; k < H;++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (i = 0; i <H ;++i)
    {
        for (j=0; j<W;++j)
            {
                printf("%-5d", c[i][j]);
            }
        printf("\n");
    }
    return 0;
}
