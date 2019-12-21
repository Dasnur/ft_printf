/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:49:23 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/15 19:29:01 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putnbr2(int nb)
{
	char	a;
	int		b;

	if (nb < 0)
	{
		ft_putchar2('-');
		if (nb < -2000000000)
		{
			ft_putchar2('2');
			nb = nb + 2000000000;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr2(nb / 10);
	b = nb % 10;
	a = '0' + b;
	ft_putchar2(a);
}
