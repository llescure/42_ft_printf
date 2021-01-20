/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:50:43 by llescure          #+#    #+#             */
/*   Updated: 2021/01/20 23:17:25 by llescure         ###   ########.fr       */
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
	if (!(new = malloc(sizeof(char) * (end - start))))
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
	{
		new[j] = str[i];
		i++;
		j++;
	}
	new[end] = '\0';
	return (new);
}
