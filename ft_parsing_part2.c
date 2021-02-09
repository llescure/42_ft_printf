/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:37:43 by llescure          #+#    #+#             */
/*   Updated: 2021/02/09 15:30:16 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_delete_multiple_cara(const char **str, char cara)
{
	char										*temp;
	char										*first_str_trimmed;
	char										*second_str_trimmed;
	int											start;
	int											end;

	temp = (char *)*str;
	start = 0;
	while (temp[start] != '%')
		start++;
	while (temp[start] != cara)
		start++;
	end = start;
	while (temp[end] == cara)
		end++;
	if (start == end)
		return (temp);
	first_str_trimmed = ft_trim(temp, 0, start);
	second_str_trimmed = ft_trim(temp, end - 1, ft_strlen(temp));
	temp = ft_strjoin(first_str_trimmed, second_str_trimmed);
	free(first_str_trimmed);
	free(second_str_trimmed);
	return (temp);
}

char		*ft_delete_cara(const char *str, char cara, t_flag all_flag)
{
	char								*first_str_trimmed;
	char								*second_str_trimmed;
	int									start;
	int									end;

	start = 0;
	while (str[start] != '%')
		start++;
	end = start;
	while (str[end] != '.' && str[end] != '\0')
		end++;
	if (str[end] == '.' && str[end + 1] == '%' && all_flag.minus < 1)
		return (NULL);
	while (str[start] != cara)
		start++;
	end = start;
	while (str[end] == cara)
		end++;
	first_str_trimmed = ft_trim((char *)str, 0, start);
	second_str_trimmed = ft_trim((char *)str, end, ft_strlen(str));
	str = ft_strjoin(first_str_trimmed, second_str_trimmed);
	free(first_str_trimmed);
	free(second_str_trimmed);
	return ((char *)str);
}

char		*replace_first_wildcard(const char *str, char cara,
		t_flag *all_flag)
{
	int											i;
	int											j;
	int											ok;
	char										*rslt;

	i = 0;
	j = 0;
	ok = 1;
	all_flag->wildcard_value1 = all_flag->wildcard_value1 * -1;
	all_flag->minus = all_flag->minus + 1;
	if (!(rslt = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	while (str[i] != '%')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '*' && ok == 1)
		{
			rslt[j++] = cara;
			ok = 0;
		}
		rslt[j++] = str[i++];
	}
	rslt[j] = '\0';
	return (rslt);
}

char		*replace_second_wildcard(const char *str, char cara,
		t_flag *all_flag)
{
	int											i;
	int											j;
	char										*rslt;

	i = 0;
	j = 0;
	all_flag->wildcard_value2 = all_flag->wildcard_value2 * -1;
	all_flag->minus = all_flag->minus + 1;
	if (!(rslt = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	while (str[i] != '%')
		i++;
	while (str[i] != '*')
		rslt[j++] = str[i++];
	rslt[j++] = str[i++];
	while (str[i] != '\0')
	{
		if (str[i] == '*')
			rslt[j++] = cara;
		rslt[j++] = str[i++];
	}
	rslt[j] = '\0';
	return (rslt);
}

int			check_weird_combination(const char **str, t_flag *all_flag)
{
	int											i;
	char										*temp;

	temp = (char *)*str;
	i = 0;
	while (temp[i] != '%' && temp[i] != '\0')
		i++;
	while (temp[i] != '.' && temp[i] != '\0')
		i++;
	if (temp[i] == '.' && temp[i + 1] == '*' && all_flag->wildcard == 1)
	{
		all_flag->wildcard_value1 = 0;
		all_flag->dot = 0;
		return (1);
	}
	else if (temp[i] == '.' && temp[i - 1] == '*' && temp[i + 1] == '*' &&
			all_flag->wildcard_value2 < 0)
	{
		all_flag->wildcard_value2 = 0;
		all_flag->dot = 0;
		if (all_flag->wildcard_value1 < 0)
			*str = replace_first_wildcard(*str, '-', all_flag);
		return (1);
	}
	return (0);
}
