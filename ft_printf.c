/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:51:15 by llescure          #+#    #+#             */
/*   Updated: 2021/01/29 23:23:34 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char 		*ft_cut_str(const char *str, int compt)
{
	char *temp;
	char *str_cut;
	int i;

	if (valid_type(str, 0) == -1)
		return (NULL);
	i = compt + 1;
	temp = ft_strdup(str);
	str_cut = ft_strdup(&temp[i]);
	free(temp);
	return (str_cut);

}

int			ft_printf(const char *str, ...)
{
	va_list					arguments;
	int						compt;
	int						number_wildcard;
	t_flag					all_flag;
	char					*buf;
	int					rslt;

	va_start(arguments, str);
	ft_get_buf_start(str, &buf);
	rslt = ft_strlen(buf);
	while (str != NULL)
	{
		ft_initialisation(&all_flag);
		compt = ft_parsing(str, &all_flag);
		if (compt == -1)
			break ;
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
		str = ft_cut_str(str, valid_type(str, compt));
		rslt = ft_strlen(buf) + ft_get_buf_end(str, &buf, all_flag);
	}
	va_end(arguments);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (rslt);
}
