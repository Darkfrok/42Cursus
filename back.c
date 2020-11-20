void	ft_checkflags(const char *str, t_flags *flags, int *pos)
{
	int len;

	len = 0;
	if (str[*pos] == '-')
	{
		while (str[*pos] == '-')
			(*pos)++;
		flags->has_left = 1;
	}
	if (str[*pos] == '0')
	{
		while (str[*pos] == '0')
			(*pos)++;
		flags->has_zero = 1;
	}
	if (ft_isdigit(str[*pos]) == 1)
	{
		flags->has_width = 1;
		flags->width = ft_atoi(&str[*pos]);
		//printf("Hola \n");
		while (ft_isdigit(str[*pos] == 1))
		{
			(*pos)++;
			printf("Hola \n");
		}

	}
	len = 0;
	if (str[*pos] == '.')
	{
		(*pos)++;
		flags->has_precision = 1;
		flags->precision = ft_atoi(&str[*pos]);
		while (str[*pos] != 's')
		{
			(*pos)++;
		}
	}
}