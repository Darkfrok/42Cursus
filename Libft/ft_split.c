/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:38 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/03 17:48:19 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		**ft_mallocsize(char const *s, char c)
{
	char	*aux;
	char	**aux2;
	int		i;

	i = 0;
	aux = (char*)s;
	while (*aux)
	{
		while (*aux == c)
			aux++;
		if (*aux != '\0')
			i++;
		while (*aux != c && *aux)
			aux++;
	}
	aux2 = (char**)malloc((i + 1) * sizeof(char*));
	if (aux2 == NULL)
		return (NULL);
	aux2[i] = NULL;
	return (aux2);
}

static char		**ft_copy(const char *s, char c)
{
	size_t	len;
	char	**new;
	int		i;

	i = 0;
	len = 0;
	new = ft_mallocsize(s, c);
	if (new == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			while (s[len] != c && s[len])
				len++;
			new[i++] = ft_substr(s, 0, len);
			s += len;
		}
		len = 0;
	}
	new[i] = NULL;
	return (new);
}

char			**ft_split(char const *s, char c)
{
	char **new;

	if (!s)
		return (NULL);
	new = ft_copy(s, c);
	return (new);
}
