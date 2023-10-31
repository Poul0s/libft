/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:44:36 by psalame           #+#    #+#             */
/*   Updated: 2023/10/30 20:07:07 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_get_nb_words(char const *s, char c)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				nb++;
		}
		i++;
	}
	return (nb);
}

static int	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free_tab_tab(char **res)
{
	size_t	i;

	i = 0;
	while (res[i] != 0)
		free(res[i++]);
	free(res);
}

static char	**ft_fill_res(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
			{
				res[j] = malloc((ft_wordlen(s + i, c) + 1) * sizeof(char));
				if (res[j++] == NULL)
				{
					ft_free_tab_tab(res);
					return (NULL);
				}
				k = 0;
			}
			res[j - 1][k++] = s[i];
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	nb_words;
	size_t	i;

	nb_words = ft_get_nb_words(s, c);
	if (nb_words == 0)
	{
		res = malloc(sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	res = malloc((nb_words + 1) * sizeof(char *));
	if (res == NULL)
		return (res);
	i = 0;
	while (i < nb_words + 1)
		res[i++] = NULL;
	return (ft_fill_res(s, c, res));
}
