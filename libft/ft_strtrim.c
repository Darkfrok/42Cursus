/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:50:29 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/03 17:48:41 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_look(char c, const char *set)
{
	int k;
	int len2;

	k = 0;
	len2 = ft_strlen(set);
	while (k < len2)
	{
		if (c == set[k])
			return (1);
		k++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_look(s1[i], set))
		i++;
	while (len > 0 && ft_look(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	new = (char*)malloc(sizeof(char) * (len - i + 1));
	if (!new)
		return (NULL);
	while (i < len)
		new[j++] = (char)s1[i++];
	new[j] = '\0';
	return (new);
}
