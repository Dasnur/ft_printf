/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f_sup_printing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:26 by atote             #+#    #+#             */
/*   Updated: 2019/12/04 18:04:00 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		number_counting_in(int in)
{
	int	i;

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

int		poryadok(int len)
{
	int	res;

	res = 1;
	while (len > 1)
	{
		res = res * 10;
		len--;
	}
	return (res);
}

char	*ft_itoa_dr(int a)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	res = (char *)malloc(sizeof(char) * number_counting_in(a) + 1);
	len = number_counting_in(a);
	while (len != 0)
	{
		res[i] = a / poryadok(len) + 48;
		i++;
		a = a % poryadok(len);
		len--;
	}
	res[i] = '\0';
	return (res);
}

void	perenos_okruglenie(char *res, t_params *m, int *k)
{
	if (res[*k + 1] > 52)
	{
		if (res[*k] != '9')
			res[*k] = res[*k] + 1;
		else
		{
			res[(*k)--] = '0';
			while (res[*k] == '9')
			{
				res[*k] = '0';
				*k = *k - 1;
			}
			if (res[*k] != '.')
				res[*k] = res[*k] + 1;
			else
			{
				if (m->long_long_in < 0)
					m->long_long_in = m->long_long_in - 1;
				else
					m->long_long_in = m->long_long_in + 1;
			}
		}
	}
}

char	*okruglenie(char *res, int i, t_params *m)
{
	int	k;
	int	flag;

	flag = 0;
	k = 0;
	while (--i >= -1)
		k++;
	k--;
	if (k == -1)
	{
		k = k + 1;
		if (res[k + 1] > 52)
		{
			if (m->long_long_in < 0)
				m->long_long_in = m->long_long_in - 1;
			else
				m->long_long_in = m->long_long_in + 1;
		}
	}
	perenos_okruglenie(res, m, &k);
	return (res);
}
