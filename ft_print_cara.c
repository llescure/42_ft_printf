/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:35:52 by llescure          #+#    #+#             */
/*   Updated: 2021/01/19 17:02:43 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:46:55 by llescure          #+#    #+#             */
/*   Updated: 2021/01/19 16:06:44 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		error_case(t_flag all_flag)
{
	if ((all_flag.zero > 0) || (all_flag.dot > 0) || (all_flag.wildcard > 1))
		return (-1);
	if (all_flag.minus > 0 && (all_flag.wildcard < 0 ||
			 all_flag.number < 0))
		return (-1);
	if ((all_flag.wildcard > 1) || (all_flag.minus > 1) || (all_flag.dot > 1) ||
		(all_flag.zero > 1))
		return (-1);
	return (0);
}

int		ft_extract_number(const char *str, t_flag all_flag, int compt)
{
	int start;
	int end;
	int rslt;
	char *temp;

	start = compt;
	while (ft_isdigit(str[i]) != 1)
		start++;
	end = start;
	while (ft_isdigit(str[i]) == 1)
		end++;
	temp = ft_trim((char *)str, start, end);
	rslt = ft_atoi(temp);
	if (rslt > 1)
		return (rslt);
	return (0);
}

int		ft_space(const char *str, t_flag all_flag, int compt, char **buf,
		int cara)
{
	int number_of_spaces;

	if (all_flag.wildcard == 1)
		number_of_spaces = all_flag.wildcard_value1;
	else
		number_of_spaces = ft_extract_number(str, all_flag, compt);
	buf = ft_join_buf_space_before(str, buf, compt, number_of_spaces);
	buf[number_of_spaces] = 'cara';
	return (compt + number_of_spaces);
}

int		ft_space_minus(const char *str, t_flag all_flag, int compt, char **buf,
		int cara)
{
	int i;
	int number_of_spaces;

	i = compt;
	while (str[i] != '-')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		number_of_spaces = ft_extract_number(str, all_flag, compt);
		buf = ft_join_buf_space_after(str, buf, compt, number_of_spaces);
		buf[compt] = 'cara';
		return (compt + number_of_spaces);
	}
	if (str[i] == '-' && str[i + 1] == '*')
	{
		number_of_spaces = all_flag.wildcard_value1;
		buf = ft_join_buf_space_after(str, buf, compt, number_of_spaces);
		buf[compt] = 'cara';
		return (compt + number_of_spaces);
	}
	return (-1);
}

int		ft_print_cara(const char *str, t_flag all_flag, int compt, int cara,
	char **buf)
{
	if (error_case(all_flag) < 0)
		return (-1);
	if (all_flag.number > 0 && all_flag.minus == 0)
		return (ft_space(str, all_flag, compt, buf));
	else if (all_flag.minus > 0 && (all_flag.number > 0 ||
			   	all_flag.wildcard > 0))`
		return (ft_space_minus(str, all_flag, compt, buf));
	else
		*buf[compt] = 'cara';
	return (compt);
}
