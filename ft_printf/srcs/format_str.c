/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:14:59 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 22:59:52 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_first_part(t_params *m, int diff)
{
	ft_putstr(m->cha2);
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
			ft_putchar(' ');
	}
	ft_putstr(m->cha2);
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

	take_all_params(line, i, &m);
	m.cha2 = va_arg(a, char*);
	if (m.cha2 == NULL)
		m.cha2 = "(null)";
	print_format_str(&m);
}
