/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:08:41 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/17 22:09:31 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int     number_counting_x(long long int nbr)
{
    int i;
    int tmp;

    tmp = nbr;
    i   = 0;
    while (1)
    {
        nbr /= 16;
        i++;
        if (nbr == 0)
            break ;
    }
    return (i);
}

int     string_counter(char *line)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    return (i);
}

void    print_format_ox(t_params *m, char *line, int flag)
{
    int             i;
    char            *res;
  //  int             number;
    char            *resx;
    unsigned long int   in;

    i = 0;
    resx = "0123456789abcdef0123456789ABCDEF";
    m->type = ft_choose_flags(line, i);
 //   number = number_counting_x(m->unsigned_long_in);
    if (!(res = malloc(sizeof(char) * (100))))
        return ;
    in = m->unsigned_long_in;
  //  if (in == 0 && m->f_check_value_precision != -1 && m->f_check_value_precision != 0 && m->f_check_width)
 //       res[i++] = '0';
    while(in)
    {
        if (flag == 8)
            res[i] = resx[in % 16 + 16];
        else
            res[i] = resx[in % 16];
        i++;
        in /= 16;  
    }
    res[i] = '\0';
    if (m->unsigned_long_in == 0 && m->f_check_octotorp && m->f_check_value_precision != -1)
    {
        res[i++] = '0';
    }
    if (m->unsigned_long_in == 0 && !m->f_check_octotorp && m->f_check_value_precision != -1)
        res[i++] = '0';
    else if (m->unsigned_long_in == 0 && !m->f_check_octotorp && m->f_check_value_precision == 0)
        res[i++] = '0';
    if (m->f_check_octotorp && m->unsigned_long_in != 0 && m->f_check_value_precision <= (int)ft_strlen(res) && m->f_check_zero == 0)
    {
        if (flag == 8)
            res[i++] = 'X';
        else
            res[i++] = 'x';
        res[i++] = '0';
    }
    else if (m->f_check_octotorp && m->f_check_value_precision <= m->f_check_width && m->f_check_value_precision < ft_strlen(res) && m->f_check_value_precision != 0)
    {
        if (flag == 8)
            res[i++] = 'X';
        else
            res[i++] = 'x';
        res[i++] = '0';
    }
    if (m->f_check_value_precision > (int)ft_strlen(res))
    {
        m->f_check_value_precision = (m->f_check_value_precision - ft_strlen(res));
        while (--(m->f_check_value_precision) >= 0)
        {
            res[i] = '0';
            i++;
        }
        if (m->f_check_octotorp && m->unsigned_long_in != 0)
        {
            if (flag == 8)
                res[i++] = 'X';
            else
                res[i++] = 'x';
            res[i++] = '0';
        }
    }
    res[i] = '\0';
    if (m->f_check_width != 0)
    {
        if (m->f_check_minus)
        {
            ft_putstrrev(res);
            m->f_check_width = (m->f_check_width - ft_strlen(res) + 1);
            while (--(m->f_check_width) > 0)
                ft_putchar(' ');
        }
        else
        {
            m->f_check_width = (m->f_check_width - ft_strlen(res) + 1);
            if (m->f_check_zero && m->f_check_value_precision == 0 && m->f_check_octotorp && m->unsigned_long_in != 0)
            {
                if (flag == 8)
                    ft_putstr("0X");
                else
                    ft_putstr("0x");
                m->f_check_width = m->f_check_width - 2;
            }
            while (--(m->f_check_width) > 0)
            {
                if (m->f_check_zero && m->f_check_value_precision == 0)
                    ft_putchar('0');
                else
                    ft_putchar(' ');
            }
            ft_putstrrev(res);
        }
    }
    else
        ft_putstrrev(res);
}

//void    help(char *x, int n, t_params *m, char *line)
//{
//    int     i;
//    int     count;
//    int     tmp;
//
//    i = 0;
//    count = string_counter(x);
//    if (m->f_check_width > m->f_check_presicion)
//    {
//        if (m->f_check_minus)
//        {
//            if (m->f_check_octotorp)
//                ft_putstr(m->type == 7 ? "0x" : "0X");
//            tmp = m->f_check_presicion;
//            // if (m->f_check_presicion <= 0)
//            //     tmp = m->f_check_width;
//            while (tmp > count && (m->f_check_zero || m->f_check_presicion > 0))
//            {
//                ft_putchar('0');
//                count++;
//            }
//            ft_putstr(x);
//            count = string_counter(x);
//            while ((Biggest(m->f_check_presicion, count) + (m->f_check_octotorp * 2)) < m->f_check_width)
//            {
//                ft_putchar(' ');
//                m->f_check_width--;
//            }
//        }
//        else
//        {
//            // if ((m->f_check_presicion <= count && m->f_check_presicion) || (m->f_check_width && !m->f_check_zero))
//            //     while ((Biggest(m->f_check_presicion, count) + (m->f_check_octotorp * 2)) < m->f_check_width)
//            //     {
//            //         ft_putchar(' ');
//            //         m->f_check_width--;
//            //     }
//            while ((m->f_check_width - m->f_check_presicion - count) > 0)
//            {
//                ft_putchar(' ');
//                m->f_check_width--;
//            }
//            if (m->f_check_octotorp)
//                ft_putstr(m->type == 7 ? "0x" : "0X");
//            tmp = m->f_check_presicion;
//            if (m->f_check_zero)
//                tmp = Biggest(m->f_check_presicion, m->f_check_width);
//            while (tmp > count)
//            {
//                ft_putchar('0');
//                count++;
//            }
//            ft_putstr(x);
//            count = string_counter(x);
//        }
//    }
//    else if (m->f_check_width < m->f_check_presicion)
//    {
//        if (m->f_check_octotorp)
//            ft_putstr(m->type == 7 ? "0x" : "0X");
//        while (count < m->f_check_presicion)
//        {
//            ft_putchar('0');
//            count++;
//        }
//        ft_putstr(x);
//    }
//    else
//        ft_putstr(x);
//}

//void    convert_to_sixteen(char *line, int i, t_params *m)
//{
//    char            *x;
//    int             number;
//    int             n;
//    char            *resx;
//
//    resx = "0123456789abcdef0123456789ABCDEF";
//    m->type = ft_choose_flags(line, i);
//    number = number_counting_x(m->unsigned_long_in);
//    n = number;
//    if (!(x = malloc(sizeof(char*) * (number + 1))))
//        return ;
//    x[number] = '\0';
//    number--;
//    while(number >= 0)
//    {
//        if (m->type == 8)
//            x[number] = resx[m->unsigned_long_in % 16 + 16];
//        else
//            x[number] = resx[m->unsigned_long_in % 16];
//        number--;
//        m->unsigned_long_in /= 16;  
//    }
//    if (m->f_check_octotorp)
//        m->type == 8 ? ft_putstr("0x") : ft_putstr("0X");
//    format_ox(x, n, m, line);
//}

void    format_x(char *line, int i, va_list a, int flag)
{
    t_params m;

    take_all_params(line, i, &m);
    if (m.f_check_long_int)
        m.unsigned_long_in = va_arg(a, unsigned long int);
    else
    {
        m.in = va_arg(a, int);
        m.unsigned_long_in = m.in;
    }
 //   m.ff            = is_hundred(m.unsigned_long_in);
 //   m.isnull        = isnull(m.unsigned_long_in);
 //   convert_to_sixteen(line, i, &m);
    print_format_ox(&m, line, flag);
}