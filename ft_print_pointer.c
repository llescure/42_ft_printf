/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:36:12 by llescure          #+#    #+#             */
/*   Updated: 2021/02/03 17:09:52 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_space_pointer(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int						i;
	int						number_of_spaces;
	char					*temp1;

	i = 0;
	number_of_spaces = 0;
	while (ft_isdigit(str[i]) != 1)
		i++;
	if (all_flag.number > 0 && ft_isdigit(str[i]) == 1)
		number_of_spaces = ft_extract_number(str, i) - ft_strlen(user_nbr);
	else if (all_flag.wildcard > 0)
		number_of_spaces = all_flag.wildcard_value1 - ft_strlen(user_nbr);
	ft_join_buf_space(buf, number_of_spaces);
	temp1 = *buf;
	*buf = ft_strjoin(*buf, user_nbr);
	free(temp1);
	return (ft_strlen(*buf));
}

int		ft_space_minus_pointer(const char *str, t_flag all_flag, char **buf,
		char *user_nbr)
{
	int								i;
	int								number_of_spaces;
	char							*temp1;

	i = 0;
	number_of_spaces = 0;
	temp1 = *buf;
	*buf = ft_strjoin(*buf, user_nbr);
	free(temp1);
	while (str[i] != '%')
		i++;
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i) - ft_strlen(user_nbr);
	if ((str[i] == '-' && str[i + 1] == '*'))
		number_of_spaces = all_flag.wildcard_value1 - ft_strlen(user_nbr);
	ft_join_buf_space(buf, number_of_spaces);
	return (ft_strlen(*buf));
}

int		print_point(const char *str, t_flag all_flag,
		long unsigned user_nbr,
	char **buf)
{
	char *temp1;
	char *nbr_convert;

	nbr_convert = ft_convert_address(user_nbr, all_flag);
	if (error_case(&all_flag, &str) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0) &&
			(all_flag.minus == 0))
		return (ft_space_pointer(str, all_flag, buf, nbr_convert));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
				all_flag.wildcard > 0))
		return (ft_space_minus_pointer(str, all_flag, buf, nbr_convert));
	else
	{
		temp1 = *buf;
		*buf = ft_strjoin(*buf, nbr_convert);
		free(temp1);
	}
	return ((int)ft_strlen(*buf));
}
