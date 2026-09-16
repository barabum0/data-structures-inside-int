#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *grow(int *a, size_t len, size_t new_cap) {
    if (new_cap == 0) {
        return NULL;
    }

    int *new;
    if (new_cap > SIZE_MAX / sizeof *a) {
        return NULL;
    }

    new = malloc(new_cap * sizeof *new);
    if (new == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        new[i] = a[i];
    }

    free(a);

    return new;
}

int main() {
    int *a = malloc(1 * sizeof *a);
    size_t old_cap = 1;

    size_t grow_amount = 0;
    size_t i = 0;
    int v;
    while (scanf("%d", &v) == 1) {
        if (i++ >= old_cap - 1) {
            size_t new_cap = old_cap + 1;
            int *new = grow(a, old_cap, new_cap);
            if (new == NULL) {
                return 1;
            }
            a = new;
            old_cap = new_cap;
            grow_amount++;
        }
        printf("address: %p\ncap: %ld\n", a, old_cap);
        a[i] = v;
    }

    free(a);

    printf("\nвыросли %ld раз\nэлементов: %ld\nвместимость: %ld\nсвободно: %ld\n", grow_amount, i, old_cap, old_cap-i);
};
