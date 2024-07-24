/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:12:33 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/24 17:46:06 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *str, long time)
{
	// pthread_mutex_lock(&(philo->data->dead_lock));
	// if (philo->data->dead_flag == 0 && philo->data->one_time == 0)
	// {
	// 	pthread_mutex_unlock(&(philo->data->dead_lock));
	pthread_mutex_lock(&philo->data->write_lock);
	if (if_dead(philo) == 0)
		printf("%ld %d %s\n", time, philo->num, str);
	pthread_mutex_unlock(&philo->data->write_lock);
	// 	return ;
	// }
	// else if (philo->data->dead_flag == 1 && philo->data->one_time == 0)
	// {
	// 	philo->data->one_time = 1;
	// 	pthread_mutex_unlock(&(philo->data->dead_lock));
	// 	pthread_mutex_lock(&philo->data->write_lock);
	// 	printf("%ld %d %s\n", time, philo->num, "died");
	// 	pthread_mutex_unlock(&philo->data->write_lock);
	// 	return ;
	// }
	// pthread_mutex_unlock(&(philo->data->dead_lock));
}

int	if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead_flag == 0)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (1);
	}
}