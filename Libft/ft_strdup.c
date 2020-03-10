/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:52:16 by cquezada          #+#    #+#             */
/*   Updated: 2019/12/02 16:54:52 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		cont1;
	int		cont2;
	char	*new;

	cont1 = 0;
	cont2 = 0;
	while (src[cont1])
		cont1++;
	new = malloc(sizeof(char) * (cont1 + 1));
	if (new == NULL)
		return (NULL);
	while (cont1 > 0)
	{
		new[cont2] = src[cont2];
		cont1--;
		cont2++;
	}
	new[cont2] = '\0';
	return (new);
}
