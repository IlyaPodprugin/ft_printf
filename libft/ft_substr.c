/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 23:39:25 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:33:10 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		ctr;
	size_t		len_s;

	if (s == NULL)
		return (NULL);
	ctr = 0;
	len_s = ft_strlen((char *)s);
	if (len_s < len)
		len = len_s;
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (*s && ctr <= start)
	{
		if (ctr == start)
		{
			ft_strlcpy(str, s, len + 1);
			return (str);
		}
		s++;
		ctr++;
	}
	ft_bzero(str, len);
	return (str);
}
