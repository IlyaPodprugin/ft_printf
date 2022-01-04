/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:16:51 by rtinisha          #+#    #+#             */
/*   Updated: 2022/01/04 03:40:49 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_option	*init_flags(t_option *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->star = 0;
	return (flags);
}

int	ft_print_char(int char_to_print)
{
	write(1, &char_to_print, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		ft_print_char(str[len++]);
	return (len);
}

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

// static long int	ft_abs(long int num)
// {
// 	if (num < 0)
// 		return (-num);
// 	return (num);
// }

int	ft_print_digit(int digit)
{
	int		len;
	int		counter;
	char	*result;
	int		digit_cpy;

	len = 0;
	counter = 0;
	if (digit < 0)
	{
		len += ft_print_char('-');
		digit = -digit;
	}
	digit_cpy = digit;
	while (digit_cpy)
	{
		digit_cpy /= 10;
		counter++;
	}
	result = (char *)malloc(sizeof(char) * counter + 1);
	if (!result)
		return (len);
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

int	ft_define_conversion(va_list args, const char *str, int i)
{
	int	len;

	len = 0;
	if (str[i] == 'c')
		len = ft_print_char(va_arg(args, int));
	if (str[i] == 's')
		len = ft_print_str(va_arg(args, char *));
	if (str[i] == 'p')
		len = ft_print_ptr(va_arg(args, unsigned long));
	if (str[i] == 'd')
		len = ft_print_digit(va_arg(args, int));
	// if (str[i] == 'i')
	// 	len = ft_print_char(va_arg(args, int));
	// if (str[i] == 'u')
	// 	len = ft_print_char(va_arg(args, unsigned int));
	// if (str[i] == 'x')
	// 	len = ft_print_char(va_arg(args, unsigned int));
	// if (str[i] == 'X')
	// 	len = ft_print_char(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	// t_print	*flags;
	int		len;
	int		i;

	len = 0;
	i = 0;

	va_list	args;
	va_start(args, str);
	// len = parse_input(args, str);
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

// int	main(void)
// {
// 	// void	*ptr;

// 	// // ptr = (char *)&"world";
// 	// ptr = &"world";
// 	// printf("%d\n", ft_printf("Hello %c\n", 'w'));
// 	// printf("%d\n", ft_printf("Hello %s\n", "world"));
// 	// printf("%d\n", ft_printf("myne: Hello %p\n", ptr));
// 	// printf("%d\n", printf("syst: Hello %p\n", ptr));
// 	printf("%d\n", ft_printf("myne: Hello %d\n", 2147483648));
// 	printf("%d\n", printf("syst: Hello %ld\n", 2147483648));
// 	return (0);
// }
