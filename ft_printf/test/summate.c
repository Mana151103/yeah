#include <stdarg.h>
#include <stdio.h>

int summate(int n, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, n);
    for (; n; n--)
        i += va_arg(ap, int);
    va_end(ap);
    return i;
}

int main(void)
{
    int result = summate(4, 10, 20, 30, 40);
    printf("sum = %d\n",result);
    return 0;
}