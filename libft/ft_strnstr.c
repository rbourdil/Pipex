/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:50:31 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 15:52:49 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_needle(const char *haystack, const char *needle, size_t len)
{
	while (*haystack != '\0' && *needle != '\0' && len > 0)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		len--;
	}
	if (*needle == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			if (check_needle(haystack, needle, len))
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
