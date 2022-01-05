/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:11:59 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:00:32 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_len(int *digits, long int num)
{
	if (num == 0)
		*digits = 1;
	else
	{
		while (num)
		{
			num = num / 10;
			*digits += 1;
		}
	}
}

static char	*recursive_fill_result(char *s, long int n)
{
	if (n / 10 > 0)
		s = recursive_fill_result(s, n / 10);
	*s = n % 10 + '0';
	return (++s);
}

char	*ft_itoa(int n)
{
	long int	num;
	int			is_neg;
	char		*result;
	int			digits;

	is_neg = 0;
	digits = 0;
	if (n < 0)
	{
		is_neg++;
		digits++;
		num = (long)n * -1;
	}
	else
		num = n;
	ft_len(&digits, num);
	result = (char *)malloc((digits + 1) * sizeof(char));
	if (!result)
		return (0);
	if (n < 0)
		*result = '-';
	recursive_fill_result(&result[is_neg], num);
	result[digits] = '\0';
	return (result);
}
