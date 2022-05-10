/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:38 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:33:02 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*to;
	const char	*from = src;

	if (dst == NULL && src == NULL)
		return (NULL);
	to = dst;
	if (to > from && to < (from + len))
	{
		to += len - 1;
		from += len - 1;
		while (len > 0)
		{
			*to = *from;
			to--;
			from--;
			len--;
		}
	}
	else
		ft_memcpy(to, from, len);
	return (dst);
}
