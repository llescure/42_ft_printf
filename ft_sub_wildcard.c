/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:48:24 by llescure          #+#    #+#             */
/*   Updated: 2021/01/19 16:59:56 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_convert_wildcard(const char *str, va_arg(arguments, int),
		int number_wildcard, t_flag *all_flag);
{
	int rslt;

	rslt = va_arg(arguments, int);
	if (number_wildcard == 2 || all_flag->wildcard == 1)
		all_flag->wilcard_value1 = rslt;
	if (number_wildcard == 1 && all_flag->wildcard == 2)
		all_flag->wilcard_value2 = rslt;
	return ;
}

