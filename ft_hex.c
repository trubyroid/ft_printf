/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:53:15 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 20:53:24 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_hex(char *hex, unsigned long int h, int razr, char reg)
{
	int		o;

	hex[razr--] = '\0';
	while (razr >= 0)
	{
		o = h % 16;
		if (h > 16 && o > 9)
			hex[razr] = reg + (o - 9);
		else if (h > 16 && o <= 9)
			hex[razr] = o + '0';
		else if (h < 16 && h > 9)
			hex[razr] = reg + (h - 9);
		else if (h <= 9)
			hex[razr] = h + '0';
		else
			hex[razr] = '0';
		razr--;
		h = h / 16;
	}
	return (hex);
}
