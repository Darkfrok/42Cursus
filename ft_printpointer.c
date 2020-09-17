/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2020/09/17 18:30:00 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

void	ft_printpointer(va_list args)
{
	char *p;

	p = va_arg(args, char*);
	ft_putstr_fd("Esto imprime la direccion de memoria de un puntero", 1);
}
