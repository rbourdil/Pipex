/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:22:50 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/09 10:32:07 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	size_int(int n)
{
	int	size;

	size = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*nb_arr;

	neg = 0;
	if (n < 0)
		neg = 1;
	size = size_int(n) + neg;
	nb_arr = malloc(sizeof(char) * (size + 1));
	if (!nb_arr)
		return (0);
	if (neg)
		nb_arr[0] = '-';
	nb_arr[size] = '\0';
	while (size > neg)
	{
		nb_arr[size - 1] = (n % 10) * (1 - (2 * neg)) + '0';
		n /= 10;
		size--;
	}
	return (nb_arr);
}
