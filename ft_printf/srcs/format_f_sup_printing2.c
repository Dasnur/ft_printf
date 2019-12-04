/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f_sup_printing2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:10:03 by atote             #+#    #+#             */
/*   Updated: 2019/12/04 18:00:20 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*get_left_space_for_la(char *res)
{
	char	*nres;
	int		i;
	int		len;
	int		k;

	k = 0;
	len = ft_strlen(res);
	i = 249;
	nres = (char *)malloc(sizeof(char) * 400);
	nres[250] = '\0';
	while (len >= 0)
	{
		nres[i] = res[len];
		i--;
		len--;
	}
	while (i >= 0)
	{
		nres[i] = '0';
		i--;
	}
	free(res);
	return (nres);
}

char	*sdvig(char *res, int k)
{
	char	*resn;
	int		i;
	int		tmp;

	tmp = k;
	i = 0;
	resn = (char *)malloc(sizeof(char) * 400);
	resn[399] = '\0';
	while (res[tmp])
	{
		resn[i] = res[tmp];
		i++;
		tmp++;
	}
	while (k > 0)
	{
		resn[i] = '0';
		i++;
		k--;
	}
	resn[i] = '\0';
	return (resn);
}

char	*long_arif(char *a, char *b, char sign)
{
	t_params	m;
	char		*res;

	m.j = 0;
	res = ft_strdup(a);
	m.i = 248;
	if (sign == '+')
	{
		while (m.i >= 0)
		{
			res[m.i] = (a[m.i] - 48) + (b[m.i] - 48) + 48;
			if (m.j != 0)
			{
				res[m.i] = res[m.i] + 1;
				m.j = 0;
			}
			if (res[m.i] > 57)
			{
				res[m.i] = res[m.i] - 10;
				m.j = 1;
			}
			m.i--;
		}
	}
	return (res);
}

char	*get_good_line_of_pre(char *res, t_params *m)
{
	char	*resnew;
	int		len;
	int		i;

	i = 0;
	len = 0;
	resnew = (char *)malloc(sizeof(char) * 144);
	resnew[145] = '\0';
	if (m->type == 9)
	{
		resnew[len] = '.';
		len++;
	}
	else
		m->f_check_width = m->f_check_width - 1;
	i = 128;
	while (len < 145)
	{
		if (res[i] == '0' || res[i] == '\0')
			resnew[len] = '0';
		resnew[len] = res[i];
		len++;
		i++;
	}
	return (resnew);
}

char	*get_allres(char **res11, t_params *m)
{
	int		i;
	char	*allres;

	allres = get_left_space_for_la(ft_itoa_dr(0));
	i = 0;
	while (i < 119)
	{
		res11[i] = sdvig(res11[i], 120 - i);
		i++;
	}
	i = 0;
	while (i < ft_strlen(m->manta))
	{
		if (m->manta[i] == '1')
			allres = long_arif(res11[i], allres, '+');
		i++;
	}
	return (allres = get_good_line_of_pre(allres, m));
}
