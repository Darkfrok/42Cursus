/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:26:20 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/17 10:17:03 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	ft_printstr(va_list args, t_flags *flags)
{
	char	*s;
	char	*temp;
	char	*temp2;
	char	*spaces;
	int w;

	s = va_arg(args, char*);
	if (s == NULL)
	{
		temp = ft_strjoin("(null)", "");
	}
	else if ((flags->precision < ft_strlen(s)) && flags->tiene_precision == 1)
	{
		temp = ft_calloc((ft_min(flags->precision, ft_strlen(s)) + 1),
		sizeof(char));
		ft_memcpy(temp, s, flags->precision);
	}
	else
	{
		temp = ft_calloc(ft_strlen(s), sizeof(char));
		ft_memcpy(temp, s, ft_strlen(s));
		temp[ft_strlen(s)] = '\0';
	}
	if (flags->tiene_width == 1 && flags->tiene_left == 0)
	{
		w = ft_ifminus(flags->width, ft_strlen(temp));
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, ' ', w);
		temp2 = ft_strjoin(spaces, temp);
	}
	else if (flags->tiene_width == 1 && flags->tiene_left == 1)
	{
		w = ft_ifminus(flags->width, ft_strlen(temp));
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, ' ', w);
		temp2 = ft_strjoin(temp, spaces);
	}
	else
		temp2 = ft_strjoin("", temp);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
}
