/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 04:29:51 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 04:30:07 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	int				len;
	int				counter;
	char			*result;
	unsigned long	ptr_cpy;

	len = 0;
	counter = 0;
	ptr_cpy = ptr;
	len += ft_print_str("0x");
	if (ptr != 0)
	{
		while (ptr_cpy != 0)
		{
			ptr_cpy /= 16;
			counter++;
		}
		result = (char *)malloc(sizeof(char) * (counter + 1));
		if (!result)
			return (len);
		result[counter] = '\0';
		while (ptr != 0)
		{
			if (ptr % 16 >= 10)
				result[counter - 1] = ptr % 16 + 87;
			else
				result[counter - 1] = ptr % 16 + 48;
			ptr /= 16;
			counter--;
		}
		len += ft_print_str(result);
		free(result);
	}
	return (len);
}
