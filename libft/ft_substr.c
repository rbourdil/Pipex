/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:53:29 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:32:07 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (start > ft_strlen(s))
	{
		new = malloc(sizeof(char) * 1);
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (ft_strlen(s) < len)
		new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
