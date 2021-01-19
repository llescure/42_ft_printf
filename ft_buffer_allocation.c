/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:34:25 by llescure          #+#    #+#             */
/*   Updated: 2021/01/19 13:08:02 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_buf_start(char *str, int compt, char **buf)
{
	char *temp;
	int i

	if(!(buf = malloc(sizeof(char))))
		return (-1);
	buf[0] = "";
	i = 0;
	while (i < compt)
	{
		temp = buf;
		ft_strjoin(buf, str[i]);
		free(temp);
		i++;
	}
}

void	ft_join_buf_space(char *str, char **buf, int start, int compt)
{
	char *temp;

	while (start <= compt)
	{
		temp = buf;
		ft_strjoin(buf, ' ');
		free(temp);
		start++;
	}
}

int		ft_get_buf_end(char *str, char **buf, int compt)
