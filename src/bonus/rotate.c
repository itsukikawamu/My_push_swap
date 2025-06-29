/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:43:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 20:29:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate_node(t_node **stk);

void	rotate(char c, t_node **stk_a, t_node **stk_b)
{
	if ((c == 'a' || c == 'r') && *stk_a && (*stk_a)->next)
		rotate_node(stk_a);
	if ((c == 'b' || c == 'r') && *stk_b && (*stk_b)->next)
		rotate_node(stk_b);
}

static void	rotate_node(t_node **stk)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stk;
	*stk = tmp->next;
	tmp->next = NULL;
	tail = lstlast(*stk);
	tail->next = tmp;
	return ;
}
