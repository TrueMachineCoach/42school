/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bandrow <bandrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:05:56 by bandrow           #+#    #+#             */
/*   Updated: 2019/09/18 17:48:25 by bandrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count_elem(char *str, char c)
{
	int in_word;
	int count_elem;

	count_elem = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (!in_word)
		{
			count_elem++;
			in_word = 1;
		}
		str++;
	}
	return (count_elem);
}

static int		*ft_size_words(char *str, char c, int elems)
{
	int		*result;
	int		j;
	int		len_word;

	result = (int*)malloc(sizeof(int) * elems);
	len_word = 0;
	if (result)
	{
		j = 0;
		while (*str)
		{
			if (*str == c)
			{
				if (len_word)
					result[j++] = len_word;
				len_word = 0;
			}
			else
				len_word++;
			str++;
		}
	}
	if (len_word)
		result[j] = len_word;
	return (result);
}

static	int		ft_fill_strs(const char *s, char c, char **arr, int *size_words)
{
	int		k;
	int		j;
	size_t	i;

	j = 0;
	i = 0;
	while (s[i])
		if (s[i] != c)
		{
			k = 0;
			*(arr + j) = (char*)malloc((size_words[j] + 1) * sizeof(char));
			if (arr[j])
			{
				while (k < size_words[j])
					arr[j][k++] = s[i++];
				arr[j++][k] = '\0';
			}
			else
				return (0);
		}
		else
			i++;
	arr[j] = 0;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		*size_words;
	int		status;
	int		i;

	arr = 0;
	if (s && c)
	{
		size_words = ft_size_words((char*)s, c, ft_count_elem((char*)s, c) + 1);
		arr = (char**)malloc((ft_count_elem((char*)s, c) + 1) * sizeof(char*));
		if (arr)
		{
			status = ft_fill_strs(s, c, arr, size_words);
			if (!status)
			{
				i = 0;
				while (arr[i])
					free(arr[i++]);
				free(arr);
				arr = 0;
			}
		}
	}
	return (arr);
}
