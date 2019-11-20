/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:36:19 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/17 20:08:34 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define Always_pozitive(x) (x >= 0 ? x : -x)
# define Nalicie_minusa(x)  (x < 0 ? 1 : 0)
# define Biggest(x,y)       (x > y ? x : y)
# define is_hundred(x)      (x < 100 ? 0 : 1)
# define while_not_zero(x)  (x > 0 ? x - 1 : 0)
# define isnull(x)          (x == 0 ? 0 : 1)
# include <libc.h>
# include "../libft/libft.h"

typedef struct s_params
{
    int                     type;
    int                     in;
    long int                long_in;
    long long int           long_long_in;
    int                     short_in;
    int                     short_short_in;
    long unsigned int       unsigned_long_in;
    long long unsigned int  unsigned_long_long_in;
    unsigned int            unsigned_in;
    short unsigned int      unsigned_short_in;
    char                    cha;
    char*                   cha2;
    void*                   poin;
    int                     isnull;
    float                   flo;
    double                  doubl;
    int                     ff;
    int                     f_check_width;
    int                     f_check_minus;
    int                     f_check_plus;
    int                     f_check_zero;
    int                     f_check_presicion;
    int                     f_check_octotorp;
    int                     f_check_space;
    int                     f_otricatelnoe;
    int                     f_check_point;
    int                     f_check_value_precision;
    int                     f_check_long_int;
    int                     f_check_short_int;
}                           t_params;

void                        choose_char(t_params *m, int number);
void                        ft_put_choose(t_params *m);
void                        convert_to_sixteen(char *line, int i, t_params *m);
void                        ft_putstrrev(char *src);
void                        help(char *x, int n, t_params *m, char *line);
int                         count_flags(char *line, int i);
int                         number_counting(size_t in);
int                         take_presicion(char *line, int i);
void                        take_all_params(char *line, int i, t_params *m);
int                         take_width(char *line, int i);
void                        print_format_c(t_params *m);
void                        print_format_o8(t_params *m);
void	                    print_format_p(t_params *m);
void	                    print_format_str(t_params *m);
void                        print_format_d(t_params *m, int size_number);
int                         ft_check_short_int(char *line, int i);
int                         ft_check_point(char *line, int i);
int                         ft_check_all_flags(char *line, int i);
int                         ft_check_space(char *line, int i);
int                         ft_check_zero(char *line, int i);
int                         ft_check_octotorp(char *line, int i);
int                         ft_check_plus(char *line, int i);
int                         ft_check_minus(char *line, int i);
int                         ft_check_value(char *line, int i);
int                         ft_check_long_int(char *line, int i);
int		                    ft_atoi_sharp(const char *nptr);
int                         ft_choose_flags(char *line, int i);
void                        format_x(char *line, int i, va_list a, int flag);
void	                    format_f(char *line, int i, va_list a);
void	                    format_str(char *line, int i, va_list a);
void                        format_c(char *line, int i, va_list a, int flag);
void                        format_d_ld_lld_hd_hhd(char *line, int i, va_list a, t_params m);
void                        format_p(char *line, int i, va_list a);
void                        format_o8(char *line, int i, va_list a);

#endif