/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:31:17 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:33:00 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		end;
	size_t		start;
	size_t		ctr;

	if (s1 == NULL || set == NULL)
		return ("");
	ctr = 0;
	start = 0;
	end = ft_strlen((char *)s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > 0 && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	if (*s1 == '\0' || (int)end == 0)
		start = 0;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[start] && start < end)
		str[ctr++] = s1[start++];
	str[ctr] = 0;
	return (str);
}
