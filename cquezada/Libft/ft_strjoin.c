/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:04 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:54 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * ft_strlen(s1) + ft_strlen(s2) + 1);
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
	return (dst);
}
