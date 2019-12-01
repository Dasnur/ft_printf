/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_u_convert_tounsigned.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:22:26 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 23:15:42 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	to_u(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = va_arg(a, unsigned int);
	m.f_otricatelnoe = NALICIE_MINUSA(m.unsigned_long_long_in);
	m.isnull = ISNULL(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			write(1, "+", 1);
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_lu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (long int)va_arg(a, long);
	m.f_otricatelnoe = NALICIE_MINUSA(m.unsigned_long_long_in);
	m.isnull = ISNULL(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			write(1, "+", 1);
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_llu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (unsigned long long)va_arg(a, unsigned long long);
	m.f_otricatelnoe = NALICIE_MINUSA(m.unsigned_long_long_in);
	m.isnull = ISNULL(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			write(1, "+", 1);
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_hu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (short unsigned int)va_arg(a, unsigned int);
	m.f_otricatelnoe = NALICIE_MINUSA(m.unsigned_long_long_in);
	m.isnull = ISNULL(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
	{
		if (m.f_check_plus)
			write(1, "+", 1);
		return ;
	}
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}

void	to_hhu(char *line, int i, t_params m, va_list a)
{
	m.unsigned_long_long_in = (unsigned char)va_arg(a, unsigned int);
	m.f_otricatelnoe = NALICIE_MINUSA(m.unsigned_long_long_in);
	m.isnull = ISNULL(m.unsigned_long_long_in);
	if (!m.isnull && m.f_check_presicion == -1 && !m.f_check_width)
		return ;
	print_format_d(&m, number_counting(m.unsigned_long_long_in));
}
