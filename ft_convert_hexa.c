/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:38:55 by llescure          #+#    #+#             */
/*   Updated: 2021/02/04 16:57:17 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_size(long unsigned n)
{
	int compt;

	compt = 0;
	if (n <= 0)
	{
		n = n * -1;
		compt++;
	}
	while (n > 0)
	{
		n = n / 16;
		compt++;
	}
	return (compt);
}

char	*ft_convert_hexa(long unsigned user_nbr, char *base)
{
	char										*rslt;
	long unsigned								temp;
	int											i;
	int											j;

	temp = user_nbr;
	if (!(rslt = malloc(sizeof(char) * find_size(user_nbr) + 1)))
		return (NULL);
	i = find_size(user_nbr) - 1;
	j = 0;
	if (temp < 0)
	{
		rslt[j] = '-';
		temp = temp * -1;
		j++;
	}
	while (i >= j)
	{
		rslt[i] = base[temp % 16];
		temp = temp / 16;
		i--;
	}
	rslt[find_size(user_nbr)] = '\0';
	return (rslt);
}

char	*ft_convert_address(long unsigned user_nbr, t_flag all_flag)
{
	char *address;
	char *beginning;
	char *temp;

	if (all_flag.dot > 0 && user_nbr == 0)
		return ("0x");
	if (!(address = malloc(sizeof(char) * 10)))
		return (NULL);
	address[9] = '\0';
	beginning = "0x";
	address = ft_convert_hexa(user_nbr, "0123456789abcdef");
	temp = address;
	address = ft_strjoin(beginning, address);
	free(temp);
	return (address);
}
