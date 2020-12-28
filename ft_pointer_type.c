/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:06:37 by truby             #+#    #+#             */
/*   Updated: 2020/12/28 18:36:15 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				ft_out(t_struct *lst, int i, char *result)
{
	char				*width_sp;

	if (lst->width > i + 2)
	{
		if (!(width_sp = ft_calloc_char(lst->width, ' ')))
			return (0);
	}
	if (!ft_strchr(lst->flag, '-') && lst->width > i + 2)
	{
		write(1, width_sp, lst->width - (i + 2));
		free(width_sp);
	}
	write(1, "0x", 2);
	if (lst->precision == -1)
		write(1, result, ft_strlen(result));
	if (ft_strchr(lst->flag, '-') && lst->width > i + 2)
	{
		write(1, width_sp, lst->width - (i + 2));
		free(width_sp);
	}
	return (1);
}

static int				ft_razr(t_struct *lst, unsigned long int h)
{
	int					i;

	i = 1;
	while (h >= 16)
	{
		h = h / 16;
		i++;
	}
	if (lst->precision == 0)
		i--;
	return (i);
}

int						ft_pointer_type(t_struct *lst)
{
	char				*result;
	int					i;
	unsigned long int	h;

	if (ft_strchr(lst->flag, '0') || lst->precision > 0)
		return (0);
	h = va_arg(*(lst->ap), unsigned long int);
	i = ft_razr(lst, h);
	if (!(result = (char *)malloc(sizeof(char) * i + 1)))
		return (-1);
	result = ft_hex(result, h, i, 96);
	if (lst->width > i + 2)
	{
		if (!ft_out(lst, i, result))
			return (-1);
		free(result);
		return (lst->width);
	}
	ft_out(lst, i, result);
	free(result);
	return (i + 2);
}
