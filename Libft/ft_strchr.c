/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:48:13 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:51 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cont;
	char	*str;

	str = (char *)s;
	cont = 0;
	while (str[cont] != c)
	{
		if (str[cont] == '\0')
			return (0);
		cont++;
	}
	return (&str[cont]);
}
