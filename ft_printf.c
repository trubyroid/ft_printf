/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:49:01 by truby             #+#    #+#             */
/*   Updated: 2021/02/06 04:15:26 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_printf(const char *str, ...)
{
	int			i;
	t_struct	*lst;
	va_list		ap;

	va_start(ap, str);
	if (!(lst = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	lst->flag = NULL;
	lst->ap = &ap;
	i = ft_write_and_parse(str, lst);
	free(lst);
	va_end(ap);
	return (i);
}
