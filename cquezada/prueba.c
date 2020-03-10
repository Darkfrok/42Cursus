/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:04:09 by cquezada          #+#    #+#             */
/*   Updated: 2020/03/05 17:11:52 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funciones/libft.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int cont;

	cont = 0;
	while (str[cont] != '\0')
	{
		ft_putchar(str[cont]);
		cont++;
	}
}

int		main(void)
{
	ft_putstr("Hola mundo \n");
	return (0);
}
