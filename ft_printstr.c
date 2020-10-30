/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:26:20 by cquezada          #+#    #+#             */
/*   Updated: 2020/10/26 13:48:47 by cquezada         ###   ########.fr       */
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
	if (flags.precision < ft_strlen(s))
	{
		temp = malloc(ft_min(flags.precision, ft_strlen(s))+1);
		ft_memcpy(temp, s, flags.precision);
	}
	else
	{
		temp = malloc((sizeof(char) * ft_strlen(s))+1);
		ft_memcpy(temp, s, ft_strlen(s));
	}
		
		w = ft_ifminus(flags.width ,ft_strlen(temp));
		
		spaces = malloc(w);
		ft_memset(spaces, ' ',w);
		if (flags.tiene_left == 1)
			temp2 = ft_strjoin(temp, spaces);
		else
			temp2 = ft_strjoin(spaces, temp);
	
	ft_putstr_fd(temp2, 1);
}
