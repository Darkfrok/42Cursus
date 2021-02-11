/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/11 15:36:07 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	////printf("test\n");
	flags->d = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->d, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->d);
	else
		ft_memset(flags->spaces, ' ', flags->d);
	//printf("tempjo %s \n", *(temp));
	//printf("tempjo %s \n", *(temp2));
	//printf("tempjos %s \n", flags->spaces);
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	//printf("tempjos %s \n", flags->spaces);
	//printf("tempin %s \n", *(temp));
	//printf("tempin %s \n", *(temp2));
	free(flags->spaces);
		////printf("test2\n");
}

static void	auxdecimali2(t_flags *flags, char **temp, char **s)
{
		////printf("test3\n");
	if (flags->has_precision == 1)
	{
		(flags->d) = ft_positivediff(flags->precision, ft_strlen((*s)));
		if ((*s)[0] == '-' && flags->precision > ft_strlen((*s)))
			flags->d++;
		flags->spaces = ft_calloc((flags->d), sizeof(char));
		ft_memset(flags->spaces, '0', (flags->d));
		free(flags->spaces);
		//printf("tempaux2 %s \n", *(temp));
		////printf("tempaux2 %s \n", temp2);
		(*temp) = ft_strjoin(flags->spaces, (*s));
		//printf("tempaux2f %s \n", *(temp));
		////printf("tempaux2f %s \n", temp2);
		////printf("test4\n");
	}
	else
	{
		(*temp) = ft_calloc(ft_strlen((*s)), sizeof(char));
		ft_memcpy((*temp), (*s), ft_strlen((*s)));
		(*temp)[ft_strlen((*s))] = '\0';
		////printf("test5\n");
	}
}

static void	auxdecimali3(t_flags *flags, char **temp, char **temp2)
{
		//printf("test6\n");
		//printf("temp %s \n", *(temp));
		//printf("temp %s \n", *(temp2));
	if (flags->has_width == 1 && flags->has_left == 0)
	{
		//printf("tempif %s \n", *(temp));
		//printf("tempif %s \n", *(temp));
		ft_bzero(*(temp2), ft_strlen(*(temp2)));
		free(*(temp2));
		auxdecimali1(flags, temp, temp2);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		//printf("test7\n");

		flags->d = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->d, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(flags->spaces, ' ', flags->d);
		else
		{
			//printf("temp11 %s \n", temp);
			//printf("temp12 %s \n", temp2);
			ft_memset(flags->spaces,
			flags->has_zero == 1 ? '0' : ' ', flags->d);
		}
		//printf("temp7 %s \n", temp);
		//printf("temp8 %s \n", temp2);
		*(temp2) = ft_strjoin(*(temp), flags->spaces);
		free(flags->spaces);
		//printf("temp9 %s \n", temp);
		//printf("temp10 %s \n", temp2);
	}
	else
		*(temp2) = ft_strjoin("", *(temp));
		////printf("test8\n");
}

void	ft_printpointer(va_list args, t_flags *flags)
{
	char	*s;
	char	*temp;
	char	*temp2;
	unsigned long d;

	

	d = va_arg(args, unsigned long);

	if (d == 0 && flags->has_precision == 1)
	{
		////printf("test9\n");
		s = malloc(sizeof(char));
		s[0] = '\0';
	}
	else if (d == 0)
	{
		////printf("test10\n");
		s = malloc(sizeof(char)+1);
		s[0] = '0';
		s[1] = '\0';
	}
	
	else
	{
		s = ft_longtohex(d);
	}
    temp = NULL;
	temp2 = NULL;
	////printf("hola\n");
	auxdecimali2(flags, &temp, &s);
    //sustituteminus(temp);
	//printf("temp1 %s \n", temp);
	//printf("temp2 %s \n", temp2);
    temp2 = temp;
	// printf("temp3 %s \n", temp);
	// printf("temp4 %s \n", temp2);
	////printf("test11\n");
    temp = ft_strjoin("0x", temp2);
	//printf("temp5 %s \n", temp);
	//printf("temp6 %s \n", temp2);
	////printf("test12\n");
    //free(temp2);
	auxdecimali3(flags, &temp, &temp2);
	//printf("temp  Final %s \n", temp);
	//printf("temp Final %s \n", temp2);

	// if(flags->has_xmayus == 1){
	// //	////printf("%s", temp2);
    //    temp2 = ft_strtoupper(temp2);
	// }
	////printf("test13\n");
	////printf("temp %s \n", temp);
	ft_putstr_fd(temp2, 1);
	////printf("test14\n");
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
}
