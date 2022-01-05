/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:42:50 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 22:03:20 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	size_t	mem;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	mem = num * size;
	if (!mem || (size && num > 2147483647 / size))
		return (NULL);
	p = (void *)malloc(mem);
	if (!p)
		return (NULL);
	ft_bzero(p, mem);
	return (p);
}
