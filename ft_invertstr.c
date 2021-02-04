/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invertstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:53:01 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/04 15:04:00 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_invertstr(char *str)
{
	int		len;
	char	temps;
	int		left;
	int		right;

	len = ft_strlen(str);
	left = 0;
	right = len - 1;
	while (left < (len / 2))
	{
		temps = str[left];
		str[left] = str[right];
		str[right] = temps;
		left++;
		right--;
	}
	return (str);
}
