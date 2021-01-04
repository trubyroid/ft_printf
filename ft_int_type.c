/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:02:30 by truby             #+#    #+#             */
/*   Updated: 2021/01/04 20:32:40 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_razr(int i)
{
	int				k;
	unsigned int	g;

	k = 1;
	g = i;
	if (i < 0)
		g = (-i);
	while (g >= 10)
	{
		g = g / 10;
		k++;
	}
	return (k);
}

static int			ft_out(t_struct *lst, int k, int i, char *pre)
{
	unsigned int	g;

	g = i;
	if (lst->precision == 0 && i == 0)
		return (0);
	if (i < 0 && i > -2147483648)
	{
		write(1, "-", 1);
		g = (-i);
	}
	if (lst->precision > ft_razr(i))
	{
		write(1, pre, ft_strlen(pre));
		ft_putnbr_fd(g, 1);
		free(pre);
	}
	else
		ft_putnbr_fd(g, 1);
	if (g < 0 && lst->precision == k)
		return (k + 1);
	return (k);
}

static char			*ft_calloc_width(t_struct *lst)
{
	char			*width_sp;

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
		return (NULL);
	return (width_sp);
}

static int			ft_wdth(t_struct *lst, char *pre, int i, int k)
{
	char			*width_sp;

	if (!(width_sp = ft_calloc_width(lst)))
		return (-1);
	if (i == 0 && lst->precision == 0 && lst->width > 0)
		write(1, width_sp, lst->width);
	else
	{
		if (ft_strchr(lst->flag, '-'))
			k = ft_out(lst, k, i, pre);
		if (i < 0 && width_sp[0] == '0')
			write(1, "-", 1);
		if (lst->width > k && lst->precision <= k)
			write(1, width_sp, lst->width - k);
		if (i < 0 && width_sp[0] == '0')
			i = (-i);
		if (!(ft_strchr(lst->flag, '-')))
			k = ft_out(lst, k, i, pre);
	}
	free(width_sp);
	if (k > lst->width)
		return (k);
	return (lst->width);
}

int					ft_int_type(t_struct *lst)
{
	int				i;
	int				k;
	char			*pre;

	i = va_arg(*(lst->ap), int);
	k = ft_razr(i);
	if (lst->precision > k)
	{
		if (!(pre = ft_calloc_char((lst->precision - k), '0')))
			return (-1);
		k = lst->precision;
	}
	if (lst->precision <= k && i < 0)
		k++;
	if (lst->width >= k)
		return (ft_wdth(lst, pre, i, k));
	return (ft_out(lst, k, i, pre));
}
