/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:47:19 by llescure          #+#    #+#             */
/*   Updated: 2021/01/22 15:32:16 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_space(const char *str, t_flag all_flag, char **buf,
		char cara)
{
	int						i;
	int						number_of_spaces;
	char					*temp;
	char					*str_cara;

	i = 0;
	str_cara = NULL;
	while (ft_isdigit(str[i] != 1))
		i++;
	if (all_flag.wildcard == 1)
		number_of_spaces = all_flag.wildcard_value1;
	else
		number_of_spaces = ft_extract_number(str, i);
	if ((ft_join_buf_space(buf, number_of_spaces)) == -1)
		return (-1);
	if ((str_cara = ft_allocate_char_to_str(str_cara, cara)) == NULL)
		return (-1);
	temp = *buf;
	*buf = ft_strjoin(*buf, str_cara);
	free(temp);
	free(str_cara);
	return (ft_strlen(*buf));
}

int		ft_space_minus(const char *str, t_flag all_flag, char **buf,
		char cara)
{
	int								i;
	int								number_of_spaces;
	char							*str_cara;
	char							*temp;

	i = 0;
	str_cara = NULL;
	number_of_spaces = 0;
	while (str[i] != '-')
		i++;
	if ((str_cara = ft_allocate_char_to_str(str_cara, cara)) == NULL)
		return (-1);
	temp = *buf;
	*buf = ft_strjoin(*buf, str_cara);
	free(temp);
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		number_of_spaces = ft_extract_number(str, i);
	else if (str[i] == '-' && str[i + 1] == '*')
		number_of_spaces = all_flag.wildcard_value1;
	free(str_cara);
	if ((ft_join_buf_space(buf, number_of_spaces)) == -1)
		return (-1);
	return (ft_strlen(*buf));
}

int		ft_print_pointer(const char *str, t_flag all_flag, char cara,
	char **buf)
{
	char *str_cara;
	char *temp;

	str_cara = NULL;
	if (error_case(all_flag) < 0)
		return (-1);
	if ((all_flag.number > 0 || all_flag.wildcard > 0) &&
			all_flag.minus == 0)
		return (ft_space(str, all_flag, buf, cara));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
		all_flag.wildcard > 0))
		return (ft_space_minus(str, all_flag, buf, cara));
	else
	{
		if ((str_cara = ft_allocate_char_to_str(str_cara, cara)) == NULL)
			return (-1);
		temp = *buf;
		*buf = ft_strjoin(*buf, str_cara);
		free(temp);
	}
	return ((int)ft_strlen(*buf));
}
