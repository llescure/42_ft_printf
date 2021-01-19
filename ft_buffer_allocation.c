/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:34:25 by llescure          #+#    #+#             */
/*   Updated: 2021/01/19 23:17:25 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_buf_start(const char *str, int compt, char **buf)
{
	char *temp;
	char *str_trimmed;

	if(!(*buf = malloc(sizeof(char))))
		return (-1);
	*buf = "";
	temp = *buf;
	str_trimmed = ft_trim((char *)str, 0, compt);
	ft_strjoin(*buf, str_trimmed);
	free(temp);
	return (0);
}

char	*ft_join_buf_space_after(char **buf, int number_of_spaces)
{
	char *temp;
	char *spaces;
	int i;

	i = 0;
	if(!(malloc(sizeof(char) * number_of_spaces)))
		return (NULL);
	spaces = NULL;
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
	return (*buf);
}

char	*ft_join_buf_space_before(char **buf, int number_of_spaces)
{
	char *temp;
	char *spaces;
	int i;

	i = 0;
	if(!(malloc(sizeof(char) * number_of_spaces)))
		return (NULL);
	spaces = NULL;
	while (i < number_of_spaces)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[number_of_spaces] = '\0';
	temp = *buf;
	*buf = ft_strjoin(spaces, *buf);
	free(temp);
	free(spaces);
	return (*buf);
}
