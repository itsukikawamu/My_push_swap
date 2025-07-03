/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:45:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/03 03:02:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

enum	e_instr
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_instr
{
	int				num;
	struct s_instr	*next;
}	t_instr;

// validate_arg.c
void	validate_arg(int ac, char *av[]);
// set_stack.c
t_node	*set_stack(int ac, char *av[]);
// get_instr_lst.c
int		get_instr_lst(t_instr **lst);
// excute_instr.c
void	excute_instr(t_node **stk_a, t_node **stk_b, t_instr *instr_lst);
// uitls.c
void	lstadd_back(t_node **lst, t_node *new);
void	lstclear(t_node **lst);
t_node	*lstlast(t_node *lst);
int		count_lst(t_node *lst);
int		ft_strcmp(const char *s1, const char *s2);
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