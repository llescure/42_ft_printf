/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cara.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:46:55 by llescure          #+#    #+#             */
/*   Updated: 2021/01/18 22:59:31 by llescure         ###   ########.fr       */
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

int		ft_space_number(const char *str, t_flag all_flag, int compt)
{
	int start;
	int end;
	int rslt;
	char *temp;

	start = 0;
	while (ft_isdigit(str[i]) != 1)
		start++;
	end = start;
	while (ft_isdigit(str[i]) == 1)
		end++;
	temp = ft_trim((char *)str, start, end);
	rslt = ft_atoi(temp);
	if (rslt > 1)
		rslt --;
	//Display the space and update compt
	//Before displaying cara
}

int		ft_space_minus(const char *str, t_flag all_flag, int compt)
{
	//After displaying cara
}

int		ft_print_cara(const char *str, t_flag all_flag, int compt, int cara)
{
	if (error_case(all_flag) < 0)
		return (-1);
	if (all_flag.number > 0)
		return (ft_space_number(str, all_flag, compt));
	if (all_flag.minus > 0 && (all_flag.number > 0 || all_flag.wildcard > 0))
		return (ft_space_minus(str, all_flag, compt));
	write(1, &cara, 1);
	return (compt);
}
