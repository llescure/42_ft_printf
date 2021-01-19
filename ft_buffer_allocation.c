/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:34:25 by llescure          #+#    #+#             */
/*   Updated: 2021/01/19 20:28:57 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_buf_start(char *str, int compt, char **buf)
{
	char *temp;
	char *str_trimmed

	if(!(*buf = malloc(sizeof(char))))
		return (-1);
	*buf[0] = "";
	temp = *buf;
	str_trimmed = ft_trim(str, 0, compt);
	ft_strjoin(*buf, str_trimmed);
	free(temp);
	return (0);
}

char	*ft_join_buf_space_after(char *str, char **buf, int start,
		int number_of_spaces)
{
	char *temp;
	char *spaces;
	int i;

	i = 0;
	while (i < (compt - start))
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[compt - start] = '\0';
	temp = *buf;
	*buf = ft_strjoin(*buf, spaces);
	free(temp);
}

char	*ft_join_buf_space_before(char *str, char **buf, int start,
		int number_of_spaces)
{
	char *temp;
	char *spaces;
	int i;

	i = 0;
	while (i < (compt - start))
	{
		spaces[i] = ' ';
		i++;
	}
	spaces[compt - start] = '\0';
	temp = *buf;
	*buf = ft_strjoin(spaces, *buf);
	free(temp);
}
