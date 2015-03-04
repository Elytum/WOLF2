/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 09:52:35 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/13 10:02:46 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*new;
	t_list	*prev;

	ret = NULL;
	ret = (*f)(lst);
	prev = ret;
	lst = lst->next;
	while (lst->next != NULL)
	{
		new = (*f)(lst);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	prev->next = NULL;
	return (ret);
}
