/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:17:54 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 15:34:53 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
