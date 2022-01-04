/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 06:25:16 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 06:25:47 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_digit(int digit)
{
	int		len;
	char	*result;

	len = 0;
	result = ft_itoa(digit);
	len += ft_print_str(result);
	free(result);
	return (len);
}
