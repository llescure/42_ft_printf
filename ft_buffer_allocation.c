/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:34:25 by llescure          #+#    #+#             */
/*   Updated: 2021/02/05 19:11:40 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_get_buf_start(const char *str, t_flag *all_flag)
{
	char							*buf;
	int								i;

	i = 0;
	buf = NULL;
	all_flag->compt = 0;
	while (str[i] != '\0' && str[i] != '%')
		i++;
	if (i > 0)
	{
		buf = ft_trim((char *)str, 0, i);
		all_flag->compt = all_flag->compt + i;
		str = ft_cut_str(str, i - 1);
		ft_putstr_fd(buf, 1);
	}
		return ((char *)str);
}

int		ft_join_buf_space(int number_of_spaces)
{
	char				*spaces;
	int					i;

	i = 0;
	if (number_of_spaces <= 0)
		return (-1);
	if (!(spaces = malloc(sizeof(char) * number_of_spaces + 1)))
		return (-1);
	while (i < number_of_spaces)
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[number_of_spaces] = '\0';
	ft_putstr_fd(spaces, 1);
	free(spaces);
	return (1);
}

int		ft_join_buf_zero(int number_of_zeros)
{
	char				*zeros;
	int					i;

	i = 0;
	if (number_of_zeros <= 0)
		return (-1);
	if (!(zeros = malloc(sizeof(char) * number_of_zeros + 1)))
		return (-1);
	while (i < number_of_zeros)
	{
		zeros[i] = '0';
		i++;
	}
	zeros[number_of_zeros] = '\0';
	ft_putstr_fd(zeros, 1);
	free(zeros);
	return (1);
}

char	*ft_get_buf_end(const char *str, t_flag *all_flag)
{
	char						*buf;
	int							i;

	if (all_flag->type == '0')
		return ((char *)str);
	buf = NULL;
	printf("str1 = %s\n", str);
	//printf("compt = %d\n", all_flag->compt);
	i = ft_where_type_is(str, 0);
	//printf("i = %d\n", i);
	while (str[i] != '\0' && str[i] != '%')
		i++;
	//printf("i = %d\n", i);
	if (i - 1 > ft_where_type_is(str, 0))
	{
		buf = ft_trim((char *)str, ft_where_type_is(str, 0) + 1, i);
		all_flag->compt = all_flag->compt + i - ft_where_type_is(str, 0) - 1;
		ft_putstr_fd(buf, 1);
		str = ft_cut_str(str, i - 1);
	printf("str2 = %s\n", str);
	}
	return ((char *)str);
}
