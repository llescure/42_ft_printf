/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:49:44 by llescure          #+#    #+#             */
/*   Updated: 2021/01/28 13:33:16 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		find_size(int n)
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

char	*ft_convert_lower_hexa(int user_nbr, char *base)
{
	char							*rslt;
	int								temp;
	int								i;
	int								j;

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

char	*ft_convert_upper_hexa(int user_nbr, char *base)
{
	char							*rslt;
	int								temp;
	int								i;
	int								j;

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
