/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:14:59 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/14 17:46:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
		{
			ft_putstr(m->cha2);
			if ((diff = Always_pozitive(m->f_check_width) - ft_strlen(m->cha2) + 1) > 0)
			{
				while (--diff > 0)
					ft_putchar(' ');
			}
		}
		else
		{
			if ((diff = Always_pozitive(m->f_check_width) - ft_strlen(m->cha2) + 1) > 0)
			{
				while (--diff > 0)
					ft_putchar(' ');
			}
			ft_putstr(m->cha2);
		}
	}
}

void	format_str(char *line, int i, va_list a)
{
	t_params	m;

	take_all_params(line, i, &m);
	//printf("%d", m.f_check_value_precision);
	m.cha2 = va_arg(a, char*);
	if (m.cha2 == NULL)
		m.cha2 = "(null)";
	print_format_str(&m);
}