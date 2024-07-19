/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:43 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/19 11:00:07 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, t_philo philos[], mutex	forks[])
{
	data->dead_flag = 0;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->philos = philos;
	data->forks = forks;
}

void	init_forks(t_data *data, mutex forks[])
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philo(t_data *data, t_philo philo[], mutex forks[])
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].num = i;
		philo[i].eating = 0;
		philo[i].dead = 0;
		philo[i].dead_lock = &data->dead_lock;
		philo[i].eat_lock = &data->eat_lock;
		philo[i].write_lock = &data->write_lock;
		philo[i].l_fork = forks[i];
		if (i == 0)
			philo[i].r_fork = forks[data->nb_philo - 1];
		else
			philo[i].r_fork = forks[i - 1];
		i++;
	}
}
