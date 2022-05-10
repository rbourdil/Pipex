/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:29:38 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 18:17:41 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	size1;
	unsigned int	size2;
	unsigned int	i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = malloc(sizeof(char) * (size1 + size2 + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		ret[i] = s2[i - size1];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
