/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtinisha <rtinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:39:24 by rtinisha          #+#    #+#             */
/*   Updated: 2021/11/13 18:32:29 by rtinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **result, size_t words)
{
	while (words)
	{
		free(result[words]);
		words--;
	}
	free(result);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	words;
	size_t	ctr;

	words = 0;
	ctr = 0;
	while (str[ctr])
	{
		if (str[ctr] != c)
		{
			words++;
			while (str[ctr] && str[ctr] != c)
				ctr++;
		}
		else
			ctr++;
	}
	return (words);
}

static char	**ft_split_(char **result, const char *str, char c)
{
	size_t	ctr;
	size_t	start;
	size_t	words;

	ctr = 0;
	start = 0;
	words = 0;
	while (str[ctr])
	{
		if (str[ctr] != c)
		{
			start = ctr;
			while (str[ctr] && str[ctr] != c)
				ctr++;
			result[words] = (char *)malloc((ctr - start + 1) * sizeof(char));
			if (!result[words])
				ft_free(result, words);
			ft_strlcpy(result[words], str + start, ctr - start + 1);
			words++;
		}
		else
			ctr++;
	}
	result[words] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_split_(result, s, c);
	return (result);
}
