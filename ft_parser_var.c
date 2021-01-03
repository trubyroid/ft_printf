/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 22:36:07 by truby             #+#    #+#             */
/*   Updated: 2021/01/04 02:45:45 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char			*ft_spec(int len, const char *s)
{
	int				i;
	char			*spec;

	i = 0;
	while (!ft_isalpha(s[len + i]) && s[len + i] != '%' && s[len + i] != '\0')
		i++;
	if (s[len + i] == '\0')
		return (NULL);
	if (!(spec = ft_substr(s, len, i + 1)))
		return (NULL);
	return (spec);
}

static int			ft_prs(char *spec, t_struct *lst)
{
	if (lst->flag != NULL)
		free(lst->flag);
	lst->flag = ft_parse_flag(spec);
	if (lst->flag == NULL && (spec[0] == '0' || spec[0] == '-'))
		return (-1);
	lst->width = ft_parse_width(spec, lst);
	lst->precision = ft_parse_precision(spec, lst);
	if (lst->width == -1 || lst->precision == -2)
		return (-1);
	lst->type = ft_parse_type(spec);
	return (ft_processor(lst));
}

static int			ft_parser(const char *str, t_struct *lst, int i, int len)
{
	int				lenspec;
	char			*spec;

	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!(spec = ft_spec(i + 1, str)))
				return (-1);
			i = i + ft_strlen(spec);
			lenspec = ft_prs(spec, lst);
			if (lenspec < 0)
				return (lenspec);
			len = len + lenspec;
			free(spec);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

int					ft_parser_var(const char *str, t_struct *lst)
{
	int				len;
	int				i;

	i = 0;
	len = 0;
	return (ft_parser(str, lst, i, len));
}
