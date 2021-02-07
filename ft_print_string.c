/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:47:02 by llescure          #+#    #+#             */
/*   Updated: 2021/02/07 23:28:03 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	str_error_case(t_flag *all_flag, const char **str)
{
//	printf("str = %s\n", *str);
	if ((all_flag->zero > 0 && all_flag->dot == 0) || ((all_flag->wildcard > 2)
		|| (all_flag->dot > 1) || (all_flag->zero > 1)))
		all_flag->compt = -1;
	if (all_flag->wildcard_value1 < 0 && all_flag->wildcard_value2 < 0
			&& check_weird_combination(str, all_flag) == 0)
	{
		*str = replace_first_wildcard(*str, '-', all_flag);
		all_flag->wildcard_value2 = all_flag->wildcard_value2 * -1;
	}
	if (all_flag->wildcard_value1 < 0 &&
			check_weird_combination(str, all_flag) == 0)
		*str = replace_first_wildcard(*str, '-', all_flag);
	if (all_flag->wildcard_value2 < 0)
		*str = replace_second_wildcard(*str, '-', all_flag);
	if (all_flag->minus > 1)
		*str = ft_delete_multiple_cara(str, '-');
//	printf("str = %s\n", *str);
	return ;
}

int		ft_precision_string(const char *str, t_flag all_flag, char *user_str)
{
	int								i;
	int								number_of_char;

	i = 0;
	number_of_char = 0;
	while (str[i] != '.')
		i++;
//	printf("i = %d\n", i);
	if (str[i] == '.' && ft_isdigit(str[i + 1]) == 1)
		number_of_char = ft_extract_number(str, i);
	else if (str[i - 1] == '*' && str[i] == '.' && str[i + 1] == '*')
		number_of_char = all_flag.wildcard_value2;
	else if (str[i] == '.' && str[i + 1] == '*')
		number_of_char = all_flag.wildcard_value1;
	if (number_of_char > (int)ft_strlen(user_str))
		return (ft_strlen(user_str));
	return (number_of_char);
}

void	ft_space_string(const char *str, t_flag *all_flag, char *user_str)
{
	int						i;
	int						number_of_spaces;
	int						number_of_char;
	char					*temp;

	i = 0;
	number_of_char = ft_strlen(user_str);
	number_of_spaces = 0;
	//printf("str = %s\n", str);
	if (all_flag->dot > 0)
		number_of_char = ft_precision_string(str, *all_flag, user_str);
//	printf("number_of_char = %d\n", number_of_char);
	while (ft_isdigit(str[i]) != 1 && str[i] != '.' && str[i] != '*' &&
				str[i] != '\0')
		i++;
	if (all_flag->number > 0 && str[i] != '.')
		number_of_spaces = ft_extract_number(str, i) - number_of_char;
	else if (all_flag->wildcard > 0 && str[i] != '.')
		number_of_spaces = all_flag->wildcard_value1 - number_of_char;
	number_of_spaces = ft_create_cara(number_of_spaces, ' ');
	temp = ft_trim(user_str, 0, number_of_char);
//	printf("temp = %s\n", temp);
	if (temp != NULL)
	{
		ft_putstr_fd(temp, 1);
		free(temp);
	}
	all_flag->compt = all_flag->compt + number_of_char + number_of_spaces;
}

void	ft_space_minus_string(const char *str, t_flag *all_flag, char *user_str)
{
	int								i;
	int								number_of_spaces;
	int								number_of_char;
	char							*temp;

	i = 0;
	number_of_spaces = 0;
	number_of_char = ft_strlen(user_str);
	if (all_flag->dot > 0)
		number_of_char = ft_precision_string(str, *all_flag, user_str);
	temp = ft_trim(user_str, 0, number_of_char);
	if (temp != NULL)
	{
		ft_putstr_fd(temp, 1);
		free(temp);
	}
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i) - number_of_char;
	else if (str[i] == '-' && str[i + 1] == '*')
		number_of_spaces = all_flag->wildcard_value1 - number_of_char;
	number_of_spaces = ft_create_cara(number_of_spaces, ' ');
	all_flag->compt = all_flag->compt + number_of_char + number_of_spaces;
	return ;
}

void	ft_print_string(const char **str, t_flag *all_flag, char *user_str)
{
	str_error_case(all_flag, str);
	if (all_flag->compt == -1)
		return ;
	if (user_str == NULL)
		user_str = "(null)\0";
	if ((all_flag->number > 0 || all_flag->wildcard > 0 || all_flag->dot > 0) &&
			(all_flag->minus == 0))
		ft_space_string(*str, all_flag, user_str);
	else if (all_flag->minus > 0 && (all_flag->number > 0 ||
				all_flag->wildcard > 0))
		ft_space_minus_string(*str, all_flag, user_str);
	else
	{
		ft_putstr_fd(user_str, 1);
		all_flag->compt = all_flag->compt + ft_strlen(user_str);
	}
	return ;
}
