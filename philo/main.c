/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:19:12 by adadoun           #+#    #+#             */
/*   Updated: 2023/07/26 03:19:14 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock[philo->id % philo->data->philo_num]);
	print_str(philo, "has taken a fork", 0);
	pthread_mutex_lock(&philo->data->lock[philo->id - 1]);
	print_str(philo, "has taken a fork", 0);
	print_str(philo, "is eating", 0);
	ft_sleep(philo->data->eat_time);
	pthread_mutex_lock(&philo->data->n_meal);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->data->n_meal);
	pthread_mutex_lock(&philo->data->meal_time_mutex);
	philo->l_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_time_mutex);
	pthread_mutex_unlock(&philo->data->lock[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->lock[philo->id
		% philo->data->philo_num]);
}

void	*routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		eating(ph);
		print_str(ph, "is sleeping", 0);
		ft_sleep(ph->data->sleep_time);
		print_str(ph, "is thinking", 0);
	}
	return (NULL);
}

int	run_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->t[i], NULL, &routine, &data->philo[i]) != 0)
			return (1);
		usleep(30);
		i += 2;
	}
	i = 1;
	while (i < data->philo_num)
	{
		if (pthread_create(&data->t[i], NULL, &routine, &data->philo[i]) != 0)
			return (1);
		usleep(20);
		i += 2;
	}
	return (0);
}

int	ft_check(t_data *data, char **av)
{
	int	i;

	while (1)
	{
		if (av[5] != NULL)
		{
			if (check_meals(data) == 1)
				return (1);
		}
		i = -1;
		while (++i < data->philo_num)
		{
			pthread_mutex_lock(&data->meal_time_mutex);
			if (get_time() - data->philo[i].l_meal_time >= data->die_time)
			{
				print_str(&data->philo[i], "died", 1);
				return (1);
			}
			pthread_mutex_unlock(&data->meal_time_mutex);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data			*data;
	int				i;

	i = 0;
	data = malloc(sizeof(t_data));
	data->start_time = get_time();
	if (parssing(ac, av) == 0)
	{
		printf("Please enter a valid arguments\n");
		return (1);
	}
	init_struct(av, data);
	if (run_philo(data) != 0)
		return (1);
	if (ft_check(data, av) == 1)
		return (0);
	return (0);
}
