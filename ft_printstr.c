/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:26:20 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/09 03:35:04 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

void	ft_printstr(va_list args)
{
	char *s;

	s = va_arg(args, char*);

	ft_putstr_fd(s, 1);
}