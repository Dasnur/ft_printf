/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:59:46 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/08 18:46:29 by acarlett         ###   ########.fr       */
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
		ft_putchar(c[i]);
		i--;
	}
	free(c);
}
