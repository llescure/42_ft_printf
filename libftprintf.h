/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llescure <llescure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:50:47 by llescure          #+#    #+#             */
/*   Updated: 2021/02/05 16:58:56 by llescure         ###   ########.fr       */
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
	int		compt;
	char	type;
}				t_flag;

int				ft_printf(const char *str, ...);
void			ft_print_cara(const char **str, t_flag *all_flag, char cara);
int				ft_print_percent(const char *str, t_flag *all_flag);
int				ft_print_string(const char *str, t_flag *all_flag,
		char *user_str);
int				ft_print_up_hexa(const char *str, t_flag all_flag,
		int user_nbr);
int				ft_print_low_hexa(const char *str, t_flag all_flag,
		int user_nbr);
int				ft_print_int(const char *str, t_flag all_flag, int user_nbr);
int				print_unsign(const char *str, t_flag all_flag,
		int user_nbr);
int				print_point(const char *str, t_flag all_flag,
		long unsigned user_nbr);

void			ft_initialisation(t_flag *all_flag);
int				ft_where_type_is(const char *str, int i);
void			ft_parse_flag(const char *str, int start, int end,
		t_flag *all_flag);
int				ft_parsing(const char *str, t_flag *all_flag);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_unsigned(unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_join_cara(char const *str, char cara);
int				ft_extract_number(const char *str, int compt);
char			*ft_trim(char *str, int start, int end);
int				ft_isascii(int c);
int				find_unsigned_size(unsigned int n);
int				find_size(long unsigned n);
int				valid_type(const char *str, int compt);
char			*ft_cut_str(const char *str, int compt);
char			*ft_strdup(const char *s1);
void			ft_change_user_nbr(char **user_nbr, t_flag *all_flag);
void			ft_print_minus(char **buf);
char			*ft_delete_multiple_cara(const char **str, char cara);
char			*ft_delete_cara(const char **str, char cara, t_flag all_flag);
char			*replace_first_wildcard(const char **str, char cara);
char			*replace_second_wildcard(const char **str, char cara);
int				check_weird_combination(const char **str, t_flag *all_flag);

void			ft_space(const char *str, t_flag *all_flag, char cara);
void			ft_space_minus(const char *str, t_flag *all_flag,
		char cara);
void			ft_space_percent(const char *str, t_flag *all_flag);
void			ft_space_minus_percent(const char *str, t_flag *all_flag);
void			ft_space_string(const char *str, t_flag *all_flag,
		char *user_str);
void			ft_space_minus_string(const char *str, t_flag *all_flag,
		char *user_str);
void			ft_space_int(const char *str, t_flag *all_flag,
		char *user_nbr);
void			ft_space_minus_int(const char *str, t_flag *all_flag,
		char *user_nbr);
void			ft_zero_int(const char *str, t_flag *all_flag,
		char *user_nbr);
void			ft_zero_percent(const char *str, t_flag *all_flag, char cara);
int				ft_precision(const char *str, t_flag all_flag, char **user_nbr);
int				ft_precision_string(const char *str, t_flag all_flag,
		char *user_str);
void			error_case(t_flag *all_flag, const char **str);
void			int_error_case(t_flag *all_flag, const char **str);
void			str_error_case(t_flag *all_flag, const char **str);

char			*ft_get_buf_start(const char *str, t_flag *all_flag);
int				ft_join_buf_space(int number_of_spaces);
int				ft_join_buf_zero(int number_of_zeros);
char			*ft_get_buf_end(const char *str, t_flag *all_flag);

char			*ft_convert_address(long unsigned user_nbr, t_flag all_flag);
void			conv_wildcard(int arguments, int number_wildcard,
		t_flag *all_flag);
char			*ft_convert_hexa(long unsigned user_nbr, char *base);

#endif
