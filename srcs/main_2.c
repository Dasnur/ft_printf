/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:07:09 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/08 18:54:42 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_check_point(char *line, int i)
{
	while (ft_check_all_flags(line, i))
	{
		if (line[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	take_all_params(char *line, int i, t_params *m)
{
	m->f_check_octotorp = ft_check_octotorp(line, i);
	m->f_check_minus = ft_check_minus(line, i);
	m->f_check_plus = ft_check_plus(line, i);
	m->f_check_zero = ft_check_zero(line, i);
	m->f_check_space = ft_check_space(line, i);
	m->f_check_width = take_width(line, i);
	m->f_check_presicion = take_presicion(line, i);
	m->f_check_width = ALWAYS_POZITIVE(m->f_check_width);
	m->f_check_long_int = ft_check_long_int(line, i);
	m->f_check_short_int = ft_check_short_int(line, i);
	m->f_check_point = ft_check_point(line, i);
	m->f_check_value_precision = take_presicion(line, i);
	m->ff = 0;
}

int		ft_check_all_flags(char *line, int i)
{
	if (line[i] != 'c' && line[i] != 's' && line[i] != 'p' && line[i] != 'd' &&
		line[i] != 'i' && line[i] != 'o' && line[i] != 'u' && line[i] != 'x' &&
		line[i] != 'X' && line[i] != 'f' && line[i] != '%' && line[i] != '\0' &&
		line[i] != 'g' && line[i] != 'D' && line[i] != 'F' && line[i] != 'b' &&
		line[i] != 'e' && line[i] != 'E')
		return (1);
	return (0);
}

int		ft_atoi_easy(char *line)
{
	int number;

	number = 0;
	while (*line >= '0' && *line <= '9')
	{
		number *= 10;
		number = number + (*line - '0');
		line++;
	}
	return (number);
}

int		take_presicion(char *line, int i)
{
	char	*t;
	int		f;
	int		number;

	number = 0;
	f = 0;
	while (ft_check_all_flags(line, i))
	{
		if (line[i] == '.')
		{
			t = &line[i + 1];
			f = 1;
			number = 0;
			number = ft_atoi_easy(t);
			i = i + number_counting(number);
			i = i + (number_counting(number) == 0 ? 1 : 0);
		}
		else
			i++;
	}
	if (f && !number)
		return (-1);
	return (number);
}
