/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:49:54 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:32:14 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	i = 0;
	if (src < dst)
		while (i++ < n)
			dst[n - i] = src[n - i];
	else
		ft_memcpy(destination, source, n);
	return (destination);
}
