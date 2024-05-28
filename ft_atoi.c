/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibes-sed <ibes-sed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:59:11 by ibes-sed          #+#    #+#             */
/*   Updated: 2024/05/28 02:56:51 by ibes-sed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
static int	ft_overf(void)
{
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	r;

	i = 0;
	s = 0;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - '0');
		i++;
		if (r > (unsigned long)INT_MAX + 1)
		{
			return (ft_overf());
		}
	}
	if (s % 2 == 0)
	{
		if (r > (unsigned long)INT_MAX)
			return (ft_overf());
		return ((int)r);
	}
	if (r > (unsigned long)INT_MAX + 1)
		return (ft_overf());
	return ((int)-r);
}
