/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:47:45 by ilya              #+#    #+#             */
/*   Updated: 2022/01/04 06:51:32 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_option
{
	int		type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		star;
}	t_option;

int	ft_printf(const char *str, ...);
int	ft_print_char(int char_to_print);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long ptr);
int	ft_print_digit(int digit);
int	ft_print_hex(unsigned int digit, int letter_case);

#endif