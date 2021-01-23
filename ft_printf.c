/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:51:15 by llescure          #+#    #+#             */
/*   Updated: 2021/01/23 16:13:40 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag		ft_initialisation(t_flag *all_flag)
{
	all_flag->wildcard = 0;
	all_flag->wildcard_value1 = 0;
	all_flag->wildcard_value2 = 0;
	all_flag->minus = 0;
	all_flag->dot = 0;
	all_flag->zero = 0;
	all_flag->number = 0;
	all_flag->type = '0';
	return (*all_flag);
}

int			ft_where_type_is(const char *str, int i)
{
	int compt;

	compt = i;
	while (str[compt] != '\0')
	{
		if ((str[compt] == 'c') || (str[compt] == 's') ||
				(str[compt] == 'p') || (str[compt] == 'x') ||
				(str[compt] == 'X') || (str[compt] == 'X') ||
				(str[compt] == 'i') || (str[compt] == 'd') ||
				(str[compt] == 'u'))
			return (compt);
		if ((str[compt + 1] == '%'))
			return (compt + 1);
		compt++;
	}
	return (-1);
}

t_flag		ft_parse_flag(const char *str, int start, int end,
		t_flag *all_flag)
{
	int i;

	i = start;
	while (i < end)
	{
		if (str[i] == '*')
			all_flag->wildcard = all_flag->wildcard + 1;
		else if (str[i] == '-')
			all_flag->minus = all_flag->minus + 1;
		else if (str[i] == '.')
			all_flag->dot = all_flag->dot + 1;
		else if (str[i] == '0' && ft_isdigit(str[i - 1]) == 0)
			all_flag->zero = all_flag->zero + 1;
		else if (ft_isdigit(str[i]) == 1)
			all_flag->number = all_flag->number + 1;
		i++;
	}
	all_flag->type = str[i];
	return (*all_flag);
}

int			ft_parsing(const char *str, t_flag *all_flag)
{
	int i;
	int pos_percent;

	i = 0;
	pos_percent = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			pos_percent = i;
			i = ft_where_type_is(str, i);
			if (i > pos_percent)
			{
				*all_flag = ft_parse_flag(str, pos_percent, i, all_flag);
				return (pos_percent);
			}
			return (i);
		}
		i++;
	}
	return (i);
}

int			ft_printf(const char *str, ...)
{
	va_list					arguments;
	int						compt;
	int						number_wildcard;
	t_flag					all_flag;
	char					*buf;

	va_start(arguments, str);
	all_flag = ft_initialisation(&all_flag);
	compt = ft_parsing(str, &all_flag);
	number_wildcard = all_flag.wildcard;
	if (ft_get_buf_start(str, compt, &buf) == -1)
		return (-1);
	while (number_wildcard > 0 && number_wildcard < 3)
	{
		ft_convert_wildcard(va_arg(arguments, int), number_wildcard, &all_flag);
		number_wildcard--;
	}
	if (all_flag.type == 'c')
		compt = ft_print_cara(str, all_flag, (char)va_arg(arguments, int), &buf);
	if (all_flag.type == '%')
		compt = ft_print_percent(str, all_flag, &buf);
	else if (all_flag.type == 's')
		compt = ft_print_string(str, all_flag, va_arg(arguments, char*), &buf);
	/*else if (all_flag.type == 'p')
		compt = ft_print_pointer(str, all_flag, va_arg(arguments, void*), &buf);
	else if (all_flag.type == 'x')
		compt = ft_print_lower_hexa(str, all_flag, va_arg(arguments, int), &buf);
	else if (all_flag.type == 'X')
		compt = ft_print_upper_hexa(str, all_flag, va_arg(arguments, int), &buf);
	else if (all_flag.type == 'u')
		compt = ft_print_signed_int(str, all_flag, va_arg(arguments, unsigned int), &buf);
	else if (all_flag.type == 'i' || all_flag.type == 'd')
		compt = ft_print_unsigned_int(str, all_flag, va_arg(arguments, int), &buf);*/
	compt = compt + ft_get_buf_end(str, &buf, all_flag);
	va_end(arguments);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (compt);
}
