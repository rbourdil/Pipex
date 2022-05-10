/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:02 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:22:59 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*fs;

	size = ft_strlen(s);
	fs = malloc(sizeof(char) * (size + 1));
	if (fs == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		fs[i] = (*f)(i, s[i]);
		i++;
	}
	fs[i] = '\0';
	return (fs);
}
