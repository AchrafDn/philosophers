/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:18:03 by adadoun           #+#    #+#             */
/*   Updated: 2023/07/26 03:18:04 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_res(int signe)
{
	if (signe > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		p;
	size_t	res;

	res = 0;
	p = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - 48);
		if (res > 9223372036854775807)
			return (ft_res(p));
		i++;
	}
	return (res * p);
}
