/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:45:00 by oldurosi          #+#    #+#             */
/*   Updated: 2019/11/18 15:51:52 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

int		ft_lstlen(t_list *list)
{
	int len;

	len = 0;
	while (list && list->content)
	{
		list = list->next;
		++len;
	}
	return (len);
}
