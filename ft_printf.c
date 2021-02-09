/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:51:15 by llescure          #+#    #+#             */
/*   Updated: 2021/02/09 23:05:42 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			start_printf(const char **str, t_flag *all_flag)
{
	int compt;

	*str = ft_get_start(*str, all_flag);
	ft_initialisation(all_flag);
	compt = ft_parsing(*str, all_flag);
	if (compt == -1)
		return (-1);
	return (compt);
}

void		process_type(const char **str, t_flag *all_flag, va_list arguments)
{
	if (all_flag->type == 'c')
		ft_print_cara(str, all_flag, (char)va_arg(arguments, int));
	if (all_flag->type == '%')
		ft_print_percent(str, all_flag);
	else if (all_flag->type == 's')
		ft_print_string(str, all_flag, va_arg(arguments, char*));
	else if (all_flag->type == 'x')
		ft_print_low_hexa(str, all_flag, va_arg(arguments, int));
	else if (all_flag->type == 'X')
		ft_print_up_hexa(str, all_flag, va_arg(arguments, int));
	else if (all_flag->type == 'u')
		print_unsign(str, all_flag, va_arg(arguments, unsigned int));
	else if (all_flag->type == 'i' || all_flag->type == 'd')
		ft_print_int(str, all_flag, va_arg(arguments, int));
	else if (all_flag->type == 'p')
		print_point(str, all_flag, va_arg(arguments, long unsigned));
}

int			ft_printf(const char *str, ...)
{
	va_list					arguments;
	t_flag					all_flag;
	int						compt;

	va_start(arguments, str);
	all_flag.compt = 0;
	while (str != NULL)
	{
		if ((compt = start_printf(&str, &all_flag)) == -1)
			break ;
		if (all_flag.wildcard > 0)
			process_wildcard(&all_flag, arguments);
		process_type(&str, &all_flag, arguments);
		str = ft_cut_str(str, valid_type(str, compt));
		if (all_flag.compt == -1)
			return (all_flag.compt);
	}
	va_end(arguments);
	return (all_flag.compt);
}
