/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:43:06 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 20:42:28 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(long int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		str[12];
	long int	num;
	int			len;

	num = ft_abs(n);
	len = 0;
	ft_bzero(str, 12);
	if (n == 0)
	{
		str[0] = '0';
		len++;
	}
	while (num)
	{
		str[len++] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[len++] = '-';
	while (str[len - 1] && len > 0)
	{
		ft_putchar_fd(str[len - 1], fd);
		len--;
	}
}
