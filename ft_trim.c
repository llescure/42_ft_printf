/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:50:43 by llescure          #+#    #+#             */
/*   Updated: 2021/01/18 22:53:35 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_trim(char *str, int start, int end)
{
	char *new;
	int i;
	int j;

	i = start;
	j = 0;
	while (i <= end)
	{
		new[j] = str[i];
		i++;
		j++;
	}
	return (new);
}
