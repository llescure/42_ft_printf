/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:46:55 by llescure          #+#    #+#             */
/*   Updated: 2021/02/05 17:02:32 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	error_case(t_flag *all_flag, const char **str)
{
	if (all_flag->zero > 0 || all_flag->wildcard > 1 || all_flag->dot > 1)
		all_flag->compt = -1;
	if (all_flag->wildcard_value1 < 0)
	{
		all_flag->wildcard_value1 = all_flag->wildcard_value1 * -1;
		all_flag->minus = all_flag->minus + 1;
		*str = replace_first_wildcard(str, '-');
	}
	if (all_flag->minus > 1)
		*str = ft_delete_multiple_cara(str, '-');
	return ;
}

int		ft_extract_number(const char *str, int compt)
{
	int									start;
	int									end;
	long								rslt;
	char								*temp;

	start = compt;
	while (ft_isdigit(str[start]) != 1)
		start++;
	end = start;
	while (ft_isdigit(str[end]) == 1)
		end++;
	temp = ft_trim((char *)str, start, end);
	rslt = ft_atoi((const char *)temp);
	free(temp);
	if (rslt > 0)
		return ((int)rslt);
	return (0);
}

void	ft_space(const char *str, t_flag *all_flag, char cara)
{
	int						i;
	int						number_of_spaces;

	i = 0;
	while (ft_isdigit(str[i] != 1))
		i++;
	if (all_flag->wildcard == 1)
		number_of_spaces = all_flag->wildcard_value1 - 1;
	else
		number_of_spaces = ft_extract_number(str, i) - 1;
	ft_join_buf_space(number_of_spaces);
	ft_putchar_fd(cara, 1);
	all_flag->compt = all_flag->compt + 1 + number_of_spaces;
	return ;
}

void	ft_space_minus(const char *str, t_flag *all_flag, char cara)
{
	int								i;
	int								number_of_spaces;

	i = 0;
	number_of_spaces = 0;
	while (str[i] != '-')
		i++;
	ft_putchar_fd(cara, 1);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i) - 1;
	else if (str[i] == '-' && str[i + 1] == '*')
		number_of_spaces = all_flag->wildcard_value1 - 1;
	ft_join_buf_space(number_of_spaces);
	all_flag->compt = all_flag->compt + 1 + number_of_spaces;
	return ;
}

void	ft_print_cara(const char **str, t_flag *all_flag, char cara)
{
	error_case(all_flag, str);
	//printf("str = %s\n", *str);
	if ((all_flag->number > 0 || all_flag->wildcard > 0) &&
			all_flag->minus == 0)
		ft_space(*str, all_flag, cara);
	else if (all_flag->minus > 0 && (all_flag->number > 0 ||
		all_flag->wildcard > 0))
		ft_space_minus(*str, all_flag, cara);
	else
	{
		ft_putchar_fd(cara, 1);
		all_flag->compt = all_flag->compt + 1;
	}
	return ;
}
