/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:05:01 by truby             #+#    #+#             */
/*   Updated: 2020/12/28 18:39:40 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				ft_razr(unsigned int i)
{
	int					k;

	k = 1;
	while (i >= 10)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

static void				ft_putnbr_un_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_un_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

static int				ft_out(t_struct *lst, unsigned int i, int k, char *pre)
{
	if (lst->precision > ft_razr(i))
	{
		write(1, pre, ft_strlen(pre));
		ft_putnbr_un_fd(i, 1);
		free(pre);
	}
	else
	{
		if (lst->precision == 0)
		{
			if (i == 0)
				return (0);
		}
		ft_putnbr_un_fd(i, 1);
	}
	return (k);
}

static int				ft_wdth(t_struct *lst, unsigned int i, int k, char *pre)
{
	char				*width_sp;

	if (ft_strchr(lst->flag, '0') && lst->precision == -1)
	{
		if (!ft_strchr(lst->flag, '-'))
			width_sp = ft_calloc_char((lst->width), '0');
		else
			width_sp = ft_calloc_char((lst->width), ' ');
	}
	else
		width_sp = ft_calloc_char((lst->width), ' ');
	if (width_sp == NULL)
		return (-1);
	if (i == 0 && lst->precision == 0)
	{
		write(1, width_sp, lst->width);
		return (lst->width);
	}
	if (ft_strchr(lst->flag, '-'))
		ft_out(lst, i, k, pre);
	write(1, width_sp, lst->width - k);
	if (!(ft_strchr(lst->flag, '-')))
		ft_out(lst, i, k, pre);
	free(width_sp);
	return (lst->width);
}

int						ft_un_int_type(t_struct *lst)
{
	unsigned int		i;
	int					k;
	char				*pre;

	i = va_arg(*(lst->ap), unsigned int);
	k = ft_razr(i);
	if (lst->precision > k)
	{
		if (!(pre = ft_calloc_char((lst->precision - k), '0')))
			return (-1);
		k = lst->precision;
	}
	if (lst->width >= k)
		return (ft_wdth(lst, i, k, pre));
	return (ft_out(lst, i, k, pre));
}
