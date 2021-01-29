/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:20:37 by llescure          #+#    #+#             */
/*   Updated: 2021/01/29 17:14:42 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_unsigned_size(unsigned int n)
{
	int compt;

	compt = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		compt++;
	}
	return (compt);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char				*rslt;
	unsigned long		store;
	int					i;
	int					j;

	store = n;
	if (!(rslt = malloc(sizeof(char) * find_unsigned_size(n) + 1)))
		return (NULL);
	i = find_unsigned_size(n);
	j = 0;
	while (i >= j)
	{
		rslt[i] = '0' + store % 10;
		store = store / 10;
		i--;
	}
	rslt[find_unsigned_size(n) + 1] = '\0';
	return (rslt);
}

int		ft_precision(const char *str, t_flag all_flag, char **user_str)
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
	if (number_of_char == 0)
		*user_str = "";
	if (number_of_char > (int)ft_strlen(*user_str))
		return (number_of_char);
	return ((int)ft_strlen(*user_str));
}

int		print_unsign(const char *str, t_flag all_flag, int user_nbr,
	char **buf)
{
	char								*temp1;
	unsigned int						signed_to_unsigned;
	char								*nbr_convert;

	signed_to_unsigned = (unsigned int)user_nbr;
	nbr_convert = ft_itoa_unsigned(signed_to_unsigned);
	if (int_error_case(all_flag) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0 || all_flag.dot > 0) &&
			(all_flag.minus == 0) && (all_flag.zero == 0))
		return (ft_space_int(str, all_flag, buf, nbr_convert));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
				all_flag.wildcard > 0) && all_flag.zero == 0)
		return (ft_space_minus_int(str, all_flag, buf, nbr_convert));
	else if (all_flag.zero > 0 && (all_flag.number > 0 ||
				all_flag.wildcard > 0))
		return (ft_zero_int(str, all_flag, buf, nbr_convert));
	else
	{
		temp1 = *buf;
		*buf = ft_strjoin(*buf, nbr_convert);
		free(temp1);
	}
	return ((int)ft_strlen(*buf));
}
