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

void	minus_value_x(char *res)
{
	int		i;

	i = 8;
	while (i <= 15)
	{
		if (res[i] == 'f' || res[i] == 'F')
			i++;
		else
			break ;
	}
	if (i == 16)
		res[8] = '\0';
}

void	print_format_ox(t_params *m, char *line, int flag)
{
	char						*resx;
	unsigned long long int		in;
	int							limit;

	m->i = 0;
	resx = "0123456789abcdef0123456789ABCDEF";
	if (!(m->res = malloc(sizeof(char) * (100))))
		return ;
	in = m->long_long_in;
	//printf("%llu\n", in);
	while (in)
	{
		if (flag == 8)
			m->res[m->i] = resx[(in) % 16 + 16];
		else
			m->res[m->i] = resx[(in) % 16];
		m->i++;
		in /= 16;
	}
	m->res[m->i] = '\0';
	//printf("%s\n", m->res);
	if (m->f_check_j != 1)
		minus_value_x(m->res);
	ox_s(m, flag, resx, in);
}

void	format_x(char *line, int i, va_list a, int flag)
{
	t_params m;

	take_all_params(line, i, &m);
	m.f_check_j = ft_check_j(line, i);
	if (m.f_check_long_int)
		m.long_long_in = va_arg(a, long int);
	else if (m.f_check_short_int == 2)
	{
		m.unsigned_char = va_arg(a, int);
		m.long_long_in = m.unsigned_char;
	}
	else if (m.f_check_j)
		m.long_long_in = va_arg(a, long long int);
	else
	{
		m.in = va_arg(a, int);
		m.long_long_in = m.in;
	}
	print_format_ox(&m, line, flag);
}
