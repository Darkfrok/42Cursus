/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimali.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:28:00 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/17 18:16:47 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

void	ft_printdecimali(va_list args)
{
	char d;

	d = va_arg(args, int);
	ft_putnbr_fd(d, 1);
}
