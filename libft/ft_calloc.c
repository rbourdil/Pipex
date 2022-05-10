/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:34:50 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:06:39 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (count * size));
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}	
	return (ptr);
}
