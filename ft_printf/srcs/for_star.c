/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_star.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 22:39:38 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/08 18:46:46 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	cont(char *line, int i, t_params *m, va_list a)
{
	if (m->f && !m->f_check_presicion)
		m->f_check_presicion = -1;
	between(line, m->j, m, a);
}

void	take_width_2_1(char *line, int i, t_params *m, va_list a)
{
	while (ft_check_all_flags(line, i))
	{
		if (line[i] >= '0' && line[i] <= '9' && !ft_isdigit(line[i - 1]) &&
				line[i - 1] != '.')
		{
			m->f_check_width = ft_atoi_easy(&line[i]);
			i = i + number_counting(m->f_check_width);
			i = i + (number_counting(m->f_check_width) == 0 ? 1 : 0);
			continue;
		}
		else if (line[i] == '.' && line[i + 1] != '*')
		{
			m->f = 1;
			m->f_check_presicion = ft_atoi_easy(&line[i + 1]);
			i = i + number_counting(m->f_check_presicion);
			i = i + (number_counting(m->f_check_presicion) == 0 ? 1 : 0);
			continue;
		}
		else if (line[i] == '*' && line[i - 1] != '.')
			m->f_check_width = va_arg(a, int);
		else if (line[i] == '*' && line[i - 1] == '.')
			m->f_check_presicion = va_arg(a, int);
		i++;
	}
	cont(line, i, m, a);
}

void	take_width_2(char *line, int i, t_params *m, va_list a)
{
	m->f_check_presicion = 0;
	m->f_check_width = 0;
	m->j = i;
	m->f = 0;
	take_width_2_1(line, i, m, a);
}

void	take_all_params_2(char *line, int i, t_params *m, va_list a)
{
	m->f_check_octotorp = ft_check_octotorp(line, i);
	m->f_check_minus = ft_check_minus(line, i);
	m->f_check_plus = ft_check_plus(line, i);
	m->f_check_zero = ft_check_zero(line, i);
	m->f_check_space = ft_check_space(line, i);
	m->f_check_width = ALWAYS_POZITIVE(m->f_check_width);
	m->f_check_long_int = ft_check_long_int(line, i);
	m->f_check_short_int = ft_check_short_int(line, i);
	m->f_check_point = ft_check_point(line, i);
	m->f_check_value_precision = take_presicion(line, i);
	m->ff = 0;
	take_width_2(line, i, m, a);
}
