/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:50:57 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 20:31:29 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count_size(unsigned int digit)
{
	int		counter;

	counter = 0;
	while (digit != 0)
	{
		digit /= 16;
		counter++;
	}
	return (counter);
}

static void	fill_result(char *result, int counter,
					unsigned int digit, int letter_case)
{
	while (digit != 0)
	{
		if (digit % 16 >= 10)
			result[counter - 1] = digit % 16 + letter_case - 33;
		else
			result[counter - 1] = digit % 16 + 48;
		digit /= 16;
		counter--;
	}
}

int	ft_print_hex(unsigned int digit, int letter_case)
{
	int				len;
	int				counter;
	char			*result;
	unsigned long	digit_cpy;

	len = 0;
	counter = count_size(digit);
	digit_cpy = digit;
	if (digit != 0)
	{
		result = (char *)malloc(sizeof(char) * (counter + 1));
		if (!result)
			return (len);
		result[counter] = '\0';
		fill_result(result, counter, digit, letter_case);
		len += ft_print_str(result);
		free(result);
	}
	else
		len += ft_print_str("0");
	return (len);
}
