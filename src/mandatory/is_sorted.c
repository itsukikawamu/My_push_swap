/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:38:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/24 00:38:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node *stk)
{
	t_node	*cur;

	cur = stk;
	while (cur && cur->next)
	{
		if ((cur->val) > (cur->next->val))
			return (false);
		cur = cur->next;
	}
	return (true);
}
