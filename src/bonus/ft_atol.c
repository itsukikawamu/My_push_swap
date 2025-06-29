/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 05:10:21 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 05:44:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c);
static int	is_sign(int c);

long	ft_atol(const char *nptr)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (is_sign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0') * sign;
		i++;
	}
	return (result);
}

static int	is_sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if ((c == ' ') || (9 <= c && c <= 13))
		return (1);
	return (0);
}
