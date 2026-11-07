#include "ft_printf_bonus.h"
#include <stdio.h>

int main()
{
        int b = printf("%19p\n", 255);
        int a = ft_printf("%19p\n", 255);
      

        printf("a =%d\n", a);
        printf("b =%d\n",b ); 
        return (0);
}