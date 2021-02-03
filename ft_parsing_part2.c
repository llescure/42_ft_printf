/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:37:43 by llescure          #+#    #+#             */
/*   Updated: 2021/02/03 14:33:18 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_delete_multiple_cara(const char **str, char cara)
{
	char *temp;
	char *first_str_trimmed;
	char *second_str_trimmed;
	int start;
	int end;

	temp = (char *)*str;
	start = 0;
	while (temp[start] != '%')
		start++;
	while (temp[start] != cara)
		start++;
	end = start;
	while (temp[end] == cara)
		end++;
	first_str_trimmed = ft_trim(temp, 0, start);
	second_str_trimmed = ft_trim(temp, end - 1, ft_strlen(temp));
	temp = ft_strjoin(first_str_trimmed, second_str_trimmed);
	free(first_str_trimmed);
	free(second_str_trimmed);
	return (temp);
}


char		*ft_delete_cara(const char **str, char cara)
{
	char *temp;
	char *first_str_trimmed;
	char *second_str_trimmed;
	int start;
	int end;

	temp = (char *)*str;
	start = 0;
	while (temp[start] != '%')
		start++;
	while (temp[start] != cara)
		start++;
	end = start;
	while (temp[end] == cara)
		end++;
	first_str_trimmed = ft_trim(temp, 0, start);
	second_str_trimmed = ft_trim(temp, end, ft_strlen(temp));
	temp = ft_strjoin(first_str_trimmed, second_str_trimmed);
	free(first_str_trimmed);
	free(second_str_trimmed);
	return (temp);
}

char		*ft_join_cara(const char *str, char cara)
{
	unsigned int						i;
	char								*rslt;

	if (!(rslt = malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		rslt[i] = str[i];
		i++;
	}
	rslt[i] = cara;
	i++;
	rslt[i] = '\0';
	return (rslt);
}

char		*replace_first_wildcard(const char **str, char cara)
{
	int i;
	int j;
	int ok;
	char *rslt;
	char *temp;

	i = 0;
	j = 0;
	ok = 1;
	temp = (char *)*str;
	if (!(rslt = malloc(sizeof(char) * (ft_strlen(temp) + 2))))
		return (NULL);
	while (temp[i] != '%')
		i++;
	while (temp[i] != '\0')
	{
		if (temp[i] == '*' && ok == 1)
		{
			rslt[j] = cara;
			ok = 0;
			j++;
		}
		rslt[j] = temp[i];
		i++;
		j++;
	}
	rslt[j] = '\0';
	return (rslt);
}

char		*replace_second_wildcard(const char **str, char cara)
{
	int i;
	int j;
	char *rslt;
	char *temp;

	i = 0;
	j = 0;
	temp = (char *)*str;
	printf("temp%s\n", temp);
	if (!(rslt = malloc(sizeof(char) * (ft_strlen(temp) + 2))))
		return (NULL);
	while (temp[i] != '%')
		i++;
	while (temp[i] != '*')
		i++;
	while (temp[i] != '\0')
	{
		if (temp[i] == '*')
		{
			rslt[j] = cara;
			j++;
		}
		rslt[j] = temp[i];
		i++;
		j++;
	}
	rslt[j] = '\0';
	return (rslt);
}

int			check_weird_combination(const char **str, t_flag *all_flag)
{
	int i;
	char *temp;

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
	return (0);

}
