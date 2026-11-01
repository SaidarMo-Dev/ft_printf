#include "stdio.h"
#include "ft_printf.h"

int main()
{
        int a = printf("%");

        int b = ft_printf("%");

        ft_printf("\na = %d\n", a);
        ft_printf("b = %d\n", b);
}