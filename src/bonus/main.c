/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:45:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 13:39:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	instr_clear(t_instr **lst);

int	main(int ac, char *av[])
{
	t_node	*stk_a;
	t_node	*stk_b;
	t_instr	*instr_lst;

	validate_arg(ac, av);
	stk_a = set_stack(ac, av);
	stk_b = NULL;
	instr_lst = NULL;
	if (get_instr_lst(instr_lst) == -1)
	{
		lstclear(&stk_a);
		instr_clear(&instr_lst);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	excute_instr(&stk_a, &stk_b, instr_lst);
	lstclear(&stk_a);
	instr_clear(&instr_lst);
	return (0);
}

static void	instr_clear(t_instr **lst)
{
	t_instr	*head;

	if (!lst)
		return ;
	while (*lst)
	{
		head = *lst;
		*lst = (*lst)->next;
		free(head);
	}
	lst = NULL;
}
