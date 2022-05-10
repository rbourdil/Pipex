/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:08:43 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 11:07:16 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*b2;
	const unsigned char	c2 = c;

	b2 = b;
	while (len > 0)
	{
		*b2 = c2;
		b2++;
		len--;
	}
	return (b);
}
