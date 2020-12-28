/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:45:04 by truby             #+#    #+#             */
/*   Updated: 2020/12/27 23:16:38 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct	s_spec_list
{
	char		*flag;
	int			width;
	int			precision;
	char		type;
	va_list		*ap;
}				t_struct;

int				ft_printf(const char *line, ...);
int				ft_parser_var(const char *str, t_struct *lst);
char			*ft_parse_flag(char *str);
int				ft_parse_width(char *str, t_struct *lst);
int				ft_parse_precision(char *str, t_struct *lst);
char			ft_parse_type(char *str);
int				ft_processor(t_struct *list);
int				ft_int_type(t_struct *lst);
int				ft_un_int_type(t_struct *lst);
int				ft_char_type(t_struct *lst);
int				ft_percent_type(t_struct *lst);
int				ft_str_type(t_struct *lst);
int				ft_pointer_type(t_struct *lst);
int				ft_xx_type(t_struct *lst);
char			*ft_hex(char *res, unsigned long int h, int razr, char reg);
char			*ft_calloc_char(int num, char a);

#endif
