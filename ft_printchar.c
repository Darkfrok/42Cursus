/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 11:50:21 by cquezada          #+#    #+#             */
/*   Updated: 2020/11/20 14:04:25 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void	ft_printchar(va_list args, t_flags *flags)
{
	int w;
	char *temp;
	char *temp2;
	char *spaces;
	int c;

	c = va_arg(args, int);

	// printf("Hasta aqui-2\n");
	// printf("Hasta aqui-1\n");
	temp = ft_calloc(2, sizeof(char));
	if (c == '\0')
	{
		//ft_putchar_fd('\0', 1);
		temp[0] = '\0';
		flags->r_count++;
	}
	else
		temp[0] = c;
	//printf("Hasta aqui0\n");
	if (flags->has_width == 1 && flags->has_left == 0)
	{
		//printf("Hasta aqui\n");
		w = ft_positivediff(flags->width, ft_strlen(temp));
		//printf("w= %i \n", w);
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, flags->has_zero == 1 ? '0' : ' ', w);
		temp2 = ft_strjoin(spaces, temp);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		//printf("Hasta aqui2\n");
		w = ft_positivediff(flags->width, ft_strlen(temp));
		spaces = ft_calloc(w, sizeof(char));
		ft_memset(spaces, ' ', w);
		temp2 = ft_strjoin(temp, spaces);
	}
	else
	{
		//printf("Hasta aqui3\n");
		temp2 = ft_strjoin("", temp);
	}
	ft_putstr_fd(temp2, 1);
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
}
