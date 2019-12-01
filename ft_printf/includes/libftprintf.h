/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:36:19 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 23:21:37 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define ALWAYS_POZITIVE(x)	(x >= 0 ? x : -x)
# define NALICIE_MINUSA(x) (x < 0 ? 1 : 0)
# define BIGGEST(x,y) (x > y ? x : y)
# define IS_HUNDRED(x) (x < 100 ? 0 : 1)
# define WHILE_NOT_ZERO(x) (x > 0 ? x - 1 : 0)
# define ISNULL(x) (x == 0 ? 0 : 1)
# include <libc.h>
# include "../libft/libft.h"

typedef struct				s_params
{
	long int				long_in;
	long long int			long_long_in;
	long long int			p;
	long unsigned int		unsigned_long_in;
	long long unsigned int	unsigned_long_long_in;
	unsigned int			unsigned_in;
	short unsigned int		unsigned_short_in;
	char					cha;
	char*					cha2;
	char*					res;
	char					*manta;
	void*					poin;
	float					flo;
	double					doubl;
	int						isnull;
	int						short_in;
	int						type;
	int						in;
	int						short_short_in;
	int						ff;
	int						i;
	int						number;
	int						len;
	int						f_check_width;
	int						f_check_minus;
	int						f_check_plus;
	int						f_check_zero;
	int						f_check_presicion;
	int						f_check_octotorp;
	int						f_check_space;
	int						f_otricatelnoe;
	int						f_check_point;
	int						f_check_value_precision;
	int						f_check_long_int;
	int						f_check_short_int;
}							t_params;

void						to_d(char *line, int i, t_params m, va_list a);
void						ox_s(t_params *m, int flag, char *resx, int in);
void						choose_unsigned(t_params *m, int number);
void						choose_int(t_params *m, int number);
void						to_hhu(char *line, int i, t_params m, va_list a);
void						to_hu(char *line, int i, t_params m, va_list a);
void						to_llu(char *line, int i, t_params m, va_list a);
void						to_lu(char *line, int i, t_params m, va_list a);
void						to_u(char *line, int i, t_params m, va_list a);
void						to_hhd(char *line, int i, t_params m, va_list a);
void						to_hd(char *line, int i, t_params m, va_list a);
void						to_lld(char *line, int i, t_params m, va_list a);
void						to_ld(char *line, int i, t_params m, va_list a);
void						print_width_2(t_params *m, int size_number);
void						print_width_1(t_params *m, int size_number, int i);
void						print_p_more(t_params *m, int size_number, int i);
void						print_only_d_u(t_params *m);
int							number_counting_x(long long int nbr);
int							number_counting(size_t in);
int							ft_check_octotorp(char *line, int i);
int							ft_check_plus(char *line, int i);
int							ft_check_short_int(char *line, int i);
int							ft_check_zero(char *line, int i);
int							ft_check_space(char *line, int i);
int							count_flags(char *line, int i);
int							take_width(char *line, int i);
int							take_presicion(char *line, int i);
int							ft_atoi_easy(char *line);
int							ft_check_all_flags(char *line, int i);
int							ft_check_point(char *line, int i);
int							count_flags(char *line, int i);
int							number_counting(size_t in);
int							take_presicion(char *line, int i);
int							ft_check_short_int(char *line, int i);
int							ft_check_point(char *line, int i);
int							ft_check_all_flags(char *line, int i);
int							ft_check_space(char *line, int i);
int							ft_check_zero(char *line, int i);
int							ft_check_octotorp(char *line, int i);
int							ft_check_plus(char *line, int i);
int							ft_check_minus(char *line, int i);
int							ft_check_value(char *line, int i);
int							ft_check_long_int(char *line, int i);
int     					ft_check_long_f(char *line, int i);
int							ft_atoi_sharp(const char *nptr);
int							ft_choose_flags(char *line, int i);
int							take_width(char *line, int i);
void						ft_put_choose(t_params *m);
void						to_int(char *line, int i, t_params m, va_list a);
void						take_all_params(char *line, int i, t_params *m);
void						choose_char(t_params *m, int number);
void						ft_put_choose(t_params *m);
void						convert_to_sixteen(char *line, int i, t_params *m);
void						help(char *x, int n, t_params *m, char *line);
void						take_all_params(char *line, int i, t_params *m);
void						print_format_c(t_params *m);
void						print_format_o8(t_params *m);
void						print_format_p(t_params *m);
void						print_format_str(t_params *m);
void						print_format_d(t_params *m, int size_number);
void						format_x(char *line, int i, va_list a, int flag);
void						format_str(char *line, int i, va_list a);
void						format_c(char *line, int i, va_list a, int flag);
void						d_u(char *line, int i, va_list a, t_params m);
void						format_p(char *line, int i, va_list a);
void						format_o8(char *line, int i, va_list a);
void						format_f(char *line, int i, va_list a);
void						ft_putstrrev(char *src, t_params *m, int in);

#endif
