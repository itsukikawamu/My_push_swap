/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:44:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 11:44:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	count_lst(t_node *lst)
{
	int	cnt;

	cnt = 0;
	if (!lst)
		return (cnt);
	cnt++;
	while (lst->next)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}

void	lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while ((last)->next)
		last = (last)->next;
	(last)->next = new;
}

void	lstclear(t_node **lst)
{
	t_node	*head;

	if (!lst)
		return ;
	while (*lst)
	{
		head = *lst;
		*lst = (*lst)->next;
		free(head);
	}
	lst = NULL;
}
