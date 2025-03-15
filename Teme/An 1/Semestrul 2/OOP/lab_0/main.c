#include <stdio.h>

int main() {
    int n, s = 0, nr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nr);
        s += nr;
    }
    printf("Suma numerelor este: %d \n", s);
    return 0;
}
