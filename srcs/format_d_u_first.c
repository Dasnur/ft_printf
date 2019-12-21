/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d_u_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:24:40 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/15 19:59:57 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		number_counting(size_t in)
{
	int i;

	i = 0;
	if (in == 0)
		return (1);
	while (in != 0)
	{
		in /= 10;
		i++;
	}
	return (i);
}

int		ft_isnull(t_params *m, int number)
{
	if (!m->isnull && m->f_check_presicion == -1)
	{
		while (--number >= 0)
			ft_putchar2(' ');
		return (1);
	}
	return (0);
}

void	choose_int(t_params *m, int number)
{
	if (ft_isnull(m, number))
		return ;
	ft_putlonglong2(m->long_long_in);
}

void	choose_unsigned(t_params *m, int number)
{
	if (ft_isnull(m, number))
		return ;
	ft_putunsignedlong2(m->unsigned_long_long_in);
}

void	choose_char(t_params *m, int number)
{
	if (ft_isnull(m, number))
		return ;
	ft_putstr2(m->cha2);
}
