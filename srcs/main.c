/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:17:30 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/15 20:14:32 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <limits.h>

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
			line[i + 2] == 'o' || line[i + 2] == 'x' || line[i + 2] == 'X' || line[i + 3] == 'x'))
			return (2);
		i++;
	}
	return (0);
}

int		ft_choose_flags_help(char *line, int i)
{
	if (line[i] == 'g')
		return (92);
	if (line[i] == 'e')
		return (91);
	if (line[i] == 'E')
		return (911);
	if (line[i] == 'b')
		return (12);
	return (-1);
}

int		ft_check_vl(char c)
{
	if (c == 'Z')
		return (1);
	return (0);
}

int		ft_choose_flags(char *line, int i)
{
	while (ft_check_all_flags(line, i))
	{
		if (ft_check_vl(line[i]))
			return (0);
		if (line[i] != '%')
			i++;
	}
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
	if (line[i] == 'u' || line[i] == 'D')
		return (6);
	if (line[i] == 'x')
		return (7);
	if (line[i] == 'X')
		return (8);
	if (line[i] == 'f' || line[i] == 'F')
		return (9);
	if (line[i] == '%')
		return (10);
	return (ft_choose_flags_help(line, i));
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
	if (m.type == 9 || m.type == 91 || m.type == 911 || m.type == 92)
		format_f(line, i, a, m.type);
	if (m.type == 10)
		format_c(line, i, a, m.type);
	if (m.type == 12)
		to_binary(&m, a);
	return (0);
}

int		ft_printf(char *line, ...)
{
	int			i;
	va_list		a;

	i = 0;
	g_count = 0;
	va_start(a, line);
	while (line[i])
	{
		if (line[i] == '%')
		{
			ft_crossroads(i + 1, a, line);
			i = count_flags(line, i + 1);
			if (line[i - 1] == '%' && line[i] == '%' && !ft_check_all_flags(line, i + 1))
			{
				i++;
				continue ;
			}
			if (line[i + 1] == '\0')
				break ;
			if (line[i] == '%' && !ft_check_all_flags(line, i + 1))
				i--;
			i++;
			continue ;
		}
		else if (line[i] == '%' && line[i + 1] == '%' && (i++))
			ft_putchar2('%');
		else if (line[i] != '%')
			ft_putchar2(line[i]);
		i++;
	}
	va_end(a);
	return (g_count);
}

// int	main()
// {
// 	ft_printf("%x\n", -42);
// 	printf("%x\n", -42);
// 	ft_printf("%X\n", -42);
// 	printf("%X\n", -42);
// 	ft_printf("%#-08x\n", 42);
// 	printf("%#-08x\n", 42);
// 	ft_printf("%9.2p\n", 1234567);
// 	printf("%9.2p\n", 1234567);
// 	printf("%hho, %hho\n", 0, 255 + 42);
// 	ft_printf("%hho, %hho\n", 0, 255 + 42);
// 	printf("{%5p}\n", 0);
// 	ft_printf("{%5p}\n", 0);
// 	printf("%o, %ho, %hho\n", -42, -42, -42);
// 	ft_printf("%o, %ho, %hho\n", -42, -42, -42);
// printf("%.0pa, %.pa\n", 0, 0);
// ft_printf("%.0pa, %.pa\n", 0, 0);
// printf("%.pa, %.0pa\n", 0, 0);
// ft_printf("%.pa, %.0pa\n", 0, 0);
// printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);
// ft_printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);
// printf("{%Lf}\n", -1444565444646.6465424242242l);
// ft_printf("{%Lf}\n", -1444565444646.6465424242242l);
//  ft_printf("%Z\n");
//  ft_printf("% hZ\n");
// ft_printf("% hZ%\n");
// ft_printf("% Z\n", "test");
// // printf("% hZ%\n");
// // printf("%%\n");
// ft_printf("% Z%s\n", "test");
// ft_printf("% Z\n", 42);
// ft_printf("%%%\n");
// //ft_printf("%jx\n", -4294967296);
// ft_printf("%ll#x", 9223372036854775807);
// ft_printf("%u%llu");
//ft_printf("%jx", -4294967296);
//printf("%%d 	 == |%d|\n", 43);
// ft_printf("%%d 	 == |%d|\n", 43);
// ft_printf("%x\n", -8000);
// ft_printf("%#08.5x", 123);
// }