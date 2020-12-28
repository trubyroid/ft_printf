/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:49:01 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 23:19:11 by truby            ###   ########.fr       */
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
	i = ft_parser_var(str, lst);
	if (lst->flag != NULL)
		free(lst->flag);
	free(lst);
	va_end(ap);
	return (i);
}
