/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:37:31 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/27 11:46:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_range(int stk_size);

int	main(int ac, char *av[])
{
	t_node	*stk_a;
	t_node	*stk_b;
	int		range;

	validate(ac, av);
	stk_a = set_stack(ac, av);
	stk_b = NULL;
	if (!is_sorted(stk_a) && !stk_b)
		small_sort(&stk_a, &stk_b);
	if (!is_sorted(stk_a) && !stk_b)
	{
		range = set_range(ac - 1);
		sort_by_range(&stk_a, &stk_b, range);
		push_max(&stk_a, &stk_b);
	}
	lstclear(&stk_a);
	return (0);
}

static int	set_range(int stk_size)
{
	if (stk_size <= 100)
		return (10);
	if (stk_size <= 200)
		return (15);
	if (stk_size <= 300)
		return (20);
	if (stk_size <= 400)
		return (25);
	return (30);
}
