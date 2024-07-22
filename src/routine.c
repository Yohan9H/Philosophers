/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:48:25 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/22 16:58:22 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	print_status(philo, "has taken a fork", NULL);
	pthread_mutex_lock(&philo->eat_lock);
	print_status(philo, "is eating", NULL);
	usleep(philo->time_to_eat);
	philo->eating++;
	pthread_mutex_unlock(&philo->eat_lock);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	// add time
}

void	sleep(t_philo *philo)
{
	print_status(philo, "is sleeping", NULL);
	usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking", NULL);
	usleep(philo->time_to_sleep);
}
 
int	routine(t_philo *philo)
{
	size_t	i;
	t_time	time;

	i = 0;
	while (philo->data->dead_flag != 1)
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
}
