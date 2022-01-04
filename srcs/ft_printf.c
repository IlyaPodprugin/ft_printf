/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:16:51 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 18:49:33 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_define_conversion(va_list args, const char *str, int i)
{
	int	len;

	len = 0;
	if (str[i] == 'c')
		len = ft_print_char(va_arg(args, int));
	if (str[i] == '%')
		len = ft_print_char('%');
	if (str[i] == 's')
		len = ft_print_str(va_arg(args, char *));
	if (str[i] == 'p')
		len = ft_print_ptr(va_arg(args, unsigned long));
	if (str[i] == 'd' || str[i] == 'i')
		len = ft_print_digit(va_arg(args, int));
	if (str[i] == 'x' || str[i] == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), str[i]);
	if (str[i] == 'u')
		len = ft_print_uint(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_define_conversion(args, str, ++i);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
