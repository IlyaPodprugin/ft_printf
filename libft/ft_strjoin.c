/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:53:57 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:32:39 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;
	size_t		ctr;

	if (s1 == NULL || s2 == NULL)
		return (0);
	ctr = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (str)
	{
		while (*s1)
			str[ctr++] = *s1++;
		while (*s2)
			str[ctr++] = *s2++;
		str[ctr] = 0;
		return (str);
	}
	return (0);
}
