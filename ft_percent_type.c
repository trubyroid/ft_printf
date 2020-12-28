/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:31:12 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 23:18:32 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_percent_type(t_struct *lst)
{
	char			*out;

	if (lst->width > 1)
	{
		if (ft_strchr(lst->flag, '0') && !ft_strchr(lst->flag, '-'))
			out = ft_calloc_char(lst->width, '0');
		else
			out = ft_calloc_char(lst->width, ' ');
		if (out == NULL)
			return (-1);
		if (ft_strchr(lst->flag, '-'))
			out[0] = '%';
		else
			out[lst->width - 1] = '%';
		write(1, out, lst->width);
		free(out);
		return (lst->width);
	}
	write(1, "%", 1);
	return (1);
}
