/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:35:41 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 19:55:10 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_uint(unsigned int digit)
{
	int				len;
	char			*result;
	unsigned int	digit_cpy;

	len = 0;
	digit = (unsigned int)digit;
	digit_cpy = digit;
	if (!digit)
		len += ft_print_char('0');
	else
		len += print_digit(len, result, digit);
	return (len);
}
