/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:50:14 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:55:09 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	size_t	slen;

	i = 0;
	if (!s)
		return (0);
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
	{
		new[i] = '\0';
		return (new);
	}
	while (len > 0 && s[start] != '\0')
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
