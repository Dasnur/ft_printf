/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:17:30 by acarlett          #+#    #+#             */
/*   Updated: 2019/12/13 20:28:23 by acarlett         ###   ########.fr       */
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
				break ;
			i++;
			continue ;
		}
		else if (line[i] == '%' && line[i + 1] == '%' && (i++))
			ft_putchar('%');
		else if (line[i] != '%')
			ft_putchar(line[i]);
		i++;
	}
	va_end(a);
}

// int main()
// {
// 	static unsigned short		ush_pos_1 = 3047;
// 	static unsigned int		ui_pos_1 = 878023;
// 	static unsigned long		ul_pos_1 = 22337203685477;
// 	static unsigned long long	ull_pos_1 = 22337203685477;
// 	static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
// 	static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
// 	static long		l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
// 	ft_printf("%hi\n", sh_neg_1);
// 	ft_printf("%-17.14llu\n", ull_pos_1);
// 	ft_printf("%lli\n", ll_neg_1);
// 	ft_printf("%08hu\n", ush_pos_1);
// 	ft_printf("%hi\n", (short)32767);
// 	ft_printf("%i\n", 0);
// 	ft_printf("%.24lu\n", ul_pos_1);
// 	ft_printf("%llu\n", 0ull);
// 	ft_printf("%u\n", ui_pos_1);
// 	ft_printf("\n%s{green}\n------------------\n", "TEST WITH COLOUR");
// 	ft_printf("%s{red}\n", "Hello");
// 	ft_printf("%s{cyan}\n", "Hello");
// 	ft_printf("%s{green}\n", "Hello");
// 	ft_printf("%s{yellow}\n", "Hello");
// 	ft_printf("%s{blue}\n", "Hello");
// 	ft_printf("%s{magenta}\n", "Hello");
// 	ft_printf("\n%s{green}\n------------------\n", "TEST WITH *");
// 	ft_printf("%*.*s\n", 9, 3, "Hello");
// 	ft_printf("\n%s{green}\n------------------\n", "TEST WITH e/E");
// 	ft_printf("%.e\n", 1123451324.12);
// 	ft_printf("%.e\n", 91.2345132412);
// 	ft_printf("%.E\n", 91.2345132412);
// 	ft_printf("\n%s{green}\n------------------\n", "TEST WITH D");
// 	ft_printf("%D\n", 7234);
// 	ft_printf("\n%s{green}\n------------------\n", "TEST WITH S");
// 	ft_printf("|%-10.5s", "He\0dre");
// 	printf("%-10.5s|\n", "He\0dre");
// 	ft_printf("\n%s{green}\n------------------\n", "TEST WITH F");
// 	ft_printf("%.20f\n", 0.00000000010);
// 	printf("%.20f\n", 0.00000000010);
// 	ft_printf("%.50f\n", 0.8);
// 	printf("%.50f\n", 0.8);
// 	ft_printf("%#.0f\n", 15.421);
// 	printf("%#.0f\n", 15.421);
// 	ft_printf("%12.12f\n", 1235.12345);
// 	printf("%12.12f\n", 1235.12345);
// 	ft_printf("%.70f\n", 0.345);
// 	printf("%.70f\n", 0.345);
// }
