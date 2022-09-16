#include <stdio.h>
#include <stdlib.h>

#define SET_BIT(x,p) ((x) |=  (1<<(p)))
#define CLR_BIT(x,p) ((x) &= ~(1<<(p)))
#define TGL_BIT(x,p) ((x) ^=  (1<<(p)))
#define CHK_BIT(x,p) ((x) &   (1<<(p)))

void Int2BitStr(int x, char *str, int size) {
    if (x == 0) {
        str = "00000000\n";
        printf("%s", str);
    }

    int num[32];
    int i = 0, k = 2;

    while (x > 0) {
        num[i++] = x % 2;
        x /= 2;
    }

    sprintf(str, "%s", "0b");

    for (int j = i - 1 ; j >= 0 ; j--, ++k)
        sprintf(&str[k], "%d", num[j]);

    printf("%s\n", str);
}

int main(void) {
    int dec_num = 204;
    char *bin_num = (char *)malloc(8 * sizeof(char));

    printf("%d in binary from = ", dec_num);
    Int2BitStr(dec_num, bin_num, 0);

    int x = 8, res = 0;

    printf("Manipulations with x = %d\n", x);
    res = SET_BIT(x, 1);
    printf("SET_BIT %d\n", res);

    res = CLR_BIT(x, 1);
    printf("CLR_BIT %d\n", res);

    res = TGL_BIT(x, 11);
    printf("TGL_BIT %d\n", res);

    res = CHK_BIT(x, 18);
    printf("CHK_BIT %d\n", res);

    return 0;
}
