//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool ehPrimo(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0 && n != i)
            return false;
    }

    return true;
}

int main() {
    int n, p1, p2;

    scanf("%d", &n);

    if (n % 2 == 0)
        n--;

    for (int i = n; i >= 5; i -= 2) {
        if (ehPrimo(i)) {
            if (ehPrimo(i - 2)) {
                p1 = i - 2;
                p2 = i;
                break;
            }
        }
    }

    printf("%d %d\n", p1, p2);
    return 0;
}