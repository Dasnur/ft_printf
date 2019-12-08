/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f_mantiss.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:06:14 by atote             #+#    #+#             */
/*   Updated: 2019/12/04 17:52:34 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	first_manta_for_null(char *manta1, char *manta, t_params *m, int flag)
{
	while (m->ff < 8 && manta1[m->i] != '\0' && flag)
	{
		m->res[m->i] = manta1[m->i];
		m->i++;
		m->ff++;
	}
	while (manta[m->ff] != '\0')
	{
		if (manta[m->ff] >= '0' && manta[m->ff] <= '9')
		{
			m->res[m->i] = manta[m->ff];
			if (m->res[m->i] == '1')
				m->type++;
			m->i++;
		}
		m->ff++;
	}
	while (m->res[m->i - 1] == '0')
	{
		m->res[m->i - 1] = '\0';
		m->i--;
	}
	m->res[m->i] = '\0';
}

int		kratnie5_manta_for_null(char *manta, t_params *m)
{
	while (m->i >= 0)
	{
		if (manta[m->i] == '1')
		{
			m->type = m->i;
			break ;
		}
		m->i--;
	}
	m->i = 0;
	if (m->type < 12)
	{
		while (m->i <= m->type)
			m->res[m->i++] = manta[m->i];
		if (m->res[m->i - 1] == '1' &&
				m->res[m->i - 2] == '0' && m->res[m->i - 3] == '0')
		{
			m->res[m->i - 2] = '1';
			m->i--;
		}
		m->res[m->i] = '\0';
		return (1);
	}
	return (0);
}

void	second_manta_for_null(char *manta1, int flag, t_params *m)
{
	m->type = 0;
	while (manta1[m->i] == '0')
	{
		m->res[m->i] = manta1[m->i];
		m->i++;
	}
	if (m->i == 52)
		m->res[m->i++] = '0';
	while (m->ff < 8 && manta1[m->i] != '\0' && m->i < 49 && !flag)
	{
		m->res[m->i] = manta1[m->i];
		m->i++;
		m->ff++;
	}
}

char	*manta_for_null(char *manta, char *manta1, int flag)
{
	t_params	m;

	m.type = 14;
	m.ff = 0;
	m.res = (char *)malloc(sizeof(char) * 150);
	m.i = 55;
	if (kratnie5_manta_for_null(manta, &m))
		return (m.res);
	second_manta_for_null(manta1, flag, &m);
	first_manta_for_null(manta1, manta, &m, flag);
	free(manta);
	free(manta1);
	if (m.type == 52)
		return ("11111111111111111111111111111111111111111111111111111");
	else
		return (m.res);
}

void	vibor_mantiss(long double doubl1, t_params *m)
{
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	if (doubl1 != m->doubl)
	{
		while (i < 50)
		{
			if (m->res[i] == '1')
				flag = 0;
			i++;
		}
		if (flag)
			m->manta = manta_for_null(bit_double(m->doubl,
						m->long_long_in), m->res, flag);
		else
			m->manta = manta_for_null(bit_double(m->doubl,
						m->long_long_in), bit_double(doubl1, 1), flag);
	}
	else
		m->manta = bit_double(m->doubl, m->long_long_in);
}
