/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:08:41 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/04 18:32:28 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_format_ox(t_params *m, char *line, int flag)
{
	char				*resx;
	unsigned long int	in;
	int					limit;

	m->i = 0;
	resx = "0123456789abcdef0123456789ABCDEF";
	if (!(m->res = malloc(sizeof(char) * (100))))
		return ;
	in = m->unsigned_long_in;
	while (in)
	{
		if (flag == 8)
			m->res[m->i] = resx[in % 16 + 16];
		else
			m->res[m->i] = resx[in % 16];
		m->i++;
		in /= 16;
	}
	m->res[m->i] = '\0';
	ox_s(m, flag, resx, in);
}

void	format_x(char *line, int i, va_list a, int flag)
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
	print_format_ox(&m, line, flag);
}
