/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:48:25 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/23 19:38:40 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo) // faire condition pour 1 philo
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
	print_status(philo, "has taken a fork", give_time(philo->data));
	print_status(philo, "is eating", give_time(philo->data));
	pthread_mutex_lock(philo->eat_lock);
	philo->last_eat = give_time(philo->data);
	ft_usleep(philo->time_to_eat, philo->data);
	philo->eating++;
	pthread_mutex_unlock(philo->eat_lock);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
}

void	ft_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping", give_time(philo->data));
	ft_usleep(philo->time_to_sleep, philo->data);
}

void	ft_think(t_philo *philo)
{
	print_status(philo, "is thinking", give_time(philo->data));
}
 
void	*routine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	while (philo->data->dead_flag != 1)
	{
		ft_eat(philo);
		if (philo->data->dead_flag == 1)
			return (NULL);
		ft_sleep(philo);
		if (philo->data->dead_flag == 1)
			return (NULL);
		ft_think(philo);
	}
	return (NULL);
}
