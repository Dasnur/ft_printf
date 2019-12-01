/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:28:55 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 23:20:15 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		number_counting_x(long long int nbr)
{
	int i;
	int tmp;

	tmp = nbr;
	i = 0;
	while (1)
	{
		nbr /= 16;
		i++;
		if (nbr == 0)
			break ;
	}
	return (i);
}

int		string_counter(char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	format_ox_fourth(t_params *m, int flag, char *resx, int in)
{
	if (m->f_check_width != 0)
	{
		if (m->f_check_minus)
		{
			ft_putstrrev(m->res, m, m->unsigned_long_in);
			m->f_check_width = (m->f_check_width - ft_strlen(m->res) + 1);
			while (--(m->f_check_width) > 0)
				ft_putchar(' ');
		}
		else
		{
			m->f_check_width = (m->f_check_width - ft_strlen(m->res) + 1);
			if (m->f_check_zero && m->f_check_value_precision == 0 &&
					m->f_check_octotorp && m->unsigned_long_in != 0 &&
					(m->f_check_width = m->f_check_width - 2))
				ft_putstr((flag == 8 ? "0X" : "0x"));
			while (--(m->f_check_width) > 0)
				ft_putchar((m->f_check_zero &&
						m->f_check_value_precision == 0 ? '0' : ' '));
			ft_putstrrev(m->res, m, m->unsigned_long_in);
		}
	}
	else
		ft_putstrrev(m->res, m, m->unsigned_long_in);
}

void	format_ox_third(t_params *m, int flag, char *resx, int in)
{
	if (m->f_check_value_precision > (int)ft_strlen(m->res))
	{
		m->f_check_value_precision =
			(m->f_check_value_precision - ft_strlen(m->res));
		while (--(m->f_check_value_precision) >= 0)
			m->res[m->i++] = '0';
		if (m->f_check_octotorp && m->unsigned_long_in != 0 &&
				(m->res[m->i++] = (flag == 8 ? 'X' : 'x')))
			m->res[m->i++] = '0';
	}
	m->res[m->i] = '\0';
	format_ox_fourth(m, flag, resx, in);
}

void	ox_s(t_params *m, int flag, char *resx, int in)
{
	if (m->unsigned_long_in == 0 && m->f_check_octotorp &&
			m->f_check_value_precision != -1)
		m->res[m->i++] = '0';
	if ((m->unsigned_long_in == 0 && !m->f_check_octotorp &&
		m->f_check_value_precision != -1) || (m->unsigned_long_in == 0 &&
		!m->f_check_octotorp && m->f_check_value_precision == 0))
		m->res[m->i++] = '0';
	if ((m->f_check_octotorp && m->unsigned_long_in != 0 &&
		m->f_check_value_precision <= (int)ft_strlen(m->res) &&
		m->f_check_zero == 0 && (m->res[m->i++] = (flag == 8 ? 'X' : 'x'))) ||
		(m->f_check_octotorp &&
		m->f_check_value_precision <= m->f_check_width &&
		m->f_check_value_precision < ft_strlen(m->res) &&
		m->f_check_value_precision != 0 &&
		(m->res[m->i++] = (flag == 8 ? 'X' : 'x'))))
		m->res[m->i++] = '0';
	format_ox_third(m, flag, resx, in);
}
