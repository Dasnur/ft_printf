/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:28:53 by atote             #+#    #+#             */
/*   Updated: 2019/12/08 17:28:55 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	get_colour_line(char *rescolour, char *begin, char *end, char *mid)
{
	rescolour = ft_strcat(rescolour, begin);
	rescolour = ft_strcat(rescolour, mid);
	rescolour = ft_strcat(rescolour, end);
	ft_putstr(rescolour);
}

char	*check_colour(char *line, int i)
{
	char	*res;
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
