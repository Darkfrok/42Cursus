/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:17:39 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/04 15:06:07 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char    *ft_itohex (int decimalnum)
{
	int quotient;
	int remainder;
	char *str;
	int j;
    char hexadecimalnum[100];
	
	j = 0;
    quotient = decimalnum;
 
    while (j < 100)
    {
        hexadecimalnum[j] = '\0';
        j++;
    }
    j = 0;
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    j = ft_strlen(str);
    str = ft_strdup(hexadecimalnum);
   // printf("%zu", ft_strlen(str));
    //printf("\n");
    ft_invertstr(str);
    return (str);
}

int main(void)
{
	printf("%s" ,ft_itohex(45000));
    printf("\n");
}