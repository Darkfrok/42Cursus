/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:26:20 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/05 19:42:39 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	ft_printstr(va_list args, t_flags flags)
{
	char	*s;
	char	*temp;
	char	*temp2;
	char	*spaces;
	int w;
	s = va_arg(args, char*);
	if ((flags.precision < ft_strlen(s)) && flags.tiene_precision == 1)
	{
		temp = malloc(ft_min(flags.precision, ft_strlen(s))+1);
		ft_memcpy(temp, s, flags.precision);
	}
	else
	{
		temp = malloc((sizeof(char) * ft_strlen(s))+1);
		ft_memcpy(temp, s, ft_strlen(s));
	}
	if (flags.tiene_width == 1)
		w = ft_ifminus(flags.width ,ft_strlen(temp));
	else
		w = ft_strlen(temp);
	spaces = malloc(w);
	ft_memset(spaces, ' ',w);
	temp2 = ft_strjoin(spaces, temp);
	ft_putstr_fd(temp2, 1);
}
