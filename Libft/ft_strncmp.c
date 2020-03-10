/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:50:50 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:55:00 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	cont;
	unsigned char	*str1;
	unsigned char	*str2;

	cont = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[cont] == str2[cont] && str1[cont] != '\0' && str2[cont] !=
'\0' && cont < n - 1)
		cont++;
	return (str1[cont] - str2[cont]);
}
