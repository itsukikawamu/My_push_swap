/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_instr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:21:00 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/03 03:03:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_sorted(t_node *stk);
static void	do_instr(t_node **stk_a, t_node **stk_b, t_instr instr);

void	excute_instr(t_node **stk_a, t_node **stk_b, t_instr *instr_lst)
{
	while (instr_lst)
	{
		do_instr(stk_a, stk_b, *instr_lst);
		instr_lst = instr_lst->next;
	}
	if (!is_sorted(*stk_a))
		ft_printf("KO\n");
	else if (*stk_b != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return ;
}

static bool	is_sorted(t_node *stk)
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

static void	do_instr(t_node **stk_a, t_node **stk_b, t_instr instr)
{
	if (instr.num == SA)
		swap('a', stk_a, stk_b);
	if (instr.num == SB)
		swap('b', stk_a, stk_b);
	if (instr.num == SS)
		swap('s', stk_a, stk_b);
	if (instr.num == PA)
		push('a', stk_a, stk_b);
	if (instr.num == PB)
		push('b', stk_a, stk_b);
	if (instr.num == RA)
		rotate('a', stk_a, stk_b);
	if (instr.num == RB)
		rotate('b', stk_a, stk_b);
	if (instr.num == RR)
		rotate('r', stk_a, stk_b);
	if (instr.num == RRA)
		rev_rotate('a', stk_a, stk_b);
	if (instr.num == RRB)
		rev_rotate('b', stk_a, stk_b);
	if (instr.num == RRR)
		rev_rotate('r', stk_a, stk_b);
	return ;
}
