/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:03:51 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 23:17:46 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int				ft_pr_prec(int i, char *str)
{
	int					k;
	char				*sub;

	k = i;
	while (ft_isdigit(str[k]))
		k++;
	if (!(sub = ft_substr(str, i, k - i)))
		return (-2);
	k = ft_atoi(sub);
	free(sub);
	return (k);
}

int						ft_parse_precision(char *str, t_struct *lst)
{
	int					i;

	i = 0;
	while (str[i] != '.' && !ft_isalpha(str[i]) && str[i] != '%')
		i++;
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
		return (ft_pr_prec(i + 1, str));
	else if (str[i] == '.' && ft_isalpha(str[i + 1]))
		return (0);
	else if (str[i] == '.' && str[i + 1] == '*')
	{
		i = va_arg(*(lst->ap), int);
		if (i >= 0)
			return (i);
	}
	return (-1);
}
