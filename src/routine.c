/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:48:25 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/24 17:53:37 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
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
		pthread_mutex_lock(philo->r_fork);
		print_status(philo, "has taken a fork", give_time(philo->data));
		pthread_mutex_lock(philo->l_fork);
		print_status(philo, "has taken a fork", give_time(philo->data));
	}
}

// faire condition pour 1 philo
void	ft_eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_lock(&philo->data->eat_lock);
	philo->last_eat = give_time(philo->data);
	ft_usleep(philo->time_to_eat, philo->data);
	philo->eating++;
	pthread_mutex_unlock(&philo->data->eat_lock);

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
	while (if_dead(philo) == 0)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
