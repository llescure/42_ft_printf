/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:47:02 by llescure          #+#    #+#             */
/*   Updated: 2021/01/23 16:57:42 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		str_error_case(t_flag all_flag)
{
	if (all_flag.zero > 0 && all_flag.dot == 0)
		return (-1);
	if (all_flag.minus > 0 && all_flag.wildcard == 0 &&
		all_flag.number == 0)
		return (-1);
	if ((all_flag.wildcard > 2) || (all_flag.minus > 1) || (all_flag.dot > 1) ||
		(all_flag.zero > 1))
		return (-1);
	return (0);
}

int		ft_precision_string(const char *str, t_flag all_flag)
{
	int								i;
	int								number_of_char;

	i = 0;
	number_of_char = 0;
	while (str[i] != '.')
		i++;
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
		number_of_char = ft_extract_number(str, i);
	else if (str[i - 1] == '*' && str[i] == '.' && str[i + 1] == '*')
		number_of_char = all_flag.wildcard_value2;
	else if (str[i] == '.' && str[i + 1] == '*')
		number_of_char = all_flag.wildcard_value1;
	return (number_of_char);
}

int		ft_space_string(const char *str, t_flag all_flag, char **buf,
		char *user_str)
{
	int						i;
	int						number_of_spaces;
	int						number_of_char;
	char					*temp1;
	char					*temp2;

	i = 0;
	number_of_char = ft_strlen(user_str);
	number_of_spaces = 0;
	if (all_flag.dot > 0)
		number_of_char = ft_precision_string(str, all_flag);
	while (ft_isdigit(str[i] != 1))
		i++;
	if (number_of_char > (int)ft_strlen(user_str))
			number_of_char= ft_strlen(user_str);
	if (all_flag.number > 0)
		number_of_spaces = ft_extract_number(str, i) - number_of_char;
	else if (all_flag.wildcard > 0)
		number_of_spaces = all_flag.wildcard_value1 - number_of_char;
	ft_join_buf_space(buf, number_of_spaces);
	temp2 = ft_trim(user_str, 0, number_of_char);
	if (temp2 != NULL)
	{
		temp1 = *buf;
		*buf = ft_strjoin(*buf, temp2);
		free(temp1);
	}
	free(temp2);
	return (ft_strlen(*buf));
}

int		ft_space_minus_string(const char *str, t_flag all_flag, char **buf,
		char *user_str)
{
	int								i;
	int								number_of_spaces;
	int								number_of_char;
	char							*temp1;
	char							*temp2;

	i = 0;
	number_of_spaces = 0;
	number_of_char = ft_strlen(user_str);
	if (all_flag.dot > 0)
		number_of_char = ft_precision_string(str, all_flag);
	temp1 = *buf;
	temp2 = ft_trim(user_str, 0, number_of_char);
	*buf = ft_strjoin(*buf, temp2);
	free(temp1);
	free(temp2);
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i) - number_of_char;
	else if (str[i] == '-' && str[i + 1] == '*')
		number_of_spaces = all_flag.wildcard_value1 - number_of_char;
	if ((ft_join_buf_space(buf, number_of_spaces)) == -1)
		return (-1);
	return (ft_strlen(*buf));
}

int		ft_print_string(const char *str, t_flag all_flag, char *user_str,
	char **buf)
{
	char *temp1;
	char *temp2;

	temp2 = user_str;
	if (str_error_case(all_flag) < 0)
		return (-1);
	if (user_str == NULL)
		temp2 = "(null)\0";
	if ((all_flag.number > 0 || all_flag.wildcard > 0 || all_flag.dot > 0) &&
			(all_flag.minus == 0))
		return (ft_space_string(str, all_flag, buf, temp2));
	else if (all_flag.minus > 0  && (all_flag.number > 0 ||
				   	all_flag.wildcard > 0))
		return (ft_space_minus_string(str, all_flag, buf, temp2));
	else
	{
		temp1 = *buf;
		*buf = ft_strjoin(*buf, temp2);
		free(temp1);
	}
	return ((int)ft_strlen(*buf));
}
