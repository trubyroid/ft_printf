/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:11:03 by truby             #+#    #+#             */
/*   Updated: 2020/12/28 18:38:48 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			ft_wr(int i, t_struct *lst, char *input, char *width)
{
	if (ft_strchr(lst->flag, '-'))
	{
		write(1, input, i);
		write(1, width, lst->width - i);
	}
	else
	{
		write(1, width, lst->width - i);
		write(1, input, i);
	}
}

int					ft_str_type(t_struct *lst)
{
	char			*input;
	char			*width;
	int				i;

	if (!(input = va_arg(*(lst->ap), char *)))
		input = "(null)";
	if (lst->precision > (int)ft_strlen(input) || lst->precision == -1)
		i = ft_strlen(input);
	else
		i = lst->precision;
	if (lst->width > i)
	{
		if (!(width = ft_calloc_char(lst->width - i, ' ')))
			return (-1);
		ft_wr(i, lst, input, width);
		free(width);
		return (lst->width);
	}
	if (lst->precision > (int)ft_strlen(input))
	{
		write(1, input, ft_strlen(input));
		return (ft_strlen(input));
	}
	write(1, input, i);
	return (i);
}
