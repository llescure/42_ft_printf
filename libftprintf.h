/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:49:17 by llescure          #+#    #+#             */
/*   Updated: 2021/01/26 17:12:30 by llescure         ###   ########.fr       */
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
char		*ft_itoa(int n);
char		*ft_itoa_unsigned(unsigned int n);
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
int		ft_join_buf_space(char **buf, int number_of_spaces);
int		ft_join_buf_zero(char **Buf, int number_of_zeros);
char		*ft_allocate_char_to_str(char *str, char cara);
int			ft_get_buf_end(const char *str, char **buf, t_flag all_flag);
void		ft_convert_wildcard(int arguments, int number_wildcard,
		t_flag *all_flag);
int		ft_isascii(int c);
int			ft_space_percent(const char *str, t_flag all_flag, char **buf);
int			ft_space_minus_percent(const char *str, t_flag all_flag,
		char **buf);
int			ft_print_percent(const char *str, t_flag all_flag, char **buf);
int			ft_space_string(const char *str, t_flag all_flag, char **buf,
		char *user_str);
int			ft_space_minus_string(const char *str, t_flag all_flag,
		char **buf, char *user_str);
int			ft_print_string(const char *str, t_flag all_flag, char *user_str,
		char **buf);
int			ft_precision(const char *str, t_flag all_flag);
int			str_error_case(t_flag all_flag);
int			find_size(int n);
int			find_unsigned_size(unsigned int n);
int			ft_find_size(int n);
int			find_hexa_unsigned_size(long unsigned n);
char		*ft_convert_lower_hexa(int user_nbr);
char		*ft_convert_upper_hexa(int user_nbr);
char		*ft_convert_address_hexa(long unsigned user_nbr);
int		int_error_case(t_flag all_flag);
int		ft_space_int(const char *str, t_flag all_flag, char **buf, char
		*user_nbr);
int		ft_space_minus_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr);
int		ft_print_low_hexa(const char *str, t_flag all_flag, int user_nbr,
		char **buf);
int		ft_zero_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr);
int		ft_print_up_hexa(const char *str, t_flag all_flag, int user_nbr,
		char **buf);
int		ft_print_int(const char *str, t_flag all_flag, int user_nbr,
		char **buf);
int		ft_print_unsigned_int(const char *str, t_flag all_flag, int user_nbr,
		char **buf);
char	*ft_convert_address(long unsigned user_nbr);
int		ft_print_pointer(const char *str, t_flag all_flag, long unsigned user_nbr,
		char **buf);
