/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:17:30 by acarlett          #+#    #+#             */
/*   Updated: 2019/11/21 23:19:38 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_check_long_int(char *line, int i)
{
	while (line[i] != 'd' && line[i] != 'i')
	{
		if (line[i] == 'l' && (line[i + 1] == 'd' || line[i + 1] == 'i' ||
					line[i + 1] == 'u' || line[i + 1] == 'o' ||
					line[i + 1] == 'x' || line[i + 1] == 'X'))
			return (1);
		if (line[i] == 'l' && line[i + 1] == 'l' && (line[i + 2] == 'd' ||
					line[i + 2] == 'i' || line[i + 2] == 'u' ||
			line[i + 2] == 'o' || line[i + 2] == 'x' || line[i + 2] == 'X'))
			return (2);
		i++;
	}
	return (0);
}

int		ft_check_minus(char *line, int i)
{
	while (ft_check_all_flags(line, i))
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		ft_choose_flags(char *line, int i)
{
	while (ft_check_all_flags(line, i))
		i++;
	if (line[i] == 'c')
		return (1);
	if (line[i] == 's')
		return (2);
	if (line[i] == 'p')
		return (3);
	if (line[i] == 'd' || line[i] == 'i')
		return (4);
	if (line[i] == 'o')
		return (5);
	if (line[i] == 'u')
		return (6);
	if (line[i] == 'x')
		return (7);
	if (line[i] == 'X')
		return (8);
	if (line[i] == 'f')
		return (9);
	if (line[i] == '%')
		return (10);
	return (-1);
}

int		ft_crossroads(int i, va_list a, char *line)
{
	t_params m;

	m.type = ft_choose_flags(line, i);
	if (m.type == 1)
		format_c(line, i, a, m.type);
	if (m.type == 4 || m.type == 6)
		d_u(line, i, a, m);
	if (m.type == 2)
		format_str(line, i, a);
	if (m.type == 3)
		format_p(line, i, a);
	if (m.type == 5)
		format_o8(line, i, a);
	if (m.type == 7 || m.type == 8)
		format_x(line, i, a, m.type);
	if (m.type == 9)
		format_f(line, i, a);
	if (m.type == 10)
		format_c(line, i, a, m.type);
	return (0);
}

void	ft_printf(char *line, ...)
{
	int			i;
	va_list		a;

	i = 0;
	va_start(a, line);
	while (line[i])
	{
		if (line[i] == '%')
		{
			ft_crossroads(i + 1, a, line);
			i = count_flags(line, i + 1);
			if (line[i] == '\0')
				break;
			i++;
			continue ;
		}
		else if (line[i] == '%' && line[i + 1] == '%')
		{
			i++;
			ft_putchar('%');
		}
		else if (line[i] != '%')
			ft_putchar(line[i]);
		i++;
	}
	va_end(a);
}

// int main()
// {
// 	char a;
// 	printf("%p\n", &a);
// 	ft_printf("%p", &a);
// }