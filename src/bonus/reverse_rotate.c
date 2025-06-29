/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:43:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 20:29:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate_node(t_node **stk);

void	rev_rotate(char c, t_node **stk_a, t_node **stk_b)
{
	if ((c == 'a' || c == 'r') && *stk_a && (*stk_a)->next)
		rev_rotate_node(stk_a);
	if ((c == 'b' || c == 'r') && *stk_b && (*stk_b)->next)
		rev_rotate_node(stk_b);
}

static void	rev_rotate_node(t_node **stk)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	last = *stk;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stk;
	*stk = last;
}
