#include <stdio.h>
#include <stdlib.h>

 #define N 5

 struct student
 {
     int math;
     int eng;
     int comp;
 };
 typedef struct student stu;

int main(int argc, char *argv[])
{
    stu s[N];
    float sum[3] = {0};
    int i;
    int op;
    int n = 0;
    int classNo = 0;
    while(1)
    {
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                scanf("%d", &s[n].math);
                scanf("%d", &s[n].eng);
                scanf("%d", &s[n].comp);
                ++n;
                break;
            case 2:
                scanf("%d", &classNo);
                printf("%d\n", s[classNo -1].math);
                printf("%d\n", s[classNo -1].eng);
                printf("%d\n", s[classNo -1].comp);
                break;
            case 3:
                scanf("%d", &classNo);
                scanf("%d", &s[classNo -1].math);
                scanf("%d", &s[classNo -1].eng);
                scanf("%d", &s[classNo -1].comp);
                break;
            case 4:
                for (i = 0; i < n; ++i)
                {
                    printf("%d\n", s[i].math);
                    printf("%d\n", s[i].eng);
                    printf("%d\n", s[i].comp);
                }
                break;
            case 5:
                for (i = 0; i < n; ++i)
                {
                    sum[0] += s[i].math;
                    sum[1] += s[i].eng;
                    sum[2] += s[i].comp;
                }

                printf("%.2f\n", (double)sum[0]/n);
                printf("%.2f\n", (double)sum[1]/n);
                printf("%.2f\n", (double)sum[2]/n);
                break;
            case 6:
                scanf("%d", &classNo);
                printf("%.2f\n", (double)(s[classNo -1].math + s[classNo -1].eng + s[classNo -1].comp)/3);
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
