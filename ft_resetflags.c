/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darkfrok <darkfrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:54:27 by darkfrok          #+#    #+#             */
/*   Updated: 2020/09/07 11:03:34 by darkfrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	resetflags(t_flags *flags)
{
	flags->tiene_width = 0;
	flags->width = 0;
}