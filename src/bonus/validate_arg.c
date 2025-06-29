/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 05:00:09 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/28 13:32:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_all_num(int ac, char *av[]);
static bool	is_all_int(int ac, char *av[]);
static bool	is_no_dup(int ac, char *av[]);

void	validate_arg(int ac, char *av[])
{
	if (ac == 1)
		exit(1);
	if (!is_all_num(ac, av) || !is_all_int(ac, av) || !is_no_dup(ac, av))
	{
		ft_putstr_fd("Error\n", 2);
		exit(2);
	}
	return ;
}

static bool	is_no_dup(int ac, char *av[])
{
	int	i1;
	int	i2;
	int	*arr;

	arr = ft_calloc(ac - 1, sizeof(int));
	if (!arr)
		exit(1);
	i1 = 1;
	while (i1 < ac)
	{
		arr[i1 - 1] = ft_atoi(av[i1]);
		i2 = 0;
		while (i2 < i1 - 1)
		{
			if (arr[i1 - 1] == arr[i2])
			{
				free(arr);
				return (false);
			}
			i2++;
		}
		i1++;
	}
	free(arr);
	return (true);
}

static bool	is_all_int(int ac, char *av[])
{
	int		i;
	long	val;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 11)
			return (false);
		val = ft_atol(av[i]);
		if (val < INT_MIN || INT_MAX < val)
			return (false);
		i++;
	}
	return (true);
}

static bool	is_all_num(int ac, char *av[])
{
	int	i1;
	int	i2;

	i1 = 1;
	while (i1 < ac)
	{
		i2 = 0;
		if (av[i1][i2] == '-' || av[i1][i2] == '+')
			i2++;
		if (av[i1][i2] == '\0')
			return (false);
		while (av[i1][i2])
		{
			if (av[i1][i2] < '0' || '9' < av[i1][i2])
				return (false);
			i2++;
		}
		i1++;
	}
	return (true);
}
