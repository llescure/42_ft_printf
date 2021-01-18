/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:49:17 by llescure          #+#    #+#             */
/*   Updated: 2021/01/18 14:49:40 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_flag
{
	int wildcard;
	int minus;
	int dot;
	int zero;
	int number;
	char type;
}		t_flag;

int		ft_printf(const char *str, ...);
t_flag	ft_initialisation(t_flag *all_flag);
int		ft_where_type_is(const char *str, int i);
t_flag	ft_parse_flag(const char *str, int start, int end, t_flag *all_flag);
int		ft_parsing(const char *str, t_flag *all_flag);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
