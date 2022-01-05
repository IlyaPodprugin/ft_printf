/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:12:48 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:13:33 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		big_;
	size_t		little_;

	if (big == NULL && little == NULL)
		return (NULL);
	if (!little[0])
		return ((char *)big);
	big_ = 0;
	while (big[big_] && big_ < len)
	{
		little_ = 0;
		while (big[big_ + little_] && little[little_]
			&& big_ + little_ < len && big[big_ + little_] == little[little_])
			little_++;
		if (!little[little_])
			return ((char *)big + big_);
		big_++;
	}
	return (NULL);
}
