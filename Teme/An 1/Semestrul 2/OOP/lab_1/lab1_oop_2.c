#include <stdio.h>

int main()
{
    int s = 0, nr, n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nr);
        s += nr;
    }
    printf("%d", s);
}
