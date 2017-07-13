#include <stdio.h>

int main()
{
    printf("size of int %zu.\n", sizeof(int));

    int i = 0xffffffff;
    unsigned int u = 0xffffffff;
    printf("i %d, u %u.\n", i, u);

    printf("%s\n", (i - i - 1) < 0 ? "signed": "unsigned");
    printf("%s\n", (u - u - 1) < 0 ? "signed": "unsigned");
}
