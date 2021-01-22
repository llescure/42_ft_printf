/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:47:02 by llescure          #+#    #+#             */
/*   Updated: 2021/01/22 16:27:16 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		str_error_case(t_flag all_flag)
{
	if (all_flag.zero > 0)
		return (-1);
	if (all_flag.minus > 0 && (all_flag.wildcard < 0 ||
		all_flag.number < 0))
		return (-1);
	if ((all_flag.wildcard > 2) || (all_flag.minus > 1) || (all_flag.dot > 1) ||
		(all_flag.zero > 1))
		return (-1);
	return (0);
}

int		ft_precision_string(const char *str, t_flag all_flag, char **buf,
		char *user_str)
{
	int								i;
	int								number_of_char;
	char							*temp;
	char							*str_trimmed

	i = 0;
	number_of_char = 0;
	while (str[i] != '.')
		i++;
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
		number_of_char = ft_extract_number(str, i);
	else if (str[i] == '.' && str[i + 1] == '*' && all_flag.minus == 0)
		number_of_char = all_flag.wildcard_value1;
	else if (str[i] == '.' && str[i + 1] == '*' && all_flag.minus > 0)
		number_of_char = all_flag.wildcard_value2;
	str_trimmed = ft_trim((char *)user_str, 0, number_of_char);
	temp = *buf;
	*buf = ft_strjoin(buf, str_trimmed);
	free(temp);
	free(str_trimmed);
	return (ft_strlen(*buf));
}

int		ft_space_string(const char *str, t_flag all_flag, char **buf,
		char *user_str)
{
	int						i;
	int						number_of_spaces;
	int						number_of_char;
	char					*temp;

	i = 0;
	number_of_char = ft_strlen(user_str);
	if (all_flag.dot > 0)
		number_of_char = ft_precision_string(str, all_flag, buf, user_str);
	while (ft_isdigit(str[i] != 1))
		i++;
	if (all_flag.wildcard == 1)
		number_of_spaces = all_flag.wildcard_value1 - number_of_char;
	else
		number_of_spaces = ft_extract_number(str, i) - number_of_char;
	if ((ft_join_buf_space(buf, number_of_spaces)) == -1)
		return (-1);
	if (all_flag.dot == 0)
	{
		temp = *buf;
		*buf = ft_strjoin(*buf, str_user_str);
		free(temp);
	}
	return (ft_strlen(*buf));
}

int		ft_space_minus_str(const char *str, t_flag all_flag, char **buf,
		char *user_str)
{
	int								i;
	int								number_of_spaces;
	int								number_of_char;
	char							*temp;

	i = 0;
	number_of_spaces = 0;
	number_of_char = ft_strlen(user_str);
	if (all_flag.dot > 0)
		number_of_char = ft_precision_string(str, all_flag, buf, user_str);
	while (str[i] != '-')
		i++;
	if (all_flag.dot == 0)
	{
		temp = *buf;
		*buf = ft_strjoin(*buf, str_user_str);
		free(temp);
	}
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
	char *temp;

	if (str_error_case(all_flag) < 0)
		return (-1);
	if (user_str == NULL)
	{
		ft_putstr_fd("(null)\0", 1);
		return (compt = 6);
	}
	if ((all_flag.number > 0 || all_flag.wildcard > 0) &&
			(all_flag.minus == 0) || (all_flag.dot == 0))
		return (ft_space_string(str, all_flag, buf, user_str));
	else if ((all_flag.minus > 0) || (all_flag_dot > 0) && (all_flag.number > 0 ||
		all_flag.wildcard > 0))
		return (ft_space_precision(str, all_flag, buf, user_str));
	else
	{
		temp = *buf;
		*buf = ft_strjoin(*buf, user_str);
		free(temp);
	}
	return ((int)ft_strlen(*buf));
}
