/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:41:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/27 11:23:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_node **stk_a, t_node **stk_b, int stk_size);
static void	five_sort(t_node **stk_a, t_node **stk_b, int stk_size);
static void	push_min(t_node **stk_a, t_node **stk_b);

void	small_sort(t_node **stk_a, t_node **stk_b)
{
	int	stk_size;

	if (is_sorted(*stk_a) && is_sorted(*stk_b))
		return ;
	stk_size = count_lst(*stk_a);
	if (stk_size > 5)
		return ;
	else if (stk_size > 3)
		five_sort(stk_a, stk_b, stk_size);
	else if (stk_size > 0)
		three_sort(stk_a, stk_b, stk_size);
	return ;
}

static void	three_sort(t_node **stk_a, t_node **stk_b, int stk_size)
{
	if (is_sorted(*stk_a))
		return ;
	if ((*stk_a)->index == stk_size - 1)
		rotate('a', stk_a, stk_b);
	if ((*stk_a)->next->index == stk_size - 1)
		rev_rotate('a', stk_a, stk_b);
	if ((*stk_a)->index == stk_size - 2)
		swap('a', stk_a, stk_b);
	return ;
}

static void	five_sort(t_node **stk_a, t_node **stk_b, int stk_size)
{
	if (is_sorted(*stk_a))
		return ;
	push_min(stk_a, stk_b);
	three_sort(stk_a, stk_b, stk_size);
	if ((*stk_b)->index == 0)
		swap('b', stk_a, stk_b);
	push('a', stk_a, stk_b);
	push('a', stk_a, stk_b);
	return ;
}

static void	push_min(t_node **stk_a, t_node **stk_b)
{
	int	push_cnt;

	push_cnt = 0;
	while (push_cnt < 2)
	{
		if ((*stk_a)->index == 0 || (*stk_a)->index == 1)
		{
			push('b', stk_a, stk_b);
			push_cnt++;
		}
		else
			rotate('a', stk_a, stk_b);
	}
	return ;
}
