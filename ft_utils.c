/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:34:25 by llescure          #+#    #+#             */
/*   Updated: 2021/02/11 12:22:20 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_cut_str(const char *str, int compt)
{
	char				*temp;
	char				*str_cut;
	int					i;

	i = compt + 1;
	temp = ft_strdup(str);
	str_cut = ft_strdup(&temp[i]);
	free(temp);
	return (str_cut);
}

char	*ft_get_start(const char *str, t_flag *all_flag)
{
	char							*buf;
	int								i;

	i = 0;
	buf = NULL;
	while (str[i] != '\0' && str[i] != '%')
		i++;
	if (i > 0)
	{
		buf = ft_trim((char *)str, 0, i);
		all_flag->compt = all_flag->compt + i;
		str = ft_cut_str(str, i - 1);
		ft_putstr_fd(buf, 1);
		if (buf != NULL)
			free(buf);
	}
	return ((char *)str);
}

int		ft_create_cara(int number_of_cara, char c)
{
	char				*cara;
	int					i;

	i = 0;
	if (number_of_cara <= 0)
		return (0);
	if (!(cara = malloc(sizeof(char) * number_of_cara + 1)))
		return (0);
	while (i < number_of_cara)
	{
		cara[i] = c;
		i++;
	}
	cara[number_of_cara] = '\0';
	ft_putstr_fd(cara, 1);
	free(cara);
	return (number_of_cara);
}

char	*ft_trim(char *str, int start, int end)
{
	char		*new;
	int			i;
	int			j;

	if (end <= start)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (end - start) + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
	{
		new[j] = str[i];
		i++;
		j++;
	}
	new[end - start] = '\0';
	return (new);
}
