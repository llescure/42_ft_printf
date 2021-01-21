/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:34:25 by llescure          #+#    #+#             */
/*   Updated: 2021/01/20 23:18:52 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_buf_start(const char *str, int compt, char **buf)
{
	char *temp;
	char *str_trimmed;

	if (!(*buf = malloc(sizeof(char))))
		return (-1);
	*buf[0] = '\0';
	if (compt > 0)
	{
		temp = *buf;
		str_trimmed = ft_trim((char *)str, 0, compt);
		*buf = ft_strjoin(*buf, str_trimmed);
		free(temp);
		free(str_trimmed);
	}
	return (1);
}

char	*ft_allocate_char_to_str(char *str, char cara)
{
	if (!(str = malloc(sizeof(char) + 1)))
		return (NULL);
	str[0] = cara;
	str[1] = '\0';
	return (str);
}

int		ft_join_buf_space(char **buf, int number_of_spaces)
{
	char				*temp;
	char				*spaces;
	int					i;

	i = 0;
	if (number_of_spaces <= 0)
		return (-1);
	if (!(spaces = malloc(sizeof(char) * number_of_spaces)))
		return (-1);
	while (i < number_of_spaces)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[number_of_spaces] = '\0';
	temp = *buf;
	*buf = ft_strjoin(*buf, spaces);
	free(temp);
	free(spaces);
	return (1);
}

int		ft_get_buf_end(const char *str, char **buf, t_flag all_flag)
{
	char						*temp;
	char						*str_trimmed;
	int							i;
	int							total_number_cara;

	if (all_flag.type == '0')
		return (0);
	i = 0;
	while (str[i] != '%')
		i++;
	i++;
	while (str[i] != all_flag.type)
		i++;
	i++;
	total_number_cara = i;
	while (str[total_number_cara] != '\0')
		total_number_cara++;
	if (total_number_cara == i)
		return (0);
	printf("%d\n", total_number_cara);
	printf("%d\n", i);
	str_trimmed = ft_trim((char *)str, i, total_number_cara);
	printf("%s\n", str_trimmed);
	temp = *buf;
	*buf = ft_strjoin(*buf, str_trimmed);
	free(temp);
	free(str_trimmed);
	return (total_number_cara - i);
}
