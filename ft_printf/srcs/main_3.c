/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:06:45 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/08 19:25:14 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_check_space(char *line, int i)
{
	while (line[i] != 'd' && line[i] != 'i' && line[i] != 'f' &&
			line[i] != 'u' && line[i] != 'D' && line[i] != 's' &&
			line[i] != 'e' && line[i] != 'E' && line[i] != 'F')
	{
		if (line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_zero(char *line, int i)
{
	while (ft_check_all_flags(line, i) && (line[i] < '1' || line[i] > '9'))
	{
		if (line[i] == '0' && line[i - 1] != '.' &&
				!ft_isdigit(line[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_octotorp(char *line, int i)
{
	while (line[i] != 'o' && line[i] != 'x' && line[i] != 'X' && line[i] != 'f')
	{
		if (line[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_plus(char *line, int i)
{
	while (line[i] != 'f' && line[i] != 'd' && line[i] != 'i')
	{
		if (line[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_short_int(char *line, int i)
{
	while (line[i] != 'd' && line[i] != 'i')
	{
		if (line[i] == 'h' && (line[i + 1] == 'd' || line[i + 1] == 'i' ||
					line[i + 1] == 'u'))
			return (1);
		if (line[i] == 'h' && line[i + 1] == 'h' && (line[i + 2] == 'd' ||
					line[i + 2] == 'i' || line[i + 2] == 'u'))
			return (2);
		i++;
	}
	return (0);
}
