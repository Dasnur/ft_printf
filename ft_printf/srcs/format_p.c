/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:17:37 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/07 20:35:06 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	format_p_firsthelp(t_params *m, char *res)
{
	m->f_check_width = (m->f_check_width - (ft_strlen(&res[0]) + 2));
	while (--(m->f_check_width) >= 0)
		ft_putchar(' ');
	ft_putstr("0x");
	while (m->i >= 0)
	{
		ft_putchar(res[m->i]);
		m->i--;
	}
}

void	format_p_secondhelp(t_params *m, char *res)
{
	ft_putstr("0x");
	while (m->i >= 0)
	{
		ft_putchar(res[m->i]);
		m->i--;
	}
	m->f_check_width = (m->f_check_width - (ft_strlen(&res[0]) + 2));
	while (--(m->f_check_width) >= 0)
		ft_putchar(' ');
}

void	print_format_p_second(t_params *m, char *res)
{
	if (m->f_check_width != 0)
	{
		if (!(m->f_check_minus))
			format_p_firsthelp(m, res);
		else
			format_p_secondhelp(m, res);
	}
	else
	{
		ft_putstr("0x");
		while (m->i >= 0)
		{
			ft_putchar(res[m->i]);
			m->i--;
		}
	}
}

void	print_format_p(t_params *m)
{
	char	hex[16];
	char	res[sizeof(m->p) + 3];

	init_16_mas(&(hex[0]));
	m->p = (long long int)m->poin;
	m->i = 0;
	while (m->i <= (sizeof(m->p) + 3))
	{
		res[m->i] = hex[m->p % 16];
		m->p = m->p / 16;
		m->i++;
	}
	res[m->i--] = '\0';
	if (res[m->i] == '0')
	{
		res[m->i - 2] = '\0';
		m->i = m->i - 3;
	}
	if (m->poin == NULL)
	{
		res[1] = '\0';
		m->i = 0;
	}
	const_p(m, &res[0]);
	print_format_p_second(m, res);
}

void	format_p(char *line, int i, va_list a)
{
	t_params	m;

	take_all_params_2(line, i, &m, a);
}
