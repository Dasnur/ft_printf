/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:14:33 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/07 19:44:11 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		take_width(char *line, int i)
{
	int		number;

	number = 0;
	while (ft_check_all_flags(line, i))
	{
		if (line[i] >= '0' && line[i] <= '9' && !ft_isdigit(line[i - 1]) &&
				line[i - 1] != '.')
		{
			number = ft_atoi_easy(&line[i]);
			i = i + number_counting(number);
			i = i + (number_counting(number) == 0 ? 1 : 0);
		}
		else
			i++;
	}
	return (number);
}

int		count_flags(char *line, int i)
{
	while (ft_check_all_flags(line, i))
		i++;
	if (line[i + 1] == '{')
	{
		while (line[i] != '}')
			i++;
	}
	return (i);
}

int		ft_check_long_f(char *line, int i)
{
	while (line[i] != 'f')
	{
		if (line[i] == 'L' && (line[i + 1] == 'f'))
			return (1);
		i++;
	}
	return (0);
}
