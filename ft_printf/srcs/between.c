/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 22:38:30 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/08 18:45:28 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	between_p(char *line, int i, va_list a, t_params *m)
{
	m->poin = va_arg(a, void *);
	print_format_p(m);
}

void	between_c(t_params *m, int flag, va_list a)
{
	if (flag == 10)
		m->cha = '%';
	else
		m->cha = va_arg(a, int);
	print_format_c(m);
}

void	between_s(char *line, int i, va_list a, t_params *m)
{
	recognize_colour(m->colour, m);
	m->cha2 = va_arg(a, char*);
	if (m->cha2 == NULL)
		m->cha2 = "(null)";
	print_format_str(m);
}

void	between_d(t_params *m, char *line, int i, va_list a)
{
	if (!m->f_check_long_int && !m->f_check_short_int && m->type == 4)
		to_d(line, i, *m, a);
	else if (m->f_check_long_int == 1 && m->type == 4)
		to_ld(line, i, *m, a);
	else if (m->f_check_long_int == 2 && m->type == 4)
		to_lld(line, i, *m, a);
	else if (m->f_check_short_int == 1 && m->type == 4)
		to_hd(line, i, *m, a);
	else if (m->f_check_short_int == 2 && m->type == 4)
		to_hhd(line, i, *m, a);
	else if (m->type == 6 && !m->f_check_long_int && !m->f_check_short_int)
		to_u(line, i, *m, a);
	else if (m->f_check_long_int == 1 && m->type == 6)
		to_lu(line, i, *m, a);
	else if (m->f_check_long_int == 2 && m->type == 6)
		to_llu(line, i, *m, a);
	else if (m->f_check_short_int == 1 && m->type == 6)
		to_hu(line, i, *m, a);
	else if (m->f_check_short_int == 2 && m->type == 6)
		to_hhu(line, i, *m, a);
}

void	between(char *line, int i, t_params *m, va_list a)
{
	m->type = ft_choose_flags(line, i);
	if (m->type == 1 || m->type == 10)
		between_c(m, m->type, a);
	else if (m->type == 4 || m->type == 6)
		between_d(m, line, i, a);
	else if (m->type == 2)
		between_s(line, i, a, m);
	else if (m->type == 3)
		between_p(line, i, a, m);
}
