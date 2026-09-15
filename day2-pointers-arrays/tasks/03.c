#include <limits.h>
#include <stdio.h>
#include <string.h>

void reverse(int *a, size_t n) {
    int t;
    for (size_t i = 0; i < (n/2); i++) {
        t = a[i];
        a[i] = a[n - i -1];
        a[n - i -1] = t;
    }
};

void rotate_left(int *a, size_t n, size_t k) {
    if (n == 0) {
        // при сдвиге на 0 ничего не происходит
        return;
    }

    k %= n;

    reverse(a, k);
    reverse(a + k, n - k);
    reverse(a, n);
};

int main()
{
    int n = 0;

    int CAP;

    scanf("%d", &CAP);

    if (CAP == 0) {
        return 0;
    }

    int a[CAP];
    int v;
    while (n < CAP && scanf("%d", &v) == 1)
        a[n++] = v;

    int k;
    scanf("%d", &k);

    printf("исходный: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    reverse(a, n);

    printf("\nобращенный: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    reverse(a, n);
    rotate_left(a, n, k);

    printf("\nсдвиг влево на %d: ", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
