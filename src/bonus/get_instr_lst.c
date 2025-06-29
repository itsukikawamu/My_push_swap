/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instr_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:58:57 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 13:36:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		instradd_back(t_instr **lst, t_instr *new);
static int		get_instr_enum(char *instr);

int	get_instr_lst(t_instr *lst)
{
	char	*instr;
	t_instr	*new;

	lst = NULL;
	while (1)
	{
		instr = get_next_line(0);
		if (!instr)
			break ;
		new = malloc(sizeof(t_instr));
		new->num = get_instr_enum(instr);
		new->next = NULL;
		if (new->num == -1)
		{
			free(instr);
			free(new);
			return (-1);
		}
		instradd_back(&lst, new);
		free(instr);
	}
	return (0);
}

static int	get_instr_enum(char *instr)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		return (SA);
	if (ft_strcmp(instr, "sb\n") == 0)
		return (SB);
	if (ft_strcmp(instr, "ss\n") == 0)
		return (SS);
	if (ft_strcmp(instr, "pa\n") == 0)
		return (PA);
	if (ft_strcmp(instr, "pb\n") == 0)
		return (PB);
	if (ft_strcmp(instr, "ra\n") == 0)
		return (RA);
	if (ft_strcmp(instr, "rb\n") == 0)
		return (RB);
	if (ft_strcmp(instr, "rr\n") == 0)
		return (RR);
	if (ft_strcmp(instr, "rra\n") == 0)
		return (RRA);
	if (ft_strcmp(instr, "rrb\n") == 0)
		return (RRB);
	if (ft_strcmp(instr, "rrr\n") == 0)
		return (RRR);
	return (-1);
}

static void	instradd_back(t_instr **lst, t_instr *new)
{
	t_instr	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while ((last)->next)
		last = (last)->next;
	(last)->next = new;
}
