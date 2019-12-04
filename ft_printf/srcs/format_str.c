/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:14:59 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 22:59:52 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*get_colour_line(char *rescolour, char *begin, char *end, char *mid)
{
	rescolour = ft_strcat(rescolour, begin);
	rescolour = ft_strcat(rescolour, mid);
	rescolour = ft_strcat(rescolour, end);
	ft_putstr(rescolour);
}

void	ft_putstr_with_colour(char *res, t_params *m)
{
	char	*rescolour;

	rescolour = (char *)malloc(sizeof(char) * 15);
	if (m->ff == 1)
		get_colour_line(rescolour, "\e[0;31m", "\e[0m", res);
	if (m->ff == 2)
		get_colour_line(rescolour, "\e[0;32m", "\e[0m", res);
	if (m->ff == 3)
		get_colour_line(rescolour, "\e[0;33m", "\e[0m", res);
	if (m->ff == 4)
		get_colour_line(rescolour, "\e[0;34m", "\e[0m", res);
	if (m->ff == 5)
		get_colour_line(rescolour, "\e[0;35m", "\e[0m", res);
	if (m->ff == 6)
		get_colour_line(rescolour, "\e[0;36m", "\e[0m", res);
	if (m->ff == 0)
		ft_putstr(res);
}

void	print_first_part(t_params *m, int diff)
{
	ft_putstr_with_colour(m->cha2, m);
	if ((diff = ALWAYS_POZITIVE(m->f_check_width) - ft_strlen(m->cha2) + 1) > 0)
	{
		while (--diff > 0)
			ft_putchar(' ');
	}
}

void	print_second_part(t_params *m, int diff)
{
	if ((diff = ALWAYS_POZITIVE(m->f_check_width) - ft_strlen(m->cha2) + 1) > 0)
	{
		while (--diff > 0)
			ft_putchar(' ');
	}
	ft_putstr_with_colour(m->cha2, m);
}

void	print_format_str(t_params *m)
{
	char	*res;
	int		diff;

	if (m->f_check_value_precision > 0)
		m->cha2 = ft_strsub(m->cha2, 0, m->f_check_value_precision);
	if (m->f_check_value_precision == -1)
		m->cha2 = "\0";
	if (m->f_check_width == 0)
		m->f_check_width = ft_strlen(m->cha2);
	if (m->f_check_width != 0)
	{
		if (m->f_check_minus)
			print_first_part(m, diff);
		else
			print_second_part(m, diff);
	}
}

char	*check_colour(char *line, int i)
{
	char 	*res;
	int		k;

	k = 0;
	res = (char *)malloc(sizeof(char) * 10);
	while (ft_check_all_flags(line, i))
	{
		if (line[i++] == '{')
		{
			while (line[i] != '}')
			{
				res[k] = line[i];
				k++;
				i++;
			}
			i--;
		}
	}
	res[k] = '\0';
	return (res);
}

void	recognize_colour(char *res, t_params *m)
{
	if (ft_strcmp(res, "red") == 0)
		m->ff = 1;
	if (ft_strcmp(res, "green") == 0)
		m->ff = 2;
	if (ft_strcmp(res, "yellow") == 0)
		m->ff = 3;
	if (ft_strcmp(res, "blue") == 0)
		m->ff = 4;
	if (ft_strcmp(res, "magenta") == 0)
		m->ff = 5;
	if (ft_strcmp(res, "cyan") == 0)
		m->ff = 6;
}

void	format_str(char *line, int i, va_list a)
{
	t_params	m;

	m.i = i;
	while (line[m.i] != 's')
		m.i++;
	m.colour = check_colour(line, ++m.i);
	take_all_params(line, i, &m);
	recognize_colour(m.colour, &m);
	m.cha2 = va_arg(a, char*);
	if (m.cha2 == NULL)
		m.cha2 = "(null)";
	print_format_str(&m);
}
