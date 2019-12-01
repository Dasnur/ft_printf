/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_u_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:26:26 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 23:21:05 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_put_choose(t_params *m)
{
	int number;

	number = number_counting(m->long_long_in);
	if (m->ff)
		m->long_long_in = ALWAYS_POZITIVE(m->long_long_in);
	if (m->type == 4)
		choose_int(m, number);
	if (m->type == 6)
		choose_unsigned(m, number);
	if (m->type == 7 || m->type == 8)
		choose_char(m, number);
}

void	print_only_d_u(t_params *m)
{
	if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar('+');
	if ((m->type == 4 || m->type == 6) && m->f_otricatelnoe)
	{
		m->ff = 1;
		ft_putchar('-');
	}
	else if (m->f_check_space && !m->f_check_plus && !m->f_otricatelnoe)
		ft_putchar(' ');
	ft_put_choose(m);
}

void	print_p_more(t_params *m, int size_number, int i)
{
	if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar('+');
	else if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
	{
		ft_putchar('-');
		m->ff = 1;
	}
	else if (m->f_check_space)
	{
		ft_putchar(' ');
		m->f_check_width--;
	}
	while ((m->f_check_presicion - size_number) != i)
	{
		ft_putchar('0');
		i++;
	}
	ft_put_choose(m);
}

void	print_width_1(t_params *m, int size_number, int i)
{
	if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar('+');
	else if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
	{
		ft_putchar('-');
		m->ff = 1;
	}
	else if (m->f_check_space)
	{
		ft_putchar(' ');
		m->f_check_width--;
	}
	while (m->f_check_presicion > size_number)
	{
		size_number++;
		ft_putchar('0');
	}
	ft_put_choose(m);
	while (m->f_check_width != ((m->f_check_plus || m->f_otricatelnoe) +
				BIGGEST(size_number, m->f_check_presicion)))
	{
		ft_putchar(' ');
		m->f_check_width--;
	}
}

void	print_width_2(t_params *m, int size_number)
{
	if (m->f_check_plus && !m->f_otricatelnoe && (m->type == 4 || m->type == 6))
		ft_putchar('+');
	else if (m->f_otricatelnoe && (m->type == 4 || m->type == 6))
	{
		ft_putchar('-');
		m->ff = 1;
		m->f_check_width--;
	}
	else if (m->f_check_space)
	{
		ft_putchar(' ');
		m->f_check_width--;
	}
	while (m->f_check_width > (m->f_check_plus + size_number))
	{
		ft_putchar('0');
		m->f_check_width--;
	}
	ft_put_choose(m);
}
