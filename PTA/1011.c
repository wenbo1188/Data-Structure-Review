#include <stdio.h>

int main()
{
    float rate_w = 0.0, rate_t = 0.0, rate_l = 0.0;
    float product = 1.0;
    char res[3] = {0};
    for (int i = 0;i < 3;++i)
    {
        scanf("%f %f %f", &rate_w, &rate_t, &rate_l);
        if (rate_w > rate_t)
        {
            if (rate_w > rate_l)
            {
                product *= rate_w;
                res[i] = 'W';
            }
            else
            {
                product *= rate_l;
                res[i] = 'L';
            }
        }
        else
        {
            if (rate_l > rate_t)
            {
                product *= rate_l;
                res[i] = 'L';
            }
            else
            {
                product *= rate_t;
                res[i] = 'T';
            }
        }
    }

    for (int i = 0;i < 3;++i)
    {
        printf("%c ", res[i]);
    }
    printf("%.2f", (product * 0.65 - 1) * 2.0);
    return 0;
}