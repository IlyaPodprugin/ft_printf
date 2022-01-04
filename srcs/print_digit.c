/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:55:01 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 19:55:25 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_digit(int len, char *result, unsigned int digit)
{
	int				counter;
	unsigned int	digit_cpy;

	counter = 0;
	digit_cpy = digit;
	while (digit_cpy)
	{
		digit_cpy /= 10;
		counter++;
	}
	result = (char *)malloc(sizeof(char) * counter + 1);
	if (!result)
		return (0);
	result[counter] = '\0';
	while (digit)
	{
		result[counter - 1] = digit % 10 + 48;
		digit /= 10;
		counter--;
	}
	len += ft_print_str(result);
	free(result);
	return (len);
}
