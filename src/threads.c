/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/28 14:42:09 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork_long(t_philo *philo)
{
	if (philo->num % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork", give_time(philo->data));
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork", give_time(philo->data));
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork", give_time(philo->data));
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork", give_time(philo->data));
	}
}

int	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		print_status(philo, "is thinking", give_time(philo->data));
		print_status(philo, "has taken a fork", give_time(philo->data));
		ft_usleep(philo->time_to_die, philo->data);
		pthread_mutex_lock(&philo->data->dead_lock);
		philo->data->dead_flag = 1;
		pthread_mutex_unlock(&philo->data->dead_lock);
		print_status(philo, "", give_time(philo->data));
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	return (0);
}

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
	long	current_time;
	long	last_e;

	pthread_mutex_lock(&philo->data->eat_lock);
	last_e = philo->last_eat;
	pthread_mutex_unlock(&philo->data->eat_lock);
	current_time = give_time(philo->data);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (-1);
	}
	else if (current_time - last_e > philo->data->set_t_die)
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
