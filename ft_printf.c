/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:51:15 by llescure          #+#    #+#             */
/*   Updated: 2021/01/28 19:41:12 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *str, ...)
{
	va_list					arguments;
	int						compt;
	int						number_wildcard;
	int						start;
	t_flag					all_flag;
	char					*buf;

	start = 0;
	va_start(arguments, str);
	ft_initialisation(&all_flag);
	compt = ft_parsing_part1(str, &all_flag, start);
	ft_get_buf_start(str, compt, &buf);
	while (start < (int)ft_strlen(str))
	{
		ft_initialisation(&all_flag);
		compt = ft_parsing_part1(str, &all_flag, start);
		start = ft_where_type_is(str, compt);
		if (start == -1)
		{
			compt = ft_strlen(buf);
			break ;
		}
		number_wildcard = all_flag.wildcard;
		while (number_wildcard > 0 && number_wildcard < 3)
		{
			conv_wildcard(va_arg(arguments, int), number_wildcard, &all_flag);
			number_wildcard--;
		}
		if (all_flag.type == 'c')
			ft_print_cara(str, all_flag, (char)va_arg(arguments, int), &buf);
		if (all_flag.type == '%')
			ft_print_percent(str, all_flag, &buf);
		else if (all_flag.type == 's')
			ft_print_string(str, all_flag, va_arg(arguments, char*), &buf);
		else if (all_flag.type == 'x')
			ft_print_low_hexa(str, all_flag, va_arg(arguments, int), &buf);
		else if (all_flag.type == 'X')
			ft_print_up_hexa(str, all_flag, va_arg(arguments, int), &buf);
		else if (all_flag.type == 'u')
			print_unsign(str, all_flag, va_arg(arguments, unsigned int), &buf);
		else if (all_flag.type == 'i' || all_flag.type == 'd')
			ft_print_int(str, all_flag, va_arg(arguments, int), &buf);
		else if (all_flag.type == 'p')
			print_point(str, all_flag, va_arg(arguments, long unsigned), &buf);
		compt = ft_strlen(buf) + ft_get_buf_end(str, &buf, all_flag, start + 1);
	}
	va_end(arguments);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (compt);
}
