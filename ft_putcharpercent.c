/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharpercent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:45:32 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/11 12:03:52 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	auxstring1(t_flags *flags, char **temp, char **temp2)
{
	if (flags->has_width == 1 && flags->has_left == 0)
	{
		flags->w = ft_positivediff(flags->width, ft_strlen((*temp)));
		flags->spaces = ft_calloc(flags->w, sizeof(char));
		ft_memset(flags->spaces, flags->has_zero == 1 ? '0' : ' ', flags->w);
		flags->spaces[flags->w] = '\0';
		(*temp2) = ft_strjoin(flags->spaces, (*temp));
		free(flags->spaces);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		flags->w = ft_positivediff(flags->width, ft_strlen((*temp)));
		flags->spaces = ft_calloc(flags->w, sizeof(char));
		ft_memset(flags->spaces, ' ', flags->w);
		flags->spaces[flags->w] = '\0';
		(*temp2) = ft_strjoin((*temp), flags->spaces);
		free(flags->spaces);
	}
	else
		(*temp2) = ft_strjoin("", (*temp));
}

static void	s_null(t_flags *flags, char *s, char **temp)
{
	if (s == NULL)
	{
		(*temp) = ft_strjoin("(null)", "");
		if (flags->has_precision == 1)
			(*temp)[flags->precision] = '\0';
	}
	else if ((flags->precision < ft_strlen(s)) && flags->has_precision == 1)
	{
		(*temp) = ft_calloc((ft_min(flags->precision, ft_strlen(s)) + 1),
		sizeof(char));
		ft_memcpy((*temp), s, flags->precision);
	}
	else
	{
		(*temp) = ft_calloc(ft_strlen(s), sizeof(char));
		ft_memcpy((*temp), s, ft_strlen(s));
		(*temp)[ft_strlen(s)] = '\0';
	}
}

void	putcharpercent(char *s , t_flags *flags)
{
	//char	*s;
	char	*temp;
	char	*temp2;

	temp2 = NULL;
	s_null(flags, s, &temp);
	auxstring1(flags, &temp, &temp2);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
    (flags->r_count)--;
	free(temp);
	free(temp2);
}