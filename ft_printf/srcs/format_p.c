/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:17:37 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/14 17:46:25 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_format_p(t_params *m)
{
	long long int	p;
	int				i;
	char 			hex[16] = "0123456789abcdef";
	char			res[sizeof(p)];

	p = (long long int)m->poin;
	i = 0;
	while (i <= (sizeof(p)))
    {
        res[i] = hex[p % 16];
        p = p / 16;
        i++;
    }
    res[i] = '\0';
    i--;
    if (m->poin == NULL)
    {
        res[1] = '\0';
        i = 0;
    }
    if (m->f_check_width != 0)
    {
        if (!(m->f_check_minus))
        {
            m->f_check_width = (m->f_check_width - (ft_strlen(&res[0]) + 2));
            while (--(m->f_check_width) >= 0)
                ft_putchar(' ');
            ft_putstr("0x");
            while (i >= 0)
            {
                ft_putchar(res[i]);
                i--;
            }
        }
        else
        {
            ft_putstr("0x");
            while (i >= 0)
            {
                ft_putchar(res[i]);
                i--;
            }
            m->f_check_width = (m->f_check_width - (ft_strlen(&res[0]) + 2));
            while (--(m->f_check_width) >= 0)
                ft_putchar(' ');
        }
    }
    else
    {
        ft_putstr("0x");
        while (i >= 0)
        {
            ft_putchar(res[i]);
            i--;
        }
    }
}

void	format_p(char *line, int i, va_list a)
{
	t_params	m;

    take_all_params(line, i, &m);
	m.poin = va_arg(a, void *);
	print_format_p(&m);
}