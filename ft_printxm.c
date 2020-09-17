/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:03:22 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/17 19:01:17 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

void	ft_printxm(va_list args)
{
	char *xm;

	xm = va_arg(args, char*);
	ft_putstr_fd("Entero en base 16 con las letras en MAYUSCULAS", 1);
}
