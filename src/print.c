/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:12:33 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 11:57:26 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	protect_one_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->one_time == 0)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	return (1);
}

void	print_status(t_philo *philo, char *str, long time)
{
	if (if_dead(philo) == 0 && if_eat_finish(philo) == 0)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		printf("%ld %d %s\n", time, philo->num, str);
		pthread_mutex_unlock(&philo->data->write_lock);
	}
	else if (if_eat_finish(philo) == -1 && protect_one_time(philo) == 0)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		philo->data->one_time = 1;
		printf("%ld %s\n", time, "all philo ate");
		pthread_mutex_unlock(&philo->data->write_lock);
	}
	else if (if_dead(philo) == -1 && protect_one_time(philo) == 0)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		philo->data->one_time = 1;
		printf("%ld %d %s\n", time, philo->num, "died");
		pthread_mutex_unlock(&philo->data->write_lock);
	}
}
