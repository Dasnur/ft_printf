/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:49:23 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/14 18:49:16 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlonglong(long long int nb)
{
	char				a;
	long long int		b;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb < -9000000000000000000)
		{
			ft_putchar('9');
			nb = nb + 9000000000000000000;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putlonglong(nb / 10);
	b = nb % 10;
	a = '0' + b;
	ft_putchar(a);
}
