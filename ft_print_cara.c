/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:46:55 by llescure          #+#    #+#             */
/*   Updated: 2021/01/20 22:48:43 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		error_case(t_flag all_flag)
{
	if ((all_flag.zero > 0) || (all_flag.dot > 0) || (all_flag.wildcard > 1))
		return (-1);
	if (all_flag.minus > 0 && (all_flag.wildcard < 0 ||
		all_flag.number < 0))
		return (-1);
	if ((all_flag.wildcard > 1) || (all_flag.minus > 1) || (all_flag.dot > 1) ||
		(all_flag.zero > 1))
		return (-1);
	return (0);
}

int		ft_extract_number(const char *str, int compt)
{
	int									start;
	int									end;
	int									rslt;
	char								*temp;

	start = compt;
	while (ft_isdigit(str[start]) != 1)
		start++;
	end = start;
	while (ft_isdigit(str[end]) == 1)
		end++;
	temp = ft_trim((char *)str, start, end);
	rslt = ft_atoi((const char *)temp);
	if (rslt > 1)
	{
		rslt--;
		return (rslt);
	}
	return (0);
}

int		ft_space(const char *str, t_flag all_flag, char **buf,
		char cara)
{
	int						i;
	int						number_of_spaces;
	char					*temp;
	char					*str_cara;

	i = 0;
	str_cara = NULL;
	while (ft_isdigit(str[i] != 1))
		i++;
	if (all_flag.wildcard == 1)
		number_of_spaces = all_flag.wildcard_value1 - 1;
	else
		number_of_spaces = ft_extract_number(str, i);
	if ((ft_join_buf_space_before(buf, number_of_spaces)) == -1)
		return (-1);
	if ((str_cara = ft_allocate_char_to_str(str_cara, cara)) == NULL)
		return (-1);
	temp = *buf;
	*buf = ft_strjoin(*buf, str_cara);
	free(temp);
	free(str_cara);
	return (ft_strlen(*buf));
}

int		ft_space_minus(const char *str, t_flag all_flag, char **buf,
		char cara)
{
	int								i;
	int								number_of_spaces;
	char							*str_cara;
	char							*temp;

	i = 0;
	str_cara = NULL;
	number_of_spaces = 0;
	while (str[i] != '-')
		i++;
	if ((str_cara = ft_allocate_char_to_str(str_cara, cara)) == NULL)
		return (-1);
	temp = *buf;
	*buf = ft_strjoin(*buf, str_cara);
	free(temp);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i);
	else if (str[i] == '-' && str[i + 1] == '*')
		number_of_spaces = all_flag.wildcard_value1 - 1;
	free(str_cara);
	if ((ft_join_buf_space_after(buf, number_of_spaces)) == -1)
		return (-1);
	return (ft_strlen(*buf));
}

int		ft_print_cara(const char *str, t_flag all_flag, char cara,
	char **buf)
{
	char *str_cara;
	char *temp;

	str_cara = NULL;
	if (error_case(all_flag) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0) &&
			all_flag.minus == 0)
		return (ft_space(str, all_flag, buf, cara));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
		all_flag.wildcard > 0))
		return (ft_space_minus(str, all_flag, buf, cara));
	else
	{
		if ((str_cara = ft_allocate_char_to_str(str_cara, cara)) == NULL)
			return (-1);
		temp = *buf;
		*buf = ft_strjoin(*buf, str_cara);
		free(temp);
	}
	return ((int)ft_strlen(*buf));
}
