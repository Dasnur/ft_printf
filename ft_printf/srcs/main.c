/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:17:30 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/17 22:09:44 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int     ft_check_point(char *line, int i)
{
    while(ft_check_all_flags(line, i))
    {
        if (line[i] == '.')
            return (1);
        i++;
    }
    return (0);
}

void    take_all_params(char *line, int i, t_params *m)
{
    m->f_check_octotorp         = ft_check_octotorp(line, i);
    m->f_check_minus            = ft_check_minus(line, i);
    m->f_check_plus             = ft_check_plus(line, i);
    m->f_check_zero             = ft_check_zero(line, i);
    m->f_check_space            = ft_check_space(line, i);
    m->f_check_width            = take_width(line, i);
    m->f_check_presicion        = take_presicion(line, i);
    m->f_check_width            = Always_pozitive(m->f_check_width);
    m->f_check_long_int         = ft_check_long_int(line, i);
    m->f_check_short_int        = ft_check_short_int(line, i);
    m->f_check_point            = ft_check_point(line, i);
    m->f_check_value_precision  = take_presicion(line, i);   
    m->ff = 0;
 //   m->f_check_value_precision = -1;
}

int     ft_check_all_flags(char *line, int i)
{
    if (line[i] != 'c' && line[i] != 's' && line[i] != 'p' && line[i] != 'd' &&
    line[i] != 'i' && line[i] != 'o' && line[i] != 'u' && line[i] != 'x' &&
    line[i] != 'X' && line[i] != 'f' && line[i] != '%')
        return (1);
    return (0);
}

int     ft_atoi_easy(char *line)
{
    int number;

    number = 0;
    while (*line >= '0' && *line <= '9')
    {
        number *= 10;
        number = number + (*line - '0');
        line++;
    }
    return (number);
}

int     take_presicion(char *line, int i)
{
    char    *t;
    int     f;
    int     number;
    
    number = 0;
    f = 0;
    while (ft_check_all_flags(line, i))
    {
        if(line[i] == '.')
        {
            t = &line[i + 1];
            f = 1;
            number = 0;
            number = ft_atoi_easy(t);
            i = i + number_counting(number);
            i = i + (number_counting(number) == 0 ? 1 : 0);
        }
        else
            i++;
    }
     if (f && !number)
         return (-1);
    return (number);
}

int     take_width(char *line, int i)
{
    char    *t;
    int     number;
    
    number = 0;
    while (ft_check_all_flags(line, i))
    {
        if (line[i] >= '0' && line[i] <= '9' && !ft_isdigit(line[i - 1]) && line[i - 1] != '.')
        {
            t = &line[i]; 
            number  = ft_atoi_easy(t);
            t = NULL;
            i = i + number_counting(number);
            i = i + (number_counting(number) == 0 ? 1 : 0);
        }
        else
            i++;
    }
    return (number);
}

int     count_flags(char *line, int i)
{
    while (ft_check_all_flags(line, i))
        i++;
    return (i);
}


int     ft_check_space(char *line, int i)
{
    while (line[i] != 'd' && line[i] != 'i' && line[i] != 'f' && line[i] != 'u')
        {
            if (line[i] == ' ')
                return (1);
            i++;
        }
    return (0);
}

int     ft_check_zero(char *line, int i)
{
    while (ft_check_all_flags(line, i) && (line[i] < '1' || line[i] >'9'))
    {
        if (line[i] == '0' && line[i - 1] != '.' && !ft_isdigit(line[i - 1]))
            return (1);
        i++;
    }
    return (0);
}

int     ft_check_octotorp(char *line, int i)
{
    while (line[i] != 'o' && line[i] != 'x' && line[i] != 'X')
    {
        if (line[i] == '#')
            return (1);
        i++;
    }
    return (0);
}

int     ft_check_plus(char *line, int i)
{
    while (line[i] != 'f' && line[i] != 'd' && line[i] != 'i')
    {
        if (line[i] == '+')
            return (1);
        i++;
    }
    return (0);
}

int     ft_check_short_int(char *line, int i)
{
    while(line[i] != 'd' && line[i] != 'i')
    {
        if (line[i] == 'h' && (line[i + 1] == 'd' || line[i + 1] == 'i' || line[i + 1] == 'u'))
            return (1);
        if (line[i] == 'h' && line[i + 1] == 'h' && (line[i + 2] == 'd' || line[i + 2] == 'i' || line[i + 2] == 'u'))
            return (2);
        i++;
    } 
    return (0);
}

int     ft_check_long_int(char *line, int i)
{
    while(line[i] != 'd' && line[i] != 'i')
    {
        if (line[i] == 'l' && (line[i + 1] == 'd' || line[i + 1] == 'i' || line[i + 1] == 'u' || line[i + 1] == 'o' || line[i + 1] == 'x' || line[i + 1] == 'X'))
        {
            return (1);
        }
        if (line[i] == 'l' && line[i + 1] == 'l' && (line[i + 2] == 'd' || line[i + 2] == 'i' || line[i + 2] == 'u' || line[i + 2] == 'o'))
        {
            return (2);
        }
        i++;
    } 
    return (0);
}

int     ft_check_minus(char *line, int i)
{
    while (ft_check_all_flags(line, i))
    {
        if (line[i] == '-')
            return (1);
        i++;
    }
    return (0);
}

int     ft_choose_flags(char *line, int i)
{
    while (ft_check_all_flags(line, i))
        i++;
    if (line[i] == 'c')
        return (1);
    if (line[i] == 's')
        return (2);
    if (line[i] == 'p')
        return (3);
    if (line[i] == 'd' || line[i] == 'i')
        return (4);
    if (line[i] == 'o')
        return (5);
    if (line[i] == 'u')
        return (6);
    if (line[i] == 'x')
        return (7);
    if (line[i] == 'X')
         return (8);
    if (line[i] == 'f')
        return (9);
    if (line[i] == '%')
        return (10);
    return (-1);
}

int     ft_crossroads(int i, va_list a, char *line)
{
    t_params m;

    m.type = ft_choose_flags(line, i);
    if (m.type == 1)
       format_c(line, i, a, m.type);
    if (m.type == 4 || m.type == 6)
        format_d_ld_lld_hd_hhd(line, i, a, m);
    if (m.type == 2)
        format_str(line, i, a);
    if (m.type == 3)
        format_p(line, i, a);
    if (m.type == 5)
        format_o8(line, i, a);
    if (m.type == 7 || m.type == 8)
        format_x(line, i, a, m.type);
    if (m.type == 9)
        format_f(line, i, a);
    //     my_function();
    // if (ft_choose_flags(line, i) == 8)
    //     my_function();
    // if (ft_choose_flags(line, i) == 9)
    //     my_function();
    if (ft_choose_flags(line, i) == 10)
        format_c(line, i, a, m.type);
    return (0);
}

void    ft_printf(char *line, ...)
{
    int     i;
    va_list a;

    i = 0;
    va_start(a, line);
    while(line[i])
    {
        if (line[i] == '%' && line [i + 1] == '%')
        {
            i += 2;
            ft_putchar('%');
            continue ;
        }
        if (line[i] != '%')
        {
            ft_putchar(line[i]);
            i++;
            continue ;
        }
        else if(line[i] == '%')
        {
            ft_crossroads(i + 1, a, line);
            i = count_flags(line, i + 1);
        }
        i++;
    }
    va_end(a);
}
//int main(int ac, char **av)
//{
//   static char a01;
//   unsigned long a = 0;
//   int n = 43;
//      double abc = 3.4;
//   ft_printf("|%08.5x|\n", n);
//    printf ("|%08.5o|\n", 34);
//   ft_printf ("|%08.5o|\n", 34);
 //    printf ("|%#3o|\n", 0);
 //   ft_printf("|%.10f|\n", 0.87650894255);
 //  printf("|%.10f|\n", 0.87650894255);
  //  ft_printf("|%f|\n", 23.375094499);
 //  printf("|%f|\n", 23.375094499);
 //   ft_printf("|%f|\n", -985.765426499);
  //  printf("|%f|\n", -985.765426499);
 //   ft_printf("|%f|\n", -56.2012685);
 //   printf("|%f|\n", -56.2012685);
 //   ft_printf("|%.10f|\n", -985.2459765426499);
//    printf("|%.10f|\n", -985.2459765426499);
//ft_printf("|%.16f|\n",  0.999999999999999900);
//printf("|%.16f|\n",  0.999999999999999900);
//printf("|% 5.1f|\n", -7.3);
//ft_printf("|% 5.1f|\n", -7.3);
//}