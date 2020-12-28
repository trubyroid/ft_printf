/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:48:04 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 22:03:13 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char			*ifelse(char *out, t_struct *lst)
{
	if (ft_strchr(lst->flag, '-'))
		out[0] = (char)va_arg(*(lst->ap), int);
	else
		out[lst->width - 1] = (char)va_arg(*(lst->ap), int);
	return (out);
}

int					ft_char_type(t_struct *lst)
{
	char			*out;
	int				i;
	char			c;

	i = 0;
	if (lst->precision != (-1) || ft_strchr(lst->flag, '0'))
		return (0);
	if (lst->width > 0)
	{
		if (!(out = ft_calloc_char(lst->width, ' ')))
			return (0);
		out = ifelse(out, lst);
		write(1, out, lst->width);
		free(out);
		return (lst->width);
	}
	c = (char)va_arg(*(lst->ap), int);
	write(1, &c, 1);
	return (1);
}
