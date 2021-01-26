/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:55:02 by llescure          #+#    #+#             */
/*   Updated: 2021/01/26 19:20:23 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_hexa_unsigned_size(long unsigned n)
{
	int compt;

	compt = 0;
	if (n < 0)
	{
		compt++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 16;
		compt++;
	}
	return (compt);
}

char	*ft_convert_address_hexa(long unsigned user_nbr, char *base)
{
	char										*rslt;
	long unsigned								temp;
	int											i;
	int											j;

	temp = user_nbr;
	if (!(rslt = malloc(sizeof(char) * find_hexa_unsigned_size(user_nbr) + 1)))
		return (NULL);
	i = find_hexa_unsigned_size(user_nbr) - 1;
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
	find_hexa_unsigned_size(user_nbr);
	rslt[find_hexa_unsigned_size(user_nbr)] = '\0';
	return (rslt);
}

char	*ft_convert_address(long unsigned user_nbr)
{
	char *address;
	char *beginning;
	char *temp;

	if (user_nbr == 0)
		return ("0x0");
	if (!(address = malloc(sizeof(char) * 10)))
		return (NULL);
	address[9] = '\0';
	beginning = "0x";
	address = ft_convert_address_hexa(user_nbr, "0123456789abcdef");
	temp = address;
	address = ft_strjoin(beginning, address);
	free(temp);
	return (address);
}
