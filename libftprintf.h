/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:49:17 by llescure          #+#    #+#             */
/*   Updated: 2021/01/20 16:06:52 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_flag
{
	int wildcard;
	int wildcard_value1;
	int wildcard_value2;
	int minus;
	int dot;
	int zero;
	int number;
	char type;
}		t_flag;

int			ft_printf(const char *str, ...);
t_flag		ft_initialisation(t_flag *all_flag);
int			ft_where_type_is(const char *str, int i);
t_flag		ft_parse_flag(const char *str, int start, int end,
		t_flag *all_flag);
int			ft_parsing(const char *str, t_flag *all_flag);
size_t			ft_strlen(const char *str);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			error_case(t_flag all_flag);
int			ft_extract_number(const char *str, int compt);
int			ft_space(const char *str, t_flag all_flag, char **buf,
		char cara);
int			ft_space_minus(const char *str, t_flag all_flag,
		char **buf, char cara);
int			ft_print_cara(const char *str, t_flag all_flag, char cara,
		char **buf);
char		*ft_trim(char *str, int start, int end);
int			ft_get_buf_start(const char *str, int compt, char **buf);
int		ft_join_buf_space_after(char **buf, int number_of_spaces);
int		ft_join_buf_space_before(char **buf, int number_of_spaces);
int		ft_allocate_char_to_str(char **str, char cara);
void		ft_convert_wildcard(int arguments, int number_wildcard,
		t_flag *all_flag);
int		ft_isascii(int c);
