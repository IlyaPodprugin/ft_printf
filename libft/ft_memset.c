/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:40 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:13:33 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	sym;

	ptr = (unsigned char *)destination;
	sym = (unsigned char)c;
	while (n--)
		*ptr++ = sym;
	return (destination);
}
