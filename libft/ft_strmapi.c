/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:45:07 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:32:48 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*result;
	size_t		index;
	size_t		len;

	if (s == NULL)
		return (0);
	len = ft_strlen((char *)s);
	index = 0;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = 0;
	return (result);
}
