/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 22:53:17 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 23:19:21 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_processor(t_struct *lst)
{
	int		len;

	len = 0;
	if (lst->type == 'i' || lst->type == 'd')
		len = ft_int_type(lst);
	else if (lst->type == 'u')
		len = ft_un_int_type(lst);
	else if (lst->type == 'c')
		len = ft_char_type(lst);
	else if (lst->type == '%')
		len = ft_percent_type(lst);
	else if (lst->type == 's')
		len = ft_str_type(lst);
	else if (lst->type == 'p')
		len = ft_pointer_type(lst);
	else if (lst->type == 'x' || lst->type == 'X')
		len = ft_xx_type(lst);
	else
		return (-1);
	return (len);
}
