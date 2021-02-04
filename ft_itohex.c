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

char    *ft_itohex(va_list args, t_flags *flags)
{
	int quotient;
	int remainder;
	char *str;
	int j;
    char hexadecimalnum[100];
	
	j = 0;
    quotient = (flags->x = va_arg(args, int));
 
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
        else if (flags->has_xminus == 1)
            hexadecimalnum[j++] = 87 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    str = ft_strdup(hexadecimalnum);
    ft_invertstr(str);
    return (str);
}
