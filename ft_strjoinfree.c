/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:26:18 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/16 17:37:34 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = calloc(sizeof(*dst) * ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		dst[i] = s2[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	free(s1);
	free(s2);
	return (dst);
}
