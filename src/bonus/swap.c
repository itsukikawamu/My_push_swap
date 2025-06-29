/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:45:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 20:29:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_node(t_node **stk);

void	swap(char c, t_node **stk_a, t_node **stk_b)
{
	if ((c == 'a' || c == 's') && *stk_a && (*stk_a)->next)
		swap_node(stk_a);
	if ((c == 'b' || c == 's') && *stk_b && (*stk_b)->next)
		swap_node(stk_b);
	return ;
}

static void	swap_node(t_node **stk)
{
	t_node	*first;
	t_node	*second;

	first = *stk;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stk = second;
	return ;
}
