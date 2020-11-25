/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:38:22 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:55:02 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cont;
	char	*str;

	str = (char *)s;
	cont = ft_strlen(str);
	while (0 != cont && str[cont] != (char)c)
		cont--;
	if (str[cont] == (char)c)
		return ((char *)&str[cont]);
	return (0);
}
