/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:37:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/27 11:46:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_max(t_node *stk, int *pos);
static void		push_max_toa(t_node **stk_a, t_node **stk_b);

void	push_max(t_node **stk_a, t_node **stk_b)
{
	while (*stk_b)
		push_max_toa(stk_a, stk_b);
	return ;
}

static void	push_max_toa(t_node **stk_a, t_node **stk_b)
{
	int		stk_size;
	t_node	*max_node;
	int		pos;

	stk_size = count_lst(*stk_b);
	max_node = find_max(*stk_b, &pos);
	while (1)
	{
		if (max_node->index == (*stk_b)->index)
			break ;
		if (max_node->index == (*stk_b)->next->index)
		{
			swap('b', stk_a, stk_b);
			break ;
		}
		if (pos < stk_size / 2)
			rotate('b', stk_a, stk_b);
		else
			rev_rotate('b', stk_a, stk_b);
	}
	push('a', stk_a, stk_b);
}

static t_node	*find_max(t_node *stk, int *pos)
{
	t_node	*max_node;
	int		i;

	max_node = stk;
	i = 0;
	while (stk)
	{
		if (max_node->val < stk->val)
		{
			max_node = stk;
			*pos = i;
		}
		stk = stk->next;
		i++;
	}
	return (max_node);
}
