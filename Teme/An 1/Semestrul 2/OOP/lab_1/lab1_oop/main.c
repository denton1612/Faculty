#include <stdio.h>

int main(void)
{
    float s = 0, nr = 1;
    while (nr != 0)
    {
        scanf("%f", &nr);
        s += nr;
    }
    printf("Suma este: %f \n", s);
}
