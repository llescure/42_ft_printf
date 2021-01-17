/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:51:15 by llescure          #+#    #+#             */
/*   Updated: 2021/01/17 22:39:00 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_initialisation(t_flag all_flag)
{
	all_flag->wildcard = -1;
	all_flag->minus = -1;
	all_flag->dot = -1;
	all_flag->zero = -1;
	all_flag->number = -1;
	all_flag->type = '0';
	return (all_flag);
}

int		ft_where_type_is(const star *str, int i)
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
		compt++;
	}
	return (i - compt);
}

t_flag		ft_parse_flag(const star *str, int start, int end, 
		t_flag all_flag)
{
	int i;
	
	i = start;
	while (i < end)
	{
		if (str[i] == '*')
			all_flag->wildcard = wildcard * -1;
		else if (str[i] == '-')
			all_flag->minus = minus * -1;
		else if (str[i] == '.')
			all_flag->dot = dot * -1;
		else if (str[i] == '0')
			all_flag->zero = zero * -1;
		else if (ft_isdigit(str[i]) == 1)
			all_flag->number = 1;
		i++;
	}
	all_flag->types = str[i];
	return (all_flag);
}

int		ft_parsing(const char *str, t_flag all_flag)
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
				all_flag = ft_parse_flag(str, pos_percent, 
						i, all_flag);
			return (i);
		}
		i++;
	}
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list arguments;
	int compt;
	t_flag all_flag;

	va_start(arguments, read);
	ft_initialisation(all_flag);
	compt = ft_parsing(str, all_flag);
	if (compt == ft_strlen(str) || all_flag->type == '0')
		ft_putstr_fd(str);
	if (va_arg(arguments, int) && all_flag->wildcard > 0)
		//To be completed in cases where we have a wildcard
	else if (all_flag->type == 'c')
		ft_print_cara(str, all_flag, compt, va_arg(arguments, char));
	else if (all_flag->type == 's')
		ft_print_string(str, all_flag, compt, va_arg(arguments, char*));
	else if (all_flag->type == 'p')
		ft_print_pointer(str, all_flag, compt, va_arg(arguments, void*));
	else if (all_flag->type == 'x')
		ft_print_lower_hexa(str, all_flag, compt, va_arg(arguments, int));
	else if (all_flag->type == 'X')
		ft_print_upper_hexa(str, all_flag, compt, va_arg(arguments, int));
	else if (all_flag->type == 'u')
		ft_print_signed_int(str, all_flag, compt, va_arg(arguments, unsigned int));
	else if (all_flag->type == 'i' || all_flag->type == 'd')
		ft_print_unsigned_int(str, all_flag, compt, va_arg(arguments, int));
	va_end(arguments);
	return (compt);
}
