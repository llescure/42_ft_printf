/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:23:07 by llescure          #+#    #+#             */
/*   Updated: 2021/02/01 22:29:50 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_initialisation(t_flag *all_flag)
{
	all_flag->wildcard = 0;
	all_flag->wildcard_value1 = 0;
	all_flag->wildcard_value2 = 0;
	all_flag->minus = 0;
	all_flag->dot = 0;
	all_flag->zero = 0;
	all_flag->number = 0;
	all_flag->negative = 0;
	all_flag->type = '0';
	return ;
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

int			valid_type(const char *str, int compt)
{
	int i;
	int pos_percent;

	i = compt;
	pos_percent = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			pos_percent = i;
			i = ft_where_type_is(str, i);
			if (i > pos_percent)
				return (i);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

void		ft_parse_flag(const char *str, int start, int end,
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
	return ;
}

int			ft_parsing(const char *str, t_flag *all_flag)
{
	int i;
	int pos_percent;

	i = 0;
	pos_percent = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] == '%') || (i > 0 && str[i] == '%' 
					&& str[i - 1] != '%'))
		{
			pos_percent = i;
			i = ft_where_type_is(str, i);
			if (i > pos_percent)
			{
				ft_parse_flag(str, pos_percent, i, all_flag);
				return (pos_percent);
			}
			return (i);
		}
		i++;
	}
	return (-1);
}
