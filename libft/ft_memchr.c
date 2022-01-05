/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:22:09 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:13:33 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)arr == (unsigned char)c)
			return ((void *)arr);
		arr++;
		n--;
	}
	return (0);
}
