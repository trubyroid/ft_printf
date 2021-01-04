/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:09:52 by truby             #+#    #+#             */
/*   Updated: 2021/01/04 22:24:20 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_out(t_struct *lst, int k, char *pre, char *hex)
{
	if (lst->precision == k)
	{
		write(1, pre, ft_strlen(pre));
		write(1, hex, ft_strlen(hex));
		free(pre);
	}
	else
	{
		if (lst->precision == 0)
		{
			if (hex[0] == '0')
			{
				free(hex);
				return (0);
			}
		}
		write(1, hex, ft_strlen(hex));
	}
	free(hex);
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

static int			ft_wdth(t_struct *lst, char *pre, char *hex, int k)
{
	char			*width_sp;

	if (!(width_sp = ft_calloc_width(lst)))
		return (-1);
	if (hex[0] == '0' && lst->precision == 0)
	{
		write(1, width_sp, lst->width);
		free(hex);
	}
	else
	{
		if (ft_strchr(lst->flag, '-'))
			ft_out(lst, k, pre, hex);
		write(1, width_sp, lst->width - k);
		if (!(ft_strchr(lst->flag, '-')))
			ft_out(lst, k, pre, hex);
	}
	free(width_sp);
	return (lst->width);
}

static int			ft_razr(unsigned int i)
{
	int				k;

	k = 1;
	while (i >= 16)
	{
		i = i / 16;
		k++;
	}
	return (k);
}

int					ft_xx_type(t_struct *lst)
{
	unsigned int	i;
	int				k;
	char			*hex;
	char			*pre;

	i = va_arg(*(lst->ap), unsigned int);
	k = ft_razr(i);
	if (!(hex = (char *)malloc(sizeof(char) * k + 1)))
		return (-1);
	if (lst->type == 'x')
		hex = ft_hex(hex, i, k, 96);
	else
		hex = ft_hex(hex, i, k, 64);
	if (lst->precision >= k)
	{
		if (!(pre = ft_calloc_char((lst->precision - k), '0')))
			return (-1);
		k = lst->precision;
	}
	if (lst->width >= k)
		return (ft_wdth(lst, pre, hex, k));
	return (ft_out(lst, k, pre, hex));
}
