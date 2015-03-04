/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfournet <pfournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 23:09:01 by pfournet          #+#    #+#             */
/*   Updated: 2014/11/13 10:02:16 by pfournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;
	t_list		*next;

	tmp = *alst;
	while (tmp->next != NULL)
	{
		(*del)(tmp->content, tmp->content_size);
		next = tmp->next;
		free(tmp);
		tmp = next;
		alst = NULL;
	}
}
