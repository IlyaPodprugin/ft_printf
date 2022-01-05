/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:58:39 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:13:33 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)arr1 != *(unsigned char *)arr2)
			return (*(unsigned char *)arr1 - *(unsigned char *)arr2);
		arr1++;
		arr2++;
		n--;
	}
	return (0);
}
