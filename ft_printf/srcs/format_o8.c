/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:46 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/14 17:46:21 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/libftprintf.h"

void    ft_putstrrev(char *src)
{
    int i;

    while (src[i] != '\0')
        i++;
    i--;
    while (i >= 0)
    {
        ft_putchar(src[i]);
        i--;
    }
}

void    print_format_o8(t_params *m)
{
    int i;
    int number;
    int len;
    char    *res;
    unsigned long int    in;

    len = 0;
    i = 0;
    if (m->in < 0)
        in = 4294967296 + m->unsigned_long_in;
    else
        in = m->unsigned_long_in;
    number = m->unsigned_long_in;
    while (number != 0)
    {
        number /= 8;
        len++;
    }
    res = (char *)malloc(sizeof(char) * (100));
    if (in == 0 && m->f_check_value_precision != -1 && m->f_check_value_precision != 0 && m->f_check_width)
        res[i++] = '0';
    while (in)
    {
        res[i] = in % 8 + 48;
        in /= 8;
        i++;
    }
    res[i] = '\0';
    if (m->unsigned_long_in == 0 && m->f_check_octotorp && (m->f_check_value_precision == -1 || m->f_check_value_precision == 0))
        res[i++] = '0';
    else if (m->unsigned_long_in == 0 && !m->f_check_octotorp && m->f_check_value_precision != -1)
        res[i++] = '0';
    else if (m->unsigned_long_in == 0 && !m->f_check_octotorp && m->f_check_value_precision == 0)
        res[i++] = '0';
    if (m->f_check_octotorp && m->unsigned_long_in != 0 && m->f_check_value_precision <= (int)ft_strlen(res))
        res[i++] = '0';
    if (m->f_check_value_precision > (int)ft_strlen(res))
    {
        m->f_check_value_precision = (m->f_check_value_precision - ft_strlen(res));
        while (--(m->f_check_value_precision) >= 0)
        {
            res[i] = '0';
            i++;
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
            while (--(m->f_check_width) > 0)
            {
                if (m->f_check_zero && m->f_check_presicion == 0)
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

void    format_o8(char *line, int i, va_list a)
{
    t_params    m;

    take_all_params(line, i, &m);
    if (m.f_check_long_int)
        m.unsigned_long_in = va_arg(a, unsigned long int);
    else
    {
        m.in = va_arg(a, int);
        m.unsigned_long_in = m.in;
    }
    print_format_o8(&m);
}