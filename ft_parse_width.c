/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:42:25 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 23:18:02 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_star_width(int i, t_struct *lst)
{
	i = va_arg(*(lst->ap), int);
	if (i < 0)
	{
		if (lst->flag != NULL)
			lst->flag[ft_strlen(lst->flag)] = '-';
		else
		{
			if (!(lst->flag = ft_substr("-", 0, 1)))
				return (-1);
		}
		return (-i);
	}
	return (i);
}

int				ft_parse_width(char *str, t_struct *lst)
{
	int				i;
	char			*sub;
	int				k;

	i = 0;
	while (str[i] != '.' && str[i] != '*' && !ft_isalpha(str[i]))
	{
		if ((ft_isdigit(str[i]) && str[i] != '0') || str[i] == '%')
			break ;
		i++;
	}
	k = i;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[k]) != 0)
			k++;
		if (!(sub = ft_substr(str, i, k - i)))
			return (-1);
		i = ft_atoi(sub);
		free(sub);
		return (i);
	}
	else if (str[i] == '*')
		return (ft_star_width(i, lst));
	return (0);
}
