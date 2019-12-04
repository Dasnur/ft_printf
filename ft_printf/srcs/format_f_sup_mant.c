/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f_sup_mant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:14:55 by atote             #+#    #+#             */
/*   Updated: 2019/12/04 16:30:04 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*mant_to_byte(long long int mant)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * 25);
	i = 0;
	while (mant != 0)
	{
		res[i] = (mant % 2) + 48;
		mant = mant / 2;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_only_mant(char *res, long long int in, int flag)
{
	char	*mant;
	int		i;
	int		k;

	mant = (char *)malloc(sizeof(char) * 69);
	mant[53] = '\0';
	if (in == 0 && flag == 0 && res[54] == '1')
	{
		k = 52;
		mant[53] = '\0';
	}
	else
		k = 52 - ft_strlen(mant_to_byte(in));
	i = 0;
	if (res[57] == '0' && flag == 0 && in == 0 && res[58] == '0')
		k = 51;
	if (flag == 1)
		k = 63;
	if (flag == 2)
		k = 53;
	while (k >= 0)
		mant[i++] = res[k--];
	mant[i] = '\0';
	return (mant);
}

char	*div_bit_double(t_params *m, char *result,
		unsigned char tmp, unsigned char *gg)
{
	result[65] = '\0';
	while (m->i < 8)
	{
		tmp = *gg;
		m->j = 0;
		while (m->j < 8)
		{
			result[m->type] = (tmp & 1) + 48;
			if (result[m->type] == '0')
				m->number++;
			tmp >>= 1;
			m->j++;
			m->type++;
		}
		m->i++;
		gg++;
	}
	return (result);
}

char	*bit_double(double res, long long int in)
{
	char			*result;
	unsigned char	*gg;
	unsigned char	tmp;
	t_params		m;

	gg = (unsigned char *)&res;
	m.number = 0;
	result = (char *)malloc(sizeof(char) * 150);
	m.type = 0;
	m.i = 0;
	m.j = 0;
	result = div_bit_double(&m, result, tmp, gg);
	if (m.number > 45 && in == 0 && m.number < 57 && result[54] == '1')
		return (get_only_mant(result, in, 2));
	return (get_only_mant(result, in, 0));
}

char	*bit_fourth(long double res, long long int in)
{
	char			*result;
	unsigned char	*gg;
	unsigned char	tmp;
	t_params		m;

	gg = (unsigned char *)&res;
	result = (char *)malloc(sizeof(char) * 150);
	result[129] = '\0';
	m.number = 0;
	m.i = 0;
	m.j = 0;
	while (m.i < 8)
	{
		tmp = *gg++;
		m.j = 0;
		while (m.j < 16)
		{
			if (m.i < 7)
				result[m.number++] = (tmp & 1) + 48;
			tmp >>= 1;
			m.j++;
		}
		m.i++;
	}
	return (result);
}
