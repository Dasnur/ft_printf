/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_ld_lld_hd_hhd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:42:02 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/17 19:29:07 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int number_counting(size_t in)
{
    int i;
    
    i = 0;
    if (in == 0)
        return (1);
    while(in != 0)
    {
        in /= 10;
        i++;
    }
    return (i);
}

int     ft_isnull(t_params *m, int number)
{
    if (!m->isnull && m->f_check_presicion == -1)
    {
        while (--number >= 0)
            write(1, " ", 1);
        return (1);
    }
    return (0);
}

void    choose_int(t_params *m, int number)
{
    if (ft_isnull(m ,number))
        return ;
    ft_putlonglong(m->long_long_in);
}

void    choose_unsigned(t_params *m, int number)
{
    if (ft_isnull(m ,number))
        return ;
    ft_putunsignedlong(m->unsigned_long_long_in);
}

void    choose_char(t_params *m, int number)
{
    if (ft_isnull(m ,number))
        return ;
    ft_putstr(m->cha2);
}

void    ft_put_choose(t_params *m)
{
    int number;

    number = number_counting(m->long_long_in);
    if(m->ff)
        m->long_long_in = Always_pozitive(m->long_long_in);
    if (m->type == 4)
        choose_int(m, number);
    if (m->type == 6)
        choose_unsigned(m, number);
    if (m->type == 7 || m->type == 8)
        choose_char(m, number);
}

void    print_format_d(t_params *m, int size_number)
{
    int i;

    i = 0;
    if (m->f_check_width <= (size_number + m->f_check_plus) && m->f_check_presicion <= (m->f_check_plus + size_number))
    {
        if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
            ft_putchar('+');
        if ((m->type == 4 || m->type == 6) && m->f_otricatelnoe)
        {
            m->ff = 1;
            ft_putchar('-');
        }
        else if(m->f_check_space && !m->f_check_plus && !m->f_otricatelnoe)
            ft_putchar(' ');
        ft_put_choose(m);
    }
    else if (m->f_check_presicion > m->f_check_width)
    {
        if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
            ft_putchar('+');
        else if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
        {
            ft_putchar('-');
            m->ff = 1;
        }
        else if (m->f_check_space)
        {
            ft_putchar(' ');
            m->f_check_width--;
        }
        while ((m->f_check_presicion - size_number) != i)
        {
            ft_putchar('0');
            i++;
        }
        ft_put_choose(m);
    }
    else if (m->f_check_width >= m->f_check_presicion)
    {
        if (m->f_check_minus)
        {
            if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
                ft_putchar('+');
            else if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
            {
                ft_putchar('-');
                m->ff = 1;
            }
            else if (m->f_check_space)
            {
                ft_putchar(' ');
                m->f_check_width--;
            }
            while (m->f_check_presicion > size_number)
            {
                size_number++;
                ft_putchar('0');
            }
            ft_put_choose(m);
            while (m->f_check_width != ((m->f_check_plus || m->f_otricatelnoe) + Biggest(size_number, m->f_check_presicion)))
            {
                ft_putchar(' ');
                m->f_check_width--;
            }
        }
        else if (m->f_check_zero && !m->f_check_presicion)
        {
            if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
                ft_putchar('+');
            else if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
            {
                ft_putchar('-');
                m->ff = 1;
                m->f_check_width--;
            }
            else if (m->f_check_space)
            {
                ft_putchar(' ');
                m->f_check_width--;
            }
            while (m->f_check_width > (m->f_check_plus + size_number))
            {
                ft_putchar('0');
                m->f_check_width--;
            }
            ft_put_choose(m);
        }
        else if (m->f_check_presicion)
        {
            while (m->f_check_width != ((m->f_otricatelnoe || m->f_check_plus) + Biggest(size_number, m->f_check_presicion)))
            {
                ft_putchar(' ');
                m->f_check_width--;
            }
            if ((m->f_check_presicion > 0) && m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
                ft_putchar('+');
            if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
            {
                ft_putchar('-');
                m->ff = 1;
            }
            while (m->f_check_presicion > size_number)
            {
                ft_putchar('0');
                m->f_check_presicion--;
            }
            ft_put_choose(m);
            if (!m->isnull && (!m->f_check_presicion || m->f_check_presicion == -1) && m->f_check_plus)
                ft_putchar ('+');
        }
        else
        {
            while(m->f_check_width > (size_number + m->f_check_plus + m->f_otricatelnoe))
            {
                ft_putchar(' ');
                m->f_check_width--;
            }
            if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
                ft_putchar('+');
            ft_put_choose(m);
        }
    }
}

void        to_int(char *line, int i, t_params m, va_list a)
{

        m.long_long_in      = (int)va_arg(a, int);
        m.f_otricatelnoe    = Nalicie_minusa(m.long_long_in);
        m.isnull            = isnull(m.long_long_in);
        if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
        {
            if (m.f_check_plus)
                write(1, "+", 1);
            return ;
        }
        print_format_d(&m, number_counting(Always_pozitive(m.long_long_in)));
}

void        to_longint(char *line, int i, t_params m, va_list a)
{
        m.long_long_in      = (long int)va_arg(a, long int);
        m.f_otricatelnoe    = Nalicie_minusa(m.long_long_in);
        m.isnull            = isnull(m.long_long_in);
        if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
        {
            if (m.f_check_plus)
                write(1, "+", 1);
            return ;
        }
        print_format_d(&m, number_counting(Always_pozitive(m.long_long_in)));   
}


void        to_longlongint(char *line, int i, t_params m, va_list a)
{
    m.long_long_in      = va_arg(a, long long int);
    m.f_otricatelnoe    = Nalicie_minusa(m.long_long_in);
    m.isnull            = isnull(m.long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(Always_pozitive(m.long_long_in)));
}

void        to_shortint(char *line, int i, t_params m, va_list a)
{
    m.long_long_in          = (short int)va_arg(a, int);
    m.f_otricatelnoe        = Nalicie_minusa(m.long_long_in);
    m.isnull                = isnull(m.long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(Always_pozitive(m.long_long_in)));
}

void        to_shortshortint(char *line, int i, t_params m, va_list a)
{
    m.long_long_in    = (char)va_arg(a, int);
    m.f_otricatelnoe    = Nalicie_minusa(m.long_long_in);
    m.isnull            = isnull(m.long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(Always_pozitive(m.long_long_in)));
}

void        to_unsignedint(char *line, int i, t_params m, va_list a)
{
    m.unsigned_long_long_in = va_arg(a, unsigned int);
    m.f_otricatelnoe    = Nalicie_minusa(m.unsigned_long_long_in);
    m.isnull                = isnull(m.unsigned_long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void        to_unsignedlong(char *line, int i, t_params m, va_list a)
{
    m.unsigned_long_long_in = (long int)va_arg(a, long);
    m.f_otricatelnoe        = Nalicie_minusa(m.unsigned_long_long_in);
    m.isnull                = isnull(m.unsigned_long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void        to_unsignedlonglong(char *line, int i, t_params m, va_list a)
{
    m.unsigned_long_long_in = (unsigned long long)va_arg(a, unsigned long long);
    m.f_otricatelnoe        = Nalicie_minusa(m.unsigned_long_long_in);
    m.isnull                = isnull(m.unsigned_long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void        to_unsignedshort(char *line, int i, t_params m, va_list a)
{
    m.unsigned_long_long_in = (short unsigned int)va_arg(a, unsigned int);
    m.f_otricatelnoe        = Nalicie_minusa(m.unsigned_long_long_in);
    m.isnull                = isnull(m.unsigned_long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
    {
        if (m.f_check_plus)
            write(1, "+", 1);
        return ;
    }
    print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void        to_unsignedshortshort(char *line, int i, t_params m, va_list a)
{
    m.unsigned_long_long_in = (unsigned char)va_arg(a, unsigned int);
    m.f_otricatelnoe        = Nalicie_minusa(m.unsigned_long_long_in);
    m.isnull                = isnull(m.unsigned_long_long_in);
    if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
        return ;
    print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void        format_d_ld_lld_hd_hhd(char *line, int i, va_list a, t_params m)
{
    take_all_params(line, i, &m);
    if (!m.f_check_long_int && !m.f_check_short_int && m.type == 4)
        to_int(line, i, m, a);
    else if (m.f_check_long_int == 1 && m.type == 4)
        to_longint(line, i, m, a);
    else if (m.f_check_long_int == 2 && m.type == 4)
        to_longlongint(line, i, m, a);
    else if (m.f_check_short_int == 1 && m.type == 4)
        to_shortint(line, i, m, a);
    else if (m.f_check_short_int == 2 && m.type == 4)
        to_shortshortint(line, i, m, a);
    else if (m.type == 6 && !m.f_check_long_int && !m.f_check_short_int)
        to_unsignedint(line, i, m, a);
    else if (m.f_check_long_int == 1 && m.type == 6)
        to_unsignedlong(line, i, m, a);
    else if (m.f_check_long_int == 2 && m.type == 6)
        to_unsignedlonglong(line, i, m, a);
    else if (m.f_check_short_int == 1 && m.type == 6)
        to_unsignedshort(line, i, m, a);
    else if (m.f_check_short_int == 2 && m.type == 6)
        to_unsignedshortshort(line, i, m, a);
}