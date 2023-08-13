/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:18:15 by adadoun           #+#    #+#             */
/*   Updated: 2023/07/26 03:18:16 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_num(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] > 57 || num[i] < 48)
			return (0);
		i++;
	}
	return (1);
}

int	parssing(int ac, char **av)
{
	int	num;
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (0);
	while (i < ac)
	{
		if (check_num(av[i]) != 1)
			return (0);
		num = ft_atoi(av[i++]);
		if (num <= 0)
			return (0);
	}
	return (1);
}

void	ft_sleep(long mili_sec)
{
	struct timeval	after_t;
	struct timeval	before_t;
	long			time;

	gettimeofday(&before_t, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&after_t, NULL);
		time = (after_t.tv_sec * 1000 + after_t.tv_usec / 1000)
			- (before_t.tv_sec * 1000 + before_t.tv_usec / 1000);
		if (mili_sec <= time)
			break ;
	}
}

void	get_data(char **av, t_data *data)
{
	data->philo_num = ft_atoi(av[1]);
	data->die_time = ft_atoi(av[2]);
	data->eat_time = ft_atoi(av[3]);
	data->sleep_time = ft_atoi(av[4]);
	if (av[5])
		data->meal_num = ft_atoi(av[5]);
}

void	init_struct(char **av, t_data *data)
{
	int	i;

	i = 0;
	data->index = 0;
	data->meal_num = -1;
	get_data(av, data);
	data->philo = malloc(sizeof(t_philo) * data->philo_num);
	data->lock = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	while (i < data->philo_num)
		pthread_mutex_init(&data->lock[i++], NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meal_time_mutex, NULL);
	pthread_mutex_init(&data->n_meal, NULL);
	i = -1;
	while (++i < data->philo_num)
	{
		data->philo[i].id = i + 1;
		data->philo[i].n_meals = 0;
		data->philo[i].data = data;
		data->philo[i].l_meal_time = get_time();
	}
}
