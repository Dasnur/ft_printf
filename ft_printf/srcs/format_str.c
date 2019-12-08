/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:14:59 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/07 20:30:13 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putstr_with_colour(char *res, t_params *m)
{
	char	*rescolour;

	if (m->f_check_space && !m->f_check_minus && !m->f_check_plus)
		ft_putchar(' ');
	rescolour = (char *)malloc(sizeof(char) * 15);
	if (m->ff == 1)
		get_colour_line(rescolour, "\e[0;31m", "\e[0m", res);
	if (m->ff == 2)
		get_colour_line(rescolour, "\e[0;32m", "\e[0m", res);
	if (m->ff == 3)
		get_colour_line(rescolour, "\e[0;33m", "\e[0m", res);
	if (m->ff == 4)
		get_colour_line(rescolour, "\e[0;34m", "\e[0m", res);
	if (m->ff == 5)
		get_colour_line(rescolour, "\e[0;35m", "\e[0m", res);
	if (m->ff == 6)
		get_colour_line(rescolour, "\e[0;36m", "\e[0m", res);
	if (m->ff == 0)
		ft_putstr(res);
}

void	print_first_part(t_params *m, int diff)
{
	ft_putstr_with_colour(m->cha2, m);
	if ((diff = ALWAYS_POZITIVE(m->f_check_width) - ft_strlen(m->cha2) + 1) > 0)
	{
		while (--diff > 0)
			ft_putchar(' ');
	}
}

void	print_second_part(t_params *m, int diff)
{
	if ((diff = ALWAYS_POZITIVE(m->f_check_width) - ft_strlen(m->cha2) + 1) > 0)
	{
		while (--diff > 0)
		{
			if (!m->f_check_zero)
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
	}
	ft_putstr_with_colour(m->cha2, m);
}

void	print_format_str(t_params *m)
{
	char	*res;
	int		diff;

	if (m->f_check_value_precision > 0)
		m->cha2 = ft_strsub(m->cha2, 0, m->f_check_value_precision);
	if (m->f_check_value_precision == -1)
		m->cha2 = "\0";
	if (m->f_check_width == 0)
		m->f_check_width = ft_strlen(m->cha2);
	if (m->f_check_width != 0)
	{
		if (m->f_check_minus)
			print_first_part(m, diff);
		else
			print_second_part(m, diff);
	}
}

void	format_str(char *line, int i, va_list a)
{
	t_params	m;

	m.i = i;
	while (line[m.i] != 's')
		m.i++;
	m.colour = check_colour(line, ++m.i);
	take_all_params_2(line, i, &m, a);
}
