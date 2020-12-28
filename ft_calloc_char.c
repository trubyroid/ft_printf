/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:22:42 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 20:52:46 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char				*ft_calloc_char(int num, char a)
{
	char				*h;
	int					i;

	i = 0;
	if (!(h = (char *)malloc(sizeof(char) * num + 1)))
		return (NULL);
	while (i < num)
	{
		h[i] = a;
		i++;
	}
	h[i] = '\0';
	return (h);
}
