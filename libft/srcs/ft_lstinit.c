/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:37:20 by oldurosi          #+#    #+#             */
/*   Updated: 2019/11/18 15:50:58 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

t_list		*ft_lstinit(void *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (!node)
		return (0);
	node->next = NULL;
	if (!content)
	{
		node->content = 0;
		node->content_size = 0;
		return (node);
	}
	node->content = content;
	node->content = content_size;
	return (node);
}
