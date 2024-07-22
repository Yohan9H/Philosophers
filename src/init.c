/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:53:43 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/22 17:22:33 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Ajouter le temps 

void	init_data(t_data *data, t_philo philos[], mutex	forks[])
{
	data->dead_flag = 0;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	data->forks = forks;
}

void	init_forks(t_data *data) 
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philo *philos, t_data *data)
{
	int	i;
	int	nb_p;

	nb_p = data->nb_philo;
	i = 0;
	while (i < data->nb_philo)
	{
		philos[i].data = data;
		philos[i].num = i;
		philos[i].eating = 0;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].eat_lock = &data->eat_lock;
		philos[i].write_lock = &data->write_lock;
		philos[i].l_fork = philos[i].data->forks[i];
		if (i == 0)
			philos[i].r_fork = philos[i].data->forks[nb_p - 1];
		else
			philos[i].r_fork = philos[i].data->forks[i - 1];
		i++;
	}
}
