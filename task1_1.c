#include <stdio.h>

#define MIN(A,B) ((A) <= (B) ? (A) : (B))
#define MAX(A,B) ((A) >= (B) ? (A) : (B))

int min(int a, int b) {
    return (a) <= (b) ? (a) : (b);
}

int main(void) {
    int x1 = 3, x2 = 3;
    int y1 = 5, y2 = 5;

    printf("MIN(%d, %d) = %d;\n", x1, y1, MIN(x1++, y1));
    printf("MIN(%d, %d) = %d;\n", x1, y1, MIN(++x1, y1));

    printf("min(%d, %d) = %d;\n", x2, y2, min(++x2, y2));
    printf("min(%d, %d) = %d;\n", x2, y2, min(x2++, y2));

    /* In the first MIN macro use we see, that one of the operands have postfix increment.
     * That gives us understanding that x will be incremented after x value will be returned
     * for next operations. So in ((x1++) <= (y1)) x will increment by 1 (x1 == 4) and after that in
     * (x1++) : (y1) x will increment again (x1 == 5). After those operations x will become 5.
     * In second macro usage firstly x1 will increment, so it will become 6, and then macro will compare
     * those two numbers adb the result will be 5, because x1(6) > y1(5).
     *
     * In case of min function we have different behaviour. In the first case x2 is incrementing and after that
     * passing to the min function. In the second case x2 is incrementing too, but the value that is passing
     * to the function is different. That's because in the second call compiler pass "original" value of x2,
     * which is 4 but not the incremented one.
    */
    return 0;
}
