/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:42:02 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/07 20:35:29 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	print_width_more_3(t_params *m, int size_number)
{
	while (m->f_check_width != ((m->f_otricatelnoe || m->f_check_plus) +
				BIGGEST(size_number, m->f_check_presicion)))
	{
		ft_putchar(' ');
		m->f_check_width--;
	}
	if ((m->f_check_presicion > 0) && m->f_check_plus &&
			!m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar('+');
	if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
	{
		ft_putchar('-');
		m->ff = 1;
	}
	while (m->f_check_presicion > size_number)
	{
		ft_putchar('0');
		m->f_check_presicion--;
	}
	ft_put_choose(m);
	if (!m->isnull && (!m->f_check_presicion || m->f_check_presicion == -1) &&
			m->f_check_plus)
		ft_putchar('+');
}

void	print_width_more_4(t_params *m, int size_number)
{
	while (m->f_check_width > (size_number + m->f_check_plus +
				m->f_otricatelnoe))
	{
		ft_putchar(' ');
		m->f_check_width--;
	}
	if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar('+');
	ft_put_choose(m);
}

void	print_format_d(t_params *m, int size_number)
{
	int i;

	i = 0;
	if (m->f_check_width <= (size_number + m->f_check_plus) &&
			m->f_check_presicion <= (m->f_check_plus + size_number))
		print_only_d_u(m);
	else if (m->f_check_presicion > m->f_check_width)
		print_p_more(m, size_number, i);
	else if (m->f_check_width >= m->f_check_presicion)
	{
		if (m->f_check_minus)
			print_width_1(m, size_number, i);
		else if (m->f_check_zero && !m->f_check_presicion)
			print_width_2(m, size_number);
		else if (m->f_check_presicion)
			print_width_more_3(m, size_number);
		else
			print_width_more_4(m, size_number);
	}
}

void	d_u(char *line, int i, va_list a, t_params m)
{
	take_all_params_2(line, i, &m, a);
}
