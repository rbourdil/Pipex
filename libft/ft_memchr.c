/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:40:51 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 15:40:57 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	c2 = c;
	const unsigned char	*s2 = s;

	while (n > 0)
	{
		if (*s2 == c2)
			return ((void *)s2);
		s2++;
		n--;
	}
	return (0);
}
