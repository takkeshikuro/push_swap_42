/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorikaw <tmorikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:45:57 by tmorikaw          #+#    #+#             */
/*   Updated: 2023/02/17 05:03:14 by tmorikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*ft_substr(const char *s, int start, int len)
{
	char		*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (len != 0)
		ft_strlcpy(str, s + start, len + 1);
	else
		*str = 0;
	return (str);
}

static char	**free_all(char **tab, int nbcase)
{
	int	i;

	i = 0;
	while (i < nbcase)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_nbstr(char const *str, char sep)
{
	int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			nbword++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (nbword);
}

static char	*words(const char *s, char sep)
{
	int		j;
	char	*word;

	j = 0;
	while (s[j] && s[j] != sep)
		j++;
	word = ft_substr(s, 0, j);
	if (!word)
		return (NULL);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*word;
	int		i;
	int		nbstr;

	if (s == NULL)
		return (NULL);
	nbstr = ft_nbstr(s, c);
	i = 0;
	array = malloc(sizeof(char *) * (nbstr + 1));
	if (!array)
		return (NULL);
	while (*s && i < nbstr)
	{
		while (*s && *s == c)
			s++;
		word = words(s, c);
		if (!word)
			return (free_all(array, i));
		s = s + ft_strlen(word);
		array[i++] = word;
	}
	array[nbstr] = 0;
	return (array);
}
