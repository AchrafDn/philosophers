/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:18:51 by adadoun           #+#    #+#             */
/*   Updated: 2023/07/26 03:18:52 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	print_str(t_philo *philo, char	*str, int i)
{
	long	time;

	pthread_mutex_lock(&philo->data->print);
	time = get_time() - philo->data->start_time;
	printf("%li %i %s\n ", time, philo->id, str);
	if (i != 1)
		pthread_mutex_unlock(&philo->data->print);
}

int	check_meals(t_data *data)
{
	int	j;
	int	i;

	i = -1;
	pthread_mutex_lock(&data->n_meal);
	j = 0;
	while (++i < data->philo_num)
	{
		if (data->philo[i].n_meals >= data->meal_num)
			j++;
	}
	pthread_mutex_unlock(&data->n_meal);
	if (j == data->philo_num)
	{
		pthread_mutex_lock(&data->print);
		return (1);
	}
	return (0);
}
