/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:42:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 22:17:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	index_nodes(t_node *stk);

t_node	*set_stack(int ac, char *av[])
{
	t_node	*stk;
	t_node	*new;
	int		i;

	stk = NULL;
	i = 1;
	while (i < ac)
	{
		new = malloc(sizeof(t_node));
		new->val = ft_atoi(av[i]);
		new->index = -1;
		new->next = NULL;
		lstadd_back(&stk, new);
		i++;
	}
	index_nodes(stk);
	return (stk);
}

static void	index_nodes(t_node *stk)
{
	t_node	*cur;
	t_node	*cmp;
	int		idx;

	cur = stk;
	while (cur)
	{
		idx = 0;
		cmp = stk;
		while (cmp)
		{
			if (cur->val > cmp->val)
				idx++;
			cmp = cmp->next;
		}
		cur->index = idx;
		cur = cur->next;
	}
	return ;
}
