/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:49:44 by llescure          #+#    #+#             */
/*   Updated: 2021/01/24 21:17:25 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_find_size(int n)
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

char	*ft_convert_lower_hexa(int user_nbr)
{	
	char *rslt;
	char *base;
	int temp;
	int i;
	int j;

	temp = user_nbr;
	base = "0123456789abcdef";
	if (!(rslt = malloc(sizeof(char) * ft_find_size(user_nbr) + 1)))
		return (NULL);
	i = ft_find_size(user_nbr) - 1;
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
	rslt[ft_find_size(user_nbr)] = '\0';
	return (rslt);
}

char	*ft_convert_upper_hexa(int user_nbr)
{	
	char *rslt;
	char *base;
	int temp;
	int i;
	int j;

	temp = user_nbr;
	base = "0123456789ABCDEF";
	if (!(rslt = malloc(sizeof(char) * ft_find_size(user_nbr) + 1)))
		return (NULL);
	i = ft_find_size(user_nbr) - 1;
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
	rslt[ft_find_size(user_nbr)] = '\0';
	return (rslt);
}
