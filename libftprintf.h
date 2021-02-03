/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:50:47 by llescure          #+#    #+#             */
/*   Updated: 2021/02/03 12:35:25 by llescure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int		wildcard;
	int		wildcard_value1;
	int		wildcard_value2;
	int		minus;
	int		dot;
	int		zero;
	int		number;
	int		negative;
	char	type;
}				t_flag;

int				ft_printf(const char *str, ...);
int				ft_print_cara(const char *str, t_flag all_flag, char cara,
		char **buf);
int				ft_print_percent(const char *str, t_flag all_flag, char **buf);
int				ft_print_string(const char *str, t_flag all_flag,
		char *user_str, char **buf);
int				ft_print_up_hexa(const char *str, t_flag all_flag, int user_nbr,
		char **buf);
int				ft_print_low_hexa(const char *str, t_flag all_flag,
		int user_nbr, char **buf);
int				ft_print_int(const char *str, t_flag all_flag, int user_nbr,
		char **buf);
int				print_unsign(const char *str, t_flag all_flag,
		int user_nbr, char **buf);
int				print_point(const char *str, t_flag all_flag,
		long unsigned user_nbr, char **buf);

void			ft_initialisation(t_flag *all_flag);
int				ft_where_type_is(const char *str, int i);
void			ft_parse_flag(const char *str, int start, int end,
		t_flag *all_flag);
int				ft_parsing(const char *str, t_flag *all_flag);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_join_cara(char const *str, char cara);
int				ft_extract_number(const char *str, int compt);
char			*ft_trim(char *str, int start, int end);
int				ft_isascii(int c);
int				find_size(int n);
int				find_unsigned_size(unsigned int n);
int				ft_find_size(int n);
int				find_hexa_unsigned_size(long unsigned n);
int				valid_type(const char *str, int compt);
char			*ft_cut_str(const char *str, int compt);
char			*ft_strdup(const char *s1);
void			ft_change_user_nbr(char **user_nbr, t_flag *all_flag);
void			ft_print_minus(char **buf);
char			*ft_delete_multiple_cara(const char **str, char cara);
char			*ft_delete_cara(const char **str, char cara);
char			*replace_first_wildcard(const char **str, char cara);
char			*replace_second_wildcard(const char **str, char cara);
char			*check_weird_combination(const char **str, t_flag *all_flag);

int				ft_space(const char *str, t_flag all_flag, char **buf,
		char cara);
int				ft_space_minus(const char *str, t_flag all_flag,
		char **buf, char cara);
int				ft_space_percent(const char *str, t_flag all_flag, char **buf);
int				ft_space_minus_percent(const char *str, t_flag all_flag,
		char **buf);
int				ft_space_string(const char *str, t_flag all_flag, char **buf,
		char *user_str);
int				ft_space_minus_string(const char *str, t_flag all_flag,
		char **buf, char *user_str);
int				ft_space_int(const char *str, t_flag all_flag, char **buf, char
		*user_nbr);
int				ft_space_minus_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr);
int				ft_zero_int(const char *str, t_flag all_flag, char **buf,
		char *user_nbr);
int				ft_zero_percent(const char *str, t_flag all_flag, char **buf,
		char cara);
int				ft_precision(const char *str, t_flag all_flag, char **user_nbr);
int				ft_precision_string(const char *str, t_flag all_flag,
		char *user_str);
int				error_case(t_flag *all_flag, const char **str);
int				int_error_case(t_flag *all_flag, const char **str);
int				str_error_case(t_flag *all_flag, const char **str);

int				ft_get_buf_start(const char *str, char **buf);
int				ft_join_buf_space(char **buf, int number_of_spaces);
int				ft_join_buf_zero(char **buf, int number_of_zeros);
char			*ft_allocate_char_to_str(char *str, char cara);
int				ft_get_buf_end(const char *str, char **buf, t_flag all_flag);

char			*ft_convert_address(long unsigned user_nbr, t_flag all_flag);
void			conv_wildcard(int arguments, int number_wildcard,
		t_flag *all_flag);
char			*ft_convert_lower_hexa(int user_nbr, char *base);
char			*ft_convert_upper_hexa(int user_nbr, char *base);
char			*ft_convert_address_hexa(long unsigned user_nbr, char *base);

#endif
