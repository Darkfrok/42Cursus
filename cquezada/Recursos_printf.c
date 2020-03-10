/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Recursos_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:53:58 by cquezada          #+#    #+#             */
/*   Updated: 2020/03/05 17:01:36 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funciones/libft.h"

int	ft_printf(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		ft_putchar(str[j]);
		j++;
	}
	return (0);
}
int	main(void)
{
	ft_printf("Hola mundo");
}
