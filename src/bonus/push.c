/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:09:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 20:29:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push_node(t_node **src_stk, t_node **dest_stk);

void	push(char c, t_node **stk_a, t_node **stk_b)
{
	if (c == 'a' && *stk_b)
		push_node(stk_b, stk_a);
	else if (c == 'b' && *stk_a)
		push_node(stk_a, stk_b);
	return ;
}

static void	push_node(t_node **src_stk, t_node **dest_stk)
{
	t_node	*tmp;

	tmp = *src_stk;
	*src_stk = tmp->next;
	tmp->next = *dest_stk;
	*dest_stk = tmp;
}
