/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:41:39 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/06/19 11:41:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static int	issign(int c);

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		sign;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (issign(nptr[i]))
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

static int	issign(int c)
{
	if (c == '+' || c == '-')
		return (FT_ISSIGN);
	return (0);
}

static int	ft_isspace(int c)
{
	if ((c == ' ') || (9 <= c && c <= 13))
		return (FT_ISSPACE);
	return (0);
}

/*s
#include <stdlib.h>
int main(void)
{
	printf("%d\n",atoi("9223372036854775808"));
	printf("%d\n",ft_atoi("9223372036854775808"));
}
*/