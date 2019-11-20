#include "../includes/libftprintf.h"

int number_counting_in(int in)
{
    int i;
    
    i = 0;
    if (in == 0)
        return (1);
    while(in != 0)
    {
        in /= 10;
        i++;
    }
    return (i);
}

char    *okruglenie(char *res, int i, t_params *m)
{
    int k;
    int flag;

    flag = 0;
    k = 0;
    while (--i >= -1)
        k++;
    k--;
    if (k == -1)
    {
        k = k + 1;
        if (res[k + 1] > 52)
        {
            if (m->in < 0)
                m->in = m->in - 1;
            else
                m->in = m->in + 1;
        }
    }
  //  printf("|%c-->%c|", res[k], res[k + 1]);
    if (res[k + 1] > 52)
    {
        if (res[k] != '9')
            res[k] = res[k] + 1;
        else
        {
            res[k--] = '0';
            while (res[k] == '9')
            {
                res[k] = '0';
                k--;
            }
            if (res[k] != '.')
                res[k] = res[k] + 1;
            else
            {
                if (m->in < 0)
                    m->in = m->in - 1;
                else
                    m->in = m->in + 1;
            }
        }
    }
    return (res);
}

void	print_with_precision(char *res, int i, t_params *m)
{
	int	k;

	k = 0;
	while (--i >= -1)
	{
		if (k == 50)
			ft_putchar('0');
		else
			ft_putchar(res[k++]);
	}
}

void	print_format_f(t_params *m, char *res)
{
	int	len;
    len = 0;
 //   printf("%c", res[m->f_check_value_precision + 1]);
    if (res[m->f_check_value_precision + 2] == '9' && res[m->f_check_value_precision + 3] == '9' && res[m->f_check_value_precision + 4] == '9' && m->f_check_value_precision > 9)
        res = okruglenie(res, m->f_check_value_precision + 1, m);
//    printf("%s", res);
	len = m->f_check_value_precision + 1 + number_counting_in(m->in) + m->f_check_plus;
//    printf("%d\n", number_counting(m->in));
	if (m->in < 0 && !m->f_check_plus)
		len++;
	if (m->in == 0 && 1/m->doubl > 0)
	{
		len++;
//		m->f_check_plus = 0;
	}
 //   printf("%d", len);
	if (m->f_check_width)
	{
		if (m->f_check_minus)
		{
			if (m->f_check_plus)
				ft_putchar('+');
            res = okruglenie(res, m->f_check_value_precision, m);
			ft_putnbr(m->in);
			print_with_precision(res, m->f_check_value_precision, m);
			if ((m->f_check_width = m->f_check_width - len) > 0)
			{
				while (--(m->f_check_width) >= 0)
					ft_putchar(' ');
			}
		}
		else
		{
			if (m->f_check_zero && m->f_check_plus && m->in >= 0 && 1/m->doubl > 0)
				ft_putchar('+');
			if ((m->f_check_width = m->f_check_width - len) > 0)
			{
 //               printf("\n%f\n", 1/m->doubl);
 //               printf(1/m->doubl == 0.0 ? "|true|" : "|false|");
                if ((m->f_check_zero) && (1/m->doubl < 0))
                {
                    ft_putchar('-');
                    m->in = m->in * -1;
                    if (m->in == 0)
                        m->f_check_width--;
                }
				while (--(m->f_check_width) >= 0)
				{
					if (m->f_check_zero)
						ft_putchar('0');
					else
						ft_putchar(' ');
				}
			}
			if (m->f_check_zero != 1 && m->f_check_plus && m->in >= 0)
				ft_putchar('+');
            res = okruglenie(res, m->f_check_value_precision, m);
			ft_putnbr(m->in);
			print_with_precision(res, m->f_check_value_precision, m);
		}
        return ;
	}
    res = okruglenie(res, m->f_check_value_precision, m);
    if (1/m->doubl < 0 && m->in == 0)
        ft_putchar('-');
    ft_putnbr(m->in);
	print_with_precision(res, m->f_check_value_precision, m);
}

void	format_f(char *line, int i, va_list a)
{
	t_params		m;
	char			res[100];
	int				k;
	double			diff;
	unsigned int	tmp;

	k = 1;
	while (k < 100)
		res[k++] = '0';
	k = 1;
    take_all_params(line, i, &m);
    if (m.f_check_value_precision == 0)
        m.f_check_value_precision = 6;
	m.doubl = va_arg(a, double);
	m.in = m.doubl;
  //  printf("%d", m.in);
   // m.doubl = (double)m.in;
	tmp = m.in;
	diff = Always_pozitive(m.doubl) - Always_pozitive(m.in);
	res[0] = '.';
	while (k < 100)
	{
		tmp = diff * 10;
     //   printf("tmp  ->%d\n", tmp);
		res[k] = tmp + 48;
     //   printf("%c\n", res[k]);
		k++;
		diff = diff * 10 - tmp;
        tmp = (int)diff;
        if (tmp == 1)
            diff = 0;
 //       printf("tmp ->%d", tmp);
 //       printf("diff ->%f\n", diff);
	}
//	res[k] = '\0';
 //   printf("%s\n", res);
	print_format_f(&m, &(res[0]));
//	ft_putnbr(m.in);
//	ft_putchar('.');
//	while (--m.f_check_value_precision >= 0)
//	{
//		if (k == 49)
//			ft_putchar('0');
//		else
//			ft_putchar(res[k++]);
//	}
//	res = double_to_str(m.flo);
//	while (m.flo[k] != '.')
//		k++;
//	res = ft_strsub(m.flo, k, ft_strlen(m.flo) - i);
//	printf("%s", res);
//	print_format_f(&m);
}