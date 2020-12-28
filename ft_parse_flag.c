/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:14:36 by truby             #+#    #+#             */
/*   Updated: 2020/12/28 18:50:24 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char			*substr(char const *s, unsigned int start, size_t len)
{
	char		*b;
	size_t		z;

	z = 0;
	if (s == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (!(b = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (z < len)
	{
		b[z] = s[start];
		z++;
		start++;
	}
	b[z + 1] = '\0';
	return (b);
}

char				*ft_parse_flag(char *str)
{
	char			*flags;
	int				i;

	i = 0;
	flags = "-0";
	while (str[0] != flags[i] && flags[i] != '\0')
		i++;
	if (str[0] == flags[i])
	{
		i = 0;
		while (!ft_isalpha(str[i]))
		{
			i++;
			if (str[i] == '.' || str[i] == '*')
				break ;
			if (ft_isdigit(str[i]) && str[i] != '0')
				break ;
		}
		return (substr(str, 0, i));
	}
	return (NULL);
}
