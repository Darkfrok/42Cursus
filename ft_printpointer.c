/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/16 14:44:10 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	//printf("tempA19 %s \n", temp);
	//printf("tempB20 %s \n", temp2);
	flags->d = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->d + 1, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->d);
	else
		ft_memset(flags->spaces, ' ', flags->d);
	//printf("tempA21 %s \n", temp);
	//printf("tempB22 %s \n", temp2);
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	free(flags->spaces);
	//free(*(temp2));
}

static void	auxdecimali2(t_flags *flags, char **temp, char **s)
{
	//printf("tempA3 %s \n", temp);
	if (flags->has_precision == 1)
	{
		//printf("tempA5 %s \n", temp);
		(flags->d) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			flags->d++;
		flags->spaces = ft_calloc((flags->d), sizeof(char));
		ft_memset(flags->spaces, '0', (flags->d));
		free(flags->spaces);
		//printf("tempA7 %s \n", temp);
		(*temp) = ft_strjoin(flags->spaces, (*s));
	}
	else
	{
		//printf("tempA9 %s \n", (*temp));
		(*temp) = ft_calloc(ft_strlen((*s)), sizeof(char));
		ft_memcpy((*temp), (*s), ft_strlen((*s)));
		(*temp)[ft_strlen((*s))] = '\0';
		//printf("tempA11 %s \n", (*temp));
	}
}

static void	auxdecimali3(t_flags *flags, char **temp, char **temp2)
{
	if (flags->has_width == 1 && flags->has_left == 0)
	{
		//printf("tempA17 %s \n", *(temp));
		//printf("tempB18 %s \n", *(temp2));
		ft_bzero(*(temp2), ft_strlen(*(temp2)));
		free(*(temp2));
		auxdecimali1(flags, temp, temp2);
		//printf("tempA23 %s \n", *(temp));
		//printf("tempB24 %s \n", *(temp2));
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		//printf("tempA25 %s \n", *(temp));
		//printf("tempB26 %s \n", *(temp2));
		flags->d = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->d + 1, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(flags->spaces, ' ', flags->d);
		else
		{
			//printf("tempA27 %s \n", *(temp));
			//printf("tempB28 %s \n", *(temp2));
			ft_memset(flags->spaces,
			flags->has_zero == 1 ? '0' : ' ', flags->d);
		}
		//printf("tempA29 %s \n", *(temp));
		//printf("tempB30 %s \n", *(temp2));
		*(temp2) = ft_strjoin(*(temp), flags->spaces);
		free(flags->spaces);
	}
	else
		*(temp2) = ft_strjoin("", *(temp));
}

void		ft_printpointer(va_list args, t_flags *flags, int *pos)
{
	char			*s;
	char			*temp;
	char			*temp2;
	unsigned long	d;

	d = va_arg(args, unsigned long);
	if (d == 0 && flags->has_precision == 1)
	{
		s = ft_calloc(sizeof(char), 1);
		s[0] = '\0';
	}
	else if (d == 0)
	{
		s = ft_calloc(sizeof(char) + 1, 1);
		s[0] = '0';
		s[1] = '\0';
	}
	else
		s = ft_longtohex(d);
	temp = NULL;
	temp2 = NULL;
	//printf("tempA1 %s \n", temp);
	//printf("tempB2 %s \n", temp2);
	auxdecimali2(flags, &temp, &s);
	//printf("tempA13 %s \n", temp);
	//printf("tempB14 %s \n", temp2);
	temp2 = temp;
	temp = ft_strjoin("0x", temp2);
	//printf("tempA15 %s \n", temp);
	//printf("tempB16 %s \n", temp2);
	if (flags->has_width == 1 || flags->has_precision == 1)
	{
		free(temp2);
		temp2 = NULL;
	}
	auxdecimali3(flags, &temp, &temp2);
	//printf("tempA31 %s \n", temp);
	//printf("tempB32 %s \n", temp2);
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
	(*pos)++;
}
