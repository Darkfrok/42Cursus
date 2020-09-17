/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:05 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/17 18:29:20 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

void	ft_printx(va_list args)
{
	char *x;

	x = va_arg(args, char*);
	ft_putstr_fd("Un entero en base 16 con las letras en minuscula", 1);
}
