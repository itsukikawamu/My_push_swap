/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:40:05 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/24 07:48:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}	t_node;

// validate.c
void	validate(int ac, char *av[]);
// set_stack.c
t_node	*set_stack(int ac, char *av[]);
// is_sorted.c
bool	is_sorted(t_node *stk);
// small_sort.c
void	small_sort(t_node **stk_a, t_node **stk_b);
// sort_by_range.c
void	sort_by_range(t_node **stk_a, t_node **stk_b, int range);
// push_from_max.c
void	push_max(t_node **stk_a, t_node **stk_b);
// uitls.c
void	lstadd_back(t_node **lst, t_node *new);
void	lstclear(t_node **lst);
t_node	*lstlast(t_node *lst);
int		count_lst(t_node *lst);
// push.c
void	push(char c, t_node **stk_a, t_node **stk_b);
// swap.c
void	swap(char c, t_node **stk_a, t_node **stk_b);
// rotate.c
void	rotate(char c, t_node **stk_a, t_node **stk_b);
// reverse_rotate.c
void	rev_rotate(char c, t_node **stk_a, t_node **stk_b);
// ft_atol.c
long	ft_atol(const char *nptr);

#endif