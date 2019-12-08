/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:05:02 by atote             #+#    #+#             */
/*   Updated: 2019/12/08 18:07:08 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	goodline_e(t_params *m, char *resnew, int *len)
{
	int	i;

	i = number_counting(ALWAYS_POZITIVE(m->long_long_in));
	if (m->type == 91 || m->type == 911)
	{
		*len = i;
		while (ALWAYS_POZITIVE(m->long_long_in) >= 10)
		{
			resnew[--i] = ALWAYS_POZITIVE(m->long_long_in) % 10 + 48;
			m->long_long_in = m->long_long_in / 10;
			m->ff++;
		}
	}
	if (m->type == 92)
		m->f_check_width = m->f_check_width - 1;
}

void	print_with_precision_e(char *res, int ff, int type)
{
	if (type == 91)
	{
		ft_putstr("e+0");
		ft_putnbr(ff);
	}
	if (type == 911)
	{
		ft_putstr("E+0");
		ft_putnbr(ff);
	}
}

int		check_len_f(t_params *m)
{
	int	len;

	len = m->f_check_value_precision + 1 +
		number_counting_in(m->long_long_in) + m->f_check_plus;
	if (m->long_long_in < 0 && !m->f_check_plus)
		len++;
	if (m->long_long_in == 0 && 1 / m->doubl > 0 && 1 / m->doubl != 1.0 / 0.0)
		len++;
	return (len);
}
