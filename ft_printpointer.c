/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/10 14:47:10 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	flags->d = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->d, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->d);
	else
		ft_memset(flags->spaces, ' ', flags->d);
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	free(flags->spaces);
}

static void	auxdecimali2(t_flags *flags, char **temp, char **s)
{
	if (flags->has_precision == 1)
	{
		(flags->d) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			flags->d++;
		flags->spaces = ft_calloc((flags->d), sizeof(char));
		ft_memset(flags->spaces, '0', (flags->d));
		free(flags->spaces);
		(*temp) = ft_strjoin(flags->spaces, (*s));
	}
	else
	{
		(*temp) = ft_calloc(ft_strlen((*s)), sizeof(char));
		ft_memcpy((*temp), (*s), ft_strlen((*s)));
		(*temp)[ft_strlen((*s))] = '\0';
	}
}

static void	auxdecimali3(t_flags *flags, char **temp, char **temp2)
{
	if (flags->has_width == 1 && flags->has_left == 0)
		auxdecimali1(flags, temp, temp2);
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		flags->d = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->d, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(flags->spaces, ' ', flags->d);
		else
		{
			ft_memset(flags->spaces,
			flags->has_zero == 1 ? '0' : ' ', flags->d);
		}
		*(temp2) = ft_strjoin(*(temp), flags->spaces);
		free(flags->spaces);
	}
	else
		*(temp2) = ft_strjoin("", *(temp));
}

void	ft_printpointer(va_list args, t_flags *flags)
{
	char	*s;
	char	*temp;
	char	*temp2;

	flags->d = va_arg(args, unsigned int);

	if (flags->d == 0 && flags->has_precision == 1)
	{
		s = malloc(sizeof(char));
		s[0] = '\0';
	}
	else if (flags->d == 0)
	{
		s = malloc(sizeof(char)+1);
		s[0] = '0';
		s[1] = '\0';
	}
	
	else
		s = ft_itohex(flags->d);
    temp = NULL;
	temp2 = NULL;
	auxdecimali2(flags, &temp, &s);
    sustituteminus(temp);
    temp2 = temp;
    temp = ft_strjoin("0x", temp2);
    free(temp2);
	auxdecimali3(flags, &temp, &temp2);
	if (flags->has_zero == 1 && flags->has_width == 1 && temp2[0] == '0')
		sustituteminus(temp2);
	if(flags->has_xmayus == 1){
	//	printf("%s", temp2);
       temp2 = ft_strtoupper(temp2);
	}
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
}
