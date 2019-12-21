/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:59:46 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/15 19:33:49 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void		to_binary(t_params *m, va_list a)
{
	int		b;
	char	*c;
	int		i;

	b = 0;
	i = 0;
	if (!(c = malloc(sizeof(char*) * 120)))
		return ;
	m->long_long_in = va_arg(a, long int);
	while (m->long_long_in)
	{
		b = m->long_long_in % 2;
		c[i] = b + '0';
		i++;
		m->long_long_in /= 2;
	}
	while (i >= 0)
	{
		ft_putchar2(c[i]);
		i--;
	}
	free(c);
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
