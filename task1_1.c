#include <stdio.h>

#define MIN(A,B) ((A) <= (B) ? (A) : (B))
#define MAX(A,B) ((A) >= (B) ? (A) : (B))

int min(int a, int b) {
    return a <= b ? a : b;
}

int main(void) {
    int x1 = 3, x2 = 3;
    int y1 = 5, y2 = 5;

    printf("MIN(%d, %d) = %d;\n", x1, y1, MIN(x1++, y1));
    printf("MIN(%d, %d) = %d;\n", x1, y1, MIN(++x1, y1));
    printf("min(%d, %d) = %d;\n", x2, y2, min(++x2, y2));
    printf("min(%d, %d) = %d;\n", x2, y2, min(x2++, y2));

    return 0;
}
