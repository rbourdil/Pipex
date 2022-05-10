/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:51:58 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 17:49:48 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*pos;
	const char	c2 = c;

	pos = (char *)s;
	while (*s != '\0')
	{
		if (*s == c2)
			pos = (char *)s;
		s++;
	}
	if (*s == c2)
		return ((char *)s);
	else if (*pos != c2)
		return (NULL);
	else
		return (pos);
}	
