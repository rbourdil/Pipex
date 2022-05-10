/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:52:11 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:20:49 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		size;
	int		i;

	while (in_set(*s1, set))
		s1++;
	size = ft_strlen(s1);
	while (size && in_set(s1[size - 1], set))
		size--;
	trimmed = malloc(sizeof(char) * (size + 1));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		trimmed[i] = s1[i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
