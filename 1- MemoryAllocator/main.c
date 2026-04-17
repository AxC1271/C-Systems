#include <stdio.h>

void *my_malloc(size_t size);
void my_free(void *ptr);

int main() {
    char *a = my_malloc(100);
    char *b = my_malloc(200);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    my_free(a);
    char *c = my_malloc(50);
    printf("c: %p\n", c);  // should reuse a's block
    return 0;
}