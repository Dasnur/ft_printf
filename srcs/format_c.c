/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:43:24 by atote             #+#    #+#             */
/*   Updated: 2019/12/15 19:07:08 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_atoi_sharp(const char *nptr)
{
	long long int			res;
	int						i;

	i = 0;
	res = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ' || nptr[i] == '#' ||
	nptr[i] == '-' || nptr[i] == '+' || nptr[i] == '.')
		i++;
	while ((nptr[i] > 47) && (nptr[i] < 58))
	{
		res = res * 10 + (nptr[i++] - '0');
		if (res > 214748364700)
			return (-1);
		if (res > 214748364800)
			return (0);
	}
	return (res);
}

void	print_format_c(t_params *m)
{
	if (m->f_check_width == 0)
		ft_putchar2(m->cha);
	else
	{
		if (m->f_check_minus == 1)
		{
			ft_putchar2(m->cha);
			while (--(m->f_check_width) > 0)
				ft_putchar2(' ');
		}
		else
		{
			while (--(m->f_check_width) > 0)
			{
				if (m->f_check_zero == 0)
					ft_putchar2(' ');
				else
					ft_putchar2('0');
			}
			ft_putchar2(m->cha);
		}
	}
}

void	format_c(char *line, int i, va_list a, int flag)
{
	t_params m;

	take_all_params_2(line, i, &m, a);
}
