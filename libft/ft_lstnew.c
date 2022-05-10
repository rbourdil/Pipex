/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourdil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:52:01 by rbourdil          #+#    #+#             */
/*   Updated: 2021/12/14 16:54:27 by rbourdil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*plist;

	plist = malloc(sizeof(t_list) * 1);
	if (plist == NULL)
		return (NULL);
	plist->content = content;
	plist->next = NULL;
	return (plist);
}
