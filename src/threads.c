/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/25 13:28:33 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	if_eat_finish(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_lock);
	if (philo->data->eat_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->eat_lock);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->eat_lock);
	return (0);
}

int	if_dead(t_philo *philo)
{
	long current_time;

	current_time = give_time(philo->data);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (-1);
	}
	else if (current_time - philo->last_eat > philo->data->set_t_die)
	{
		philo->data->dead_flag = 1;
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (0);
}

int	make_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) 
			!= 0)
			return (free_all(philos), -1);
		i++;
	}
	if_stop(data, philos);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	free_all(philos);
	return (0);
}
