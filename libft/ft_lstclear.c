/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosada <mosada@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:24:50 by mosada            #+#    #+#             */
/*   Updated: 2023/10/06 11:20:52 by mosada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*now;
	t_list	*new;

	if (!lst || !del)
		return ;
	now = *lst;
	while (now)
	{
		new = now->next;
		del(now->content);
		free(now);
		now = new;
	}
	*lst = NULL;
}
