/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:50:15 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:32:46 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*to;
	const char	*from = src;

	if (dst == NULL && src == NULL)
		return (NULL);
	to = dst;
	while (n > 0)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	return (dst);
}
