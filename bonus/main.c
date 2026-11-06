#include "ft_printf_bonus.h"
#include <stdio.h>

int main()
{
        int b = printf("%+.10p\n", 25);
        int a = ft_printf("%+.10p\n", 25);
      

        printf("a =%d\n", a);
        printf("b =%d\n",b ); 
        return (0);
}