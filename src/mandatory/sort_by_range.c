/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:37:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/27 11:37:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_range(t_node **stk_a, t_node **stk_b, int range)
{
	int	i;

	i = 0;
	while (*stk_a)
	{
		if ((*stk_a)->index <= i)
		{
			push('b', stk_a, stk_b);
			i++;
		}
		else if ((*stk_a)->index <= i + range)
		{
			push('b', stk_a, stk_b);
			rotate('b', stk_a, stk_b);
			i++;
		}
		else
			rotate('a', stk_a, stk_b);
	}
	return ;
}
