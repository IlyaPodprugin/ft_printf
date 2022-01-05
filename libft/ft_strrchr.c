/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:10:23 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/14 17:01:23 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;

	len = ft_strlen((char *)str);
	if (!ch)
		return ((char *)str + len);
	while (len)
	{
		if (str[len - 1] == (char)ch)
			return ((char *)str + len - 1);
		len--;
	}
	return (NULL);
}
