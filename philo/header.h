/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:18:39 by adadoun           #+#    #+#             */
/*   Updated: 2023/07/26 03:18:40 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_data;

typedef struct t_philo
{
	int								id;
	pthread_mutex_t					*r_fork;
	pthread_mutex_t					*l_fork;
	int								n_meals;
	long							l_meal_time;
	struct t_data					*data;

}									t_philo;

typedef struct t_data
{
	int								index;
	int								philo_num;
	long							die_time;
	long							eat_time;
	long							sleep_time;
	long							start_time;
	int								meal_num;
	pthread_t						t[200];
	pthread_mutex_t					*lock;
	pthread_mutex_t					print;
	pthread_mutex_t					death;
	pthread_mutex_t					meal_time_mutex;
	pthread_mutex_t					n_meal;
	pthread_mutex_t					sleep;
	t_philo							*philo;
	int								flag_check;
}									t_data;

int									ft_atoi(const char *str);
void								ft_sleep(long mili_sec);
long								get_time(void);
int									check_num(char *num);
int									parssing(int ac, char **av);
void								get_data(char **av, t_data *data);
void								init_struct(char **av, t_data *data);
void								print_str(t_philo *philo, char	*str,
										int i);
int									check_meals(t_data *data);

#endif
