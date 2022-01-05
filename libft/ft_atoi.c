/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:20:14 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/12 23:14:09 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_rules(long long result, char ch, int *sign_cnt)
{
	if (((ch >= 9 && ch <= 13)
			|| ch == '+' || ch == '-' || ch == ' ')
		&& result == 0 && *sign_cnt < 1)
		return (1);
	return (0);
}

static void	ft_iterate_signs(char ch, int *sign_cnt, int *sign)
{
	if (ch == '-' || ch == '+')
		*sign_cnt += 1;
	if (ch == '-')
		*sign = -*sign;
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			sign_cnt;

	result = 0;
	sign_cnt = 0;
	sign = 1;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if ((result * 10 + *str - '0') * sign > 2147483647)
				return (-1);
			else if ((result * 10 + *str - '0') * sign < -2147483647 - 1)
				return (0);
			result = result * 10 + *str - '0';
		}
		else if (ft_check_rules(result, *str, &sign_cnt))
			ft_iterate_signs(*str, &sign_cnt, &sign);
		else
			break ;
		str++;
	}
	return ((int)result * sign);
}
