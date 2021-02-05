/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:50:43 by llescure          #+#    #+#             */
/*   Updated: 2021/02/05 16:36:24 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
