/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:30:42 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 17:49:17 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		totlen;
	size_t		dlen;
	char		*d;
	const char	*s;

	totlen = dstsize;
	d = dst;
	s = src;
	while (totlen > 0 && *d != '\0')
	{
		totlen--;
		d++;
	}
	dlen = d - dst;
	if (totlen == 0)
		return (dstsize + ft_strlen(src));
	while (totlen > 1 && *s != '\0')
	{
		*d = *s;
		d++;
		s++;
		totlen--;
	}
	*d = '\0';
	return (dlen + ft_strlen(src));
}
