#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s!\n", "world");
    _printf("Length: %d\n", len);

    return (0);
}

