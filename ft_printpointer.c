/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquezada <cquezada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:20:59 by cquezada          #+#    #+#             */
/*   Updated: 2021/02/15 14:22:22 by cquezada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	auxdecimali1(t_flags *flags, char **temp, char **temp2)
{
	////printf("test\n");
	flags->d = ft_positivediff(flags->width, ft_strlen(*temp));
	flags->spaces = ft_calloc(flags->d + 1, sizeof(char));
	if ((flags->precision >= flags->width && flags->has_zero == 1) ||
	(flags->has_zero == 1 && flags->has_width == 1 &&
	flags->has_precision == 0))
		ft_memset(flags->spaces, '0', flags->d);
	else
		ft_memset(flags->spaces, ' ', flags->d);
	//printf("tempA13 %s \n", *(temp));
	//printf("tempB14 %s \n", *(temp2));
	////printf("tempjos %s \n", flags->spaces);
	*(temp2) = ft_strjoin(flags->spaces, *(temp));
	//free(temp);
	////printf("tempjos %s \n", flags->spaces);
	//printf("tempA15 %s \n", *(temp));
	//printf("tempB16 %s \n", *(temp2));
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
		//printf("tempA1 %s \n", *(temp));
		////printf("tempaux2 %s \n", temp2);
		(*temp) = ft_strjoin(flags->spaces, (*s));
		//printf("tempB2 %s \n", *(temp));
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
		//printf("tempA9 %s \n", *(temp));
		//printf("tempB10 %s \n", *(temp2));
	if (flags->has_width == 1 && flags->has_left == 0)
	{
		//printf("tempA11 %s \n", *(temp));
		//printf("tempB12 %s \n", *(temp));
		ft_bzero(*(temp2), ft_strlen(*(temp2)));
		free(*(temp2));
		auxdecimali1(flags, temp, temp2);
	}
	else if (flags->has_width == 1 && flags->has_left == 1)
	{
		//printf("test7\n");

		flags->d = ft_positivediff(flags->width, ft_strlen(*(temp)));
		flags->spaces = ft_calloc(flags->d + 1, sizeof(char));
		if (flags->precision < flags->width)
			ft_memset(flags->spaces, ' ', flags->d);
		else
		{
			//printf("tempA17 %s \n", temp);
			//printf("tempB18 %s \n", temp2);
			ft_memset(flags->spaces,
			flags->has_zero == 1 ? '0' : ' ', flags->d);
		}
		//printf("tempA19 %s \n", temp);
		//printf("tempB20 %s \n", temp2);
		*(temp2) = ft_strjoin(*(temp), flags->spaces);
		free(flags->spaces);
		//free(*(temp));
		//printf("tempA21 %s \n", temp);
		//printf("tempB22 %s \n", temp2);
	}
	else
	{
		*(temp2) = ft_strjoin("", *(temp));
		//free(temp2);
		////printf("test8\n");
	}
}

void		ft_printpointer(va_list args, t_flags *flags)
{
	char	*s;
	char	*temp;
	char	*temp2;
	unsigned long d;

	

	d = va_arg(args, unsigned long);

	if (d == 0 && flags->has_precision == 1)
	{
		////printf("test9\n");
		s = ft_calloc(sizeof(char), 1);
		s[0] = '\0';
	}
	else if (d == 0)
	{
		////printf("test10\n");
		s = ft_calloc(sizeof(char)+1, 1);
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
	//printf("tempA3 %s \n", temp);
	//printf("tempB4 %s \n", temp2);
    temp2 = temp;
	 //printf("tempA5 %s \n", temp);
	 //printf("tempB6 %s \n", temp2);
	////printf("test11\n");
    temp = ft_strjoin("0x", temp2);
	//printf("tempA7 %s \n", temp);
	//printf("tempB8 %s \n", temp2);
	////printf("test12\n");
    //free(temp2);///////////////////////////
	auxdecimali3(flags, &temp, &temp2);
	//printf("tempA23 %s \n", temp);
	//printf("tempB24 %s \n", temp2);

	// if(flags->has_xmayus == 1){
	// //	////printf("%s", temp2);
    //    temp2 = ft_strtoupper(temp2);
	// }
	////printf("test13\n");
	//printf("tempA25 %s \n", temp);
	//printf("tempB26 %s \n", temp2);
	ft_putstr_fd(temp2, 1);
	////printf("test14\n");
	(flags->r_count) += ft_strlen(temp2);
	free(temp);
	free(temp2);
	free(s);
}
