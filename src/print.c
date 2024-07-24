/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:12:33 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/24 13:31:42 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *str, long time)
{
	if (philo->data->dead_flag == 0 && philo->data->one_time == 0)
	{
		pthread_mutex_lock(philo->write_lock);
		printf("%ld %d %s\n", time, philo->num, str);
		pthread_mutex_unlock(philo->write_lock);
	}
	else if (philo->data->dead_flag == 1 && philo->data->one_time == 0)
	{
		pthread_mutex_lock(&philo->data->dead_lock);
		philo->data->one_time = 1;
		printf("%ld %d %s\n", time, philo->num, "died");
		pthread_mutex_unlock(&philo->data->dead_lock);
	}
}
