/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:39:36 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/12 17:41:56 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtoupper(char *str)
{
	int count;
	int i;

	i = 0;
	count = ft_strlen(str);
	while (i <= count)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
