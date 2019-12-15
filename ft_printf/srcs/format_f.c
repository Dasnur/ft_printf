/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:54:21 by atote             #+#    #+#             */
/*   Updated: 2019/12/13 19:25:17 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*stepen_of_5(char *res11, char *preres)
{
	res11 = ft_strdup(preres);
	res11 = long_arif(res11, preres, '+');
	res11 = long_arif(res11, preres, '+');
	res11 = long_arif(res11, preres, '+');
	res11 = long_arif(res11, preres, '+');
	return (res11);
}

char	**map_of_stepen(t_params *m)
{
	int		y;
	char	**res11;

	y = 0;
	res11 = (char **)malloc(sizeof(char *) * 120);
	res11[119] = 0;
	while (y < 119)
	{
		if (y == 0)
		{
			res11[y] = ft_itoa_dr(5);
			res11[y] = get_left_space_for_la(res11[y], m);
		}
		else if (y != 0)
			res11[y] = stepen_of_5(res11[y], res11[y - 1]);
		y++;
	}
	return (res11);
}

int		predel_f(t_params *m)
{
	if (m->doubl == -1.0 / 0.0)
	{
		m->cha2 = "-inf";
		m->f_check_zero = 0;
		m->f_check_space = 0;
		return (1);
	}
	if (m->doubl == 1.0 / 0.0)
	{
		m->cha2 = "inf";
		if (m->f_check_plus)
			m->cha2 = "+inf";
		m->f_check_zero = 0;
		return (1);
	}
	if (m->doubl != m->doubl)
	{
		m->cha2 = "nan";
		m->f_check_zero = 0;
		m->f_check_space = 0;
		return (1);
	}
	return (0);
}

int		predel_f1(t_params *m)
{
	if (predel_f(m))
	{
		print_format_str(m);
		return (1);
	}
	if (1.0 / m->doubl == -1.0 / 0.0)
	{
		if (m->f_check_width != 0)
		{
			ft_putchar('-');
			m->f_check_width--;
		}
		m->f_check_minus = 1;
	}
	return (0);
}

void	free_map(char **res11, int index)
{
	while (index >= 0)
	{
		free(res11[index]);
		index--;
	}
}

long double	zero_part(t_params *m, long double doubl1)
{
	doubl1 = m->doubl;
	if (m->long_long_in == 0 && m->doubl > 0)
		return (doubl1 + 1);
	if (m->long_long_in == 0 && m->doubl < 0)
		return (doubl1 - 1);
	return (doubl1);
}

void	format_f(char *line, int i, va_list a, int type)
{
	t_params		m;
	long double		doubl1;
	char			**res11;

	m.type = type;
	take_all_params(line, i, &m);
	if (m.f_check_value_precision == 0)
		m.f_check_value_precision = 6;
	if (!ft_check_long_f(line, i))
		m.doubl = va_arg(a, double);
	else
		m.doubl = va_arg(a, long double);
	m.long_long_in = m.doubl;
	if (predel_f1(&m))
		return ;
	doubl1 = zero_part(&m, doubl1);
	m.res = get_only_mant(bit_fourth(doubl1, 1), 1, 1);
	vibor_mantiss(doubl1, &m);
	if (m.res)
		free(m.res);
	res11 = map_of_stepen(&m);
	print_format_f(&m, get_allres(res11, &m));
	free_map(res11, 119);
	free(res11);
	if (m.manta && m.manta[0] && ft_strcmp(m.manta,
	"11111111111111111111111111111111111111111111111111111") != 0)
		free(m.manta);
}
