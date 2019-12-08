/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:46 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/08 19:18:40 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putstrrev(char *src, t_params *m, int in)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	i--;
	if ((in == -2147483648 || in == -8000) && (i == 17 || i == 15))
	{
		if (m->f_check_octotorp)
		{
			ft_putchar(src[i--]);
			ft_putchar(src[i--]);
		}
		i = i / 2;
	}
	while (i >= 0)
	{
		ft_putchar(src[i]);
		i--;
	}
}

void	format_o8_third(t_params *m, int in)
{
	if (m->f_check_width != 0)
	{
		if (m->f_check_minus)
		{
			ft_putstrrev_o8(m->res);
			m->f_check_width = (m->f_check_width - ft_strlen(m->res) + 1);
			while (--(m->f_check_width) > 0)
				ft_putchar(' ');
		}
		else
		{
			m->f_check_width = (m->f_check_width - ft_strlen(m->res) + 1);
			while (--(m->f_check_width) > 0)
			{
				if (m->f_check_zero && m->f_check_presicion == 0)
					ft_putchar('0');
				else
					ft_putchar(' ');
			}
			ft_putstrrev_o8(m->res);
		}
	}
	else
		ft_putstrrev_o8(m->res);
}

void	format_o8_second(t_params *m, int in)
{
	if ((m->unsigned_long_in == 0 && m->f_check_octotorp &&
	(m->f_check_value_precision == -1 || m->f_check_value_precision == 0)) ||
	(m->unsigned_long_in == 0 && !m->f_check_octotorp &&
	m->f_check_value_precision != -1) || (m->unsigned_long_in == 0 &&
	!m->f_check_octotorp && m->f_check_value_precision == 0))
		m->res[m->i++] = '0';
	if (m->f_check_octotorp && m->unsigned_long_in != 0 &&
		m->f_check_value_precision <= (int)ft_strlen(m->res))
		m->res[m->i++] = '0';
	if (m->f_check_value_precision > (int)ft_strlen(m->res))
	{
		m->f_check_value_precision = (m->f_check_value_precision -
				ft_strlen(m->res));
		while (--(m->f_check_value_precision) >= 0)
		{
			m->res[m->i] = '0';
			m->i++;
		}
	}
	m->res[m->i] = '\0';
	format_o8_third(m, in);
}

void	print_format_o8(t_params *m)
{
	unsigned long int	in;

	m->len = 0;
	m->i = 0;
	in = (m->in < 0 ? 4294967296 + m->unsigned_long_in : m->unsigned_long_in);
	m->number = m->unsigned_long_in;
	while (m->number != 0)
	{
		m->number /= 8;
		m->len++;
	}
	m->res = (char *)malloc(sizeof(char) * (100));
	if (in == 0 && m->f_check_value_precision != -1 &&
		m->f_check_value_precision != 0 && m->f_check_width)
		m->res[m->i++] = '0';
	while (in)
	{
		m->res[m->i] = in % 8 + 48;
		in /= 8;
		m->i++;
	}
	m->res[m->i] = '\0';
	format_o8_second(m, in);
}

void	format_o8(char *line, int i, va_list a)
{
	t_params	m;

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
