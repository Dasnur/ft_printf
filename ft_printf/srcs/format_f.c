/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:54:21 by atote             #+#    #+#             */
/*   Updated: 2019/12/01 13:54:23 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int     number_counting_in(int in)
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

int     poryadok(int len)
{
    int res;

    res = 1;
    while (len > 1)
    {
        res = res * 10;
        len--;
    }
    return (res);
}

char    *ft_itoa(int a)
{
    int     i;
    char    *res;
    int     len;

    i = 0;
    res = (char *)malloc(sizeof(char) * number_counting_in(a) + 1);
    len = number_counting_in(a);
    while (len != 0)
    {
        res[i] = a / poryadok(len) + 48;
        i++;
        a = a % poryadok(len); 
        len--;
    }
    res[i] = '\0';
    return (res);
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
            if (m->long_long_in < 0)
                m->long_long_in = m->long_long_in - 1;
            else
                m->long_long_in = m->long_long_in + 1;
        }
    }
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
                if (m->long_long_in < 0)
                    m->long_long_in = m->long_long_in - 1;
                else
                    m->long_long_in = m->long_long_in + 1;
            }
        }
    }
    return (res);
}

void	print_with_precision(char *res, int i, t_params *m)
{
	int	k;

	k = 0;
    if (m->f_check_octotorp && m->f_check_presicion < 1)
    {
        ft_putchar('.');
        m->f_check_width = m->f_check_width - 1;
    }
	while (--i >= -1)
	{
		if (k > 82)
			ft_putchar('0');
		else
			ft_putchar(res[k++]);
	}
}

void	print_format_f(t_params *m, char *res)
{
	int	len;
    len = 0;
	len = m->f_check_value_precision + 1 + number_counting_in(m->long_long_in) + m->f_check_plus;
	if (m->long_long_in < 0 && !m->f_check_plus)
		len++;
	if (m->long_long_in == 0 && 1/m->doubl > 0)
	{
		len++;
	}
	if (m->f_check_width)
	{
		if (m->f_check_minus)
		{
			if (m->f_check_plus && 1/m->doubl > 0)
				ft_putchar('+');
            res = okruglenie(res, m->f_check_value_precision, m);
            if (m->f_check_space && !m->f_check_plus && m->doubl > 0)
            {
                ft_putchar(' ');
                m->f_check_width = m->f_check_width - 1;
            }
			ft_putlonglong(m->long_long_in);
			print_with_precision(res, m->f_check_value_precision, m);
			if ((m->f_check_width = m->f_check_width - len) > 0)
			{
				while (--(m->f_check_width) >= 0)
					ft_putchar(' ');
			}
		}
		else
		{
			if (m->f_check_zero && m->f_check_plus && m->long_long_in >= 0 && 1/m->doubl > 0)
				ft_putchar('+');
			if ((m->f_check_width = m->f_check_width - len) > 0)
			{
                if ((m->f_check_zero) && (1/m->doubl < 0))
                {
                    ft_putchar('-');
                    m->long_long_in = m->long_long_in * -1;
                    if (m->long_long_in == 0)
                        m->f_check_width--;
                }
                if (m->f_check_zero && m->f_check_space && m->doubl > 0)
                {
                    ft_putchar(' ');
                    m->f_check_width = m->f_check_width - 1;
                }
				while (--(m->f_check_width) >= 0)
				{
					if (m->f_check_zero)
						ft_putchar('0');
					else
						ft_putchar(' ');
				}
			}
            else if (m->f_check_space && !m->f_check_plus && !m->f_check_minus && m->long_long_in > 0)
                ft_putchar(' ');
			if (m->f_check_zero != 1 && m->f_check_plus && m->long_long_in >= 0)
				ft_putchar('+');
            res = okruglenie(res, m->f_check_value_precision, m);
			ft_putlonglong(m->long_long_in);
			print_with_precision(res, m->f_check_value_precision, m);
		}
        return ;
	}
    res = okruglenie(res, m->f_check_value_precision, m);
    if (m->f_check_space && !m->f_check_minus && !m->f_check_plus)
        ft_putchar(' ');
    if (1/m->doubl < 0 && m->long_long_in == 0)
        ft_putchar('-');
    if (m->f_check_plus && 1/m->doubl > 0)
        ft_putchar('+');
    ft_putlonglong(m->long_long_in);
	print_with_precision(res, m->f_check_value_precision, m);
}

char    *get_left_space_for_la(char *res)
{
    char    *nres;
    int     i;
    int     len;
    int     k;

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

char    *sdvig(char *res, int k)
{
    char    *resn;
    int        i;
    int         tmp;

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

char    *long_arif(char *a, char *b, char sign)
{
    int i;
    int len1;
    int len2;
    char    *res;
    int    tmp;

    tmp = 0;
    res = ft_strdup(a);
    i = 248;
    if (sign == '+')
    {
        while (i >= 0)
        {
            res[i] = (a[i] - 48) + (b[i] - 48) + 48;
            if (tmp != 0)
            {
                res[i] = res[i] + 1;
                tmp = 0;
            }
            if (res[i] > 57)
            {
                res[i] = res[i] - 10;
                tmp = 1;;
            }
            i--;
        }
    }
    return (res);
}

char	*mant_to_byte(long long int mant)
{
	int	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * 25);
	i = 0;
	while (mant != 0)
	{
		res[i] = (mant % 2) + 48;
		mant = mant / 2;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char    *get_only_mant(char *res, long long int in, int flag)
{
    char    *mant;
    int     i;
    int     k;
    int     f;

    f = 0;
    mant = (char *)malloc(sizeof(char) * 69);
    mant[53] = '\0';
    if (in == 0 && flag == 0 && res[54] == '1')
    {
        k = 52;
        mant[53] = '\0';
        f = 1;
    }
    else
        k = 52 - ft_strlen(mant_to_byte(in));
    i = 0;
    if (res[57] == '0' && flag == 0 && in == 0 && res[58] == '0')
        k = 51;
    if (flag == 1)
        k = 63;
    if (flag == 2)
        k = 53;
    while (k >= 0)
    {
        mant[i] = res[k];
        i++;
        k--;
    }
    mant[i] = '\0';
    return (mant);
}

char    *get_good_line_of_pre(char *res)
{
    char    *resnew;
    int len;
    int i;

    i = 0;
    len = 0;
    resnew = (char *)malloc(sizeof(char) * 144);
    resnew[145] = '\0';
    resnew[len] = '.';
    len++;
    i = 128;
    while (len < 145)
    {
        if (res[i] == '0' || res[i] == '\0')
            resnew[len] = '0';
        resnew[len] = res[i];
        len++;
        i++;
    }
    return(resnew);
}

char     *bit_double(double res, long long int in)
{
    char    *result;
    unsigned char   *gg = (unsigned char *)&res;
    unsigned char   tmp;
    int i;
    int j;
    int p;
    int count;

    count = 0;
    result = (char *)malloc(sizeof(char) *150);
    result[65] = '\0';
    p = 0;
    i = 0;
    j = 0;
    while (i < 8)
    {
        tmp = *gg;
        j = 0;
        while (j < 8)
        {
            result[p] = (tmp & 1) + 48;
            if (result[p] == '0')
                count++;
            tmp >>= 1;
            j++;
            p++;
        }
        i++;
        gg++;
    }
    if (count > 45 && in == 0 && count < 57 && result[54] == '1')
    {
        return(get_only_mant(result, in, 2));
    }
    return (get_only_mant(result, in, 0));
}

char     *bit_fourth(long double res, long long int in)
{
    char    *result;
    unsigned char   *gg = (unsigned char *)&res;
    unsigned char   tmp;
    int i;
    int j;
    int p;

    result = (char *)malloc(sizeof(char) *150);
    result[129] = '\0';
    p = 0;
    i = 0;
    j = 0;
    while (i < 8)
    {
        tmp = *gg;
        j = 0;
        while (j < 16)
        {
            if (i < 7)
                result[p++] = (tmp & 1) + 48;
            tmp >>= 1;
            j++;
        }
        i++;
        gg++;
    }
    return (result);
}

void    first_manta_for_null(char *manta1, char *manta, t_params *m, int flag)
{
    while (m->ff < 8 && manta1[m->i] != '\0' && flag)
    {
        m->res[m->i] = manta1[m->i];
        m->i++;
        m->ff++;
    }
    while (manta[m->ff] != '\0')
    {
        if (manta[m->ff] >= '0' && manta[m->ff] <= '9')
        {
            m->res[m->i] = manta[m->ff];
            if (m->res[m->i] == '1') 
                m->type++; 
            m->i++;
        }
        m->ff++;
    }
    while (m->res[m->i - 1] == '0')
    {
        m->res[m->i - 1] = '\0';
        m->i--;
    }
    m->res[m->i] = '\0';
}

int    kratnie5_manta_for_null(char *manta, t_params *m)
{
    while (m->i >= 0)
    {
         if (manta[m->i] == '1')
         {
             m->type = m->i;
             break ;
         }
         m->i--;
    }
    m->i = 0;
    if (m->type < 12)
    {
        while (m->i <= m->type)
        {
            m->res[m->i] = manta[m->i];
            m->i++;
        }
        if (m->res[m->i - 1] == '1' && m->res[m->i - 2] == '0' && m->res[m->i - 3] == '0')
        {
            m->res[m->i - 2] = '1';
            m->i--;
        } 
        m->res[m->i] = '\0';
        return (1);
    }
    return (0);
}

void    second_manta_for_null(char *manta1, int flag, t_params *m)
{
    m->type = 0;
    while (manta1[m->i] == '0')
    {
        m->res[m->i] = manta1[m->i];
        m->i++;
    }
    if (m->i == 52)
    {
        m->res[m->i++] = '0';
    }
    while (m->ff < 8 && manta1[m->i] != '\0' && m->i < 49 && !flag)
    {
        m->res[m->i] = manta1[m->i];
        m->i++;
        m->ff++;
    }
}

char    *manta_for_null(char *manta, char *manta1, int flag)
{
    t_params    m;

    m.type = 14;
    m.ff = 0;
    m.res = (char *)malloc(sizeof(char) * 150);
    m.i = 55;
    if (kratnie5_manta_for_null(manta, &m))
        return (m.res);
    second_manta_for_null(manta1, flag, &m);
    first_manta_for_null(manta1, manta, &m, flag);
    free(manta);
    free(manta1);
    if (m.type == 52)
        return ("11111111111111111111111111111111111111111111111111111");
    else
        return (m.res);
}

char    **map_of_stepen()
{
    int y;
	char **res11;

    y = 0;
    res11 = (char **)malloc(sizeof(char *) * 120);
    while (y < 119)
    {
        if (y != 0)
            res11[y] = (char *)malloc(sizeof(char) * 400);
        y++;
    }
    res11[y] = 0;
    y = 0;
	while (y < 119)
	{
		if (y == 0)
        {
			res11[y] = ft_itoa(5);
            res11[y] = get_left_space_for_la(res11[y]);
        }
        else if (y != 0)
        {
            res11[y] = long_arif(res11[y - 1], res11[y - 1], '+');
            res11[y] = long_arif(res11[y], res11[y - 1], '+');
            res11[y] = long_arif(res11[y], res11[y - 1], '+');
            res11[y] = long_arif(res11[y], res11[y - 1], '+');
        }
		y++;
	}
    return(res11);
}

char    *get_allres(char **res11, t_params *m)
{
    int     i;
    char    *allres;

    allres = get_left_space_for_la(ft_itoa(0));
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
    return (allres = get_good_line_of_pre(allres));
}

void    vibor_mantiss(long double doubl1, t_params *m)
{
    int flag;
    int i;

    i = 0;
    flag = 1;
    if (doubl1 != m->doubl)
    {
        while (i < 50)
        {
            if (m->res[i] == '1')
                flag = 0;
            i++;
        }
        if (flag)
            m->manta = manta_for_null(bit_double(m->doubl, m->long_long_in), m->res, flag);
        else
            m->manta = manta_for_null(bit_double(m->doubl, m->long_long_in), bit_double(doubl1, 1), flag);
    }
    else
        m->manta = bit_double(m->doubl, m->long_long_in);
}

void	format_f(char *line, int i, va_list a)
{
	t_params		m;
    int             y;
    long double     doubl1;
    int             flag;
    char            **res11;

    flag = 1;
    y = 0;
    take_all_params(line, i, &m);
    if (m.f_check_value_precision == 0)
        m.f_check_value_precision = 6;
    if (!ft_check_long_f(line, i))
	    m.doubl = va_arg(a, double);
    else
        m.doubl = va_arg(a, long double);
	m.long_long_in = m.doubl;
    doubl1 = m.doubl;
    if (m.long_long_in == 0 && m.doubl > 0)
        doubl1 = doubl1 + 1;
    if (m.long_long_in == 0 && m.doubl < 0)
        doubl1 = doubl1 - 1;
    m.res = get_only_mant(bit_fourth(doubl1, 1), 1, 1);
    vibor_mantiss(doubl1, &m);
 	res11 = map_of_stepen();
	print_format_f(&m, get_allres(res11, &m));
}
