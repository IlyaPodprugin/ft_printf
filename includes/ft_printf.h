/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:47:45 by ilya              #+#    #+#             */
/*   Updated: 2022/01/03 00:12:17 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <string.h>

typedef struct	s_option
{
	int		type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		star;
}	t_option;


int	ft_printf(const char *str, ...);

#endif