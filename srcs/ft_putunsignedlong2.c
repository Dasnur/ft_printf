/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedlong2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:49:23 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/15 19:29:12 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_check_j(char *line, int i)
{
	while (line[i] != 'x')
	{
		if (line[i] == 'j')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putunsignedlong2(unsigned long long int nb)
{
	char						a;
	unsigned long long int		b;

	if (nb >= 10)
		ft_putunsignedlong2(nb / 10);
	b = nb % 10;
	a = '0' + b;
	ft_putchar2(a);
}
