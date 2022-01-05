/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:33:55 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/02 13:54:18 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_dup;

	str_dup = (char *)malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (str_dup)
		ft_strlcpy(str_dup, str, (ft_strlen((char *)str) + 1));
	return (str_dup);
}
