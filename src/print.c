/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:12:33 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/25 13:15:30 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *str, long time)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (philo->data->dead_flag == 0)
		printf("%ld %d %s\n", time, philo->num, str);
	else if (philo->data->eat_flag == 1 && philo->data->one_time == 0)
	{
		philo->data->one_time = 1;
		printf("%ld %d %s\n", time, philo->num, "ALL EATTTTTTTTT");
	}
	else if (philo->data->one_time == 0)
	{
		philo->data->one_time = 1;
		printf("%ld %d %s\n", time, philo->num, "died");
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}
