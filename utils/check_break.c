/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_break.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:07:30 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 16:28:08 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	verif_dead_flag(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	if (data->dead_flag == 1)
	{
		pthread_mutex_unlock(&data->dead_lock);
		return (-1);
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (0);
}

int	check_break(t_philo *philo)
{
	if (verif_dead_flag(philo->data) == -1 || if_eat_finish(philo) == -1)
	{
		print_status(philo, "", give_time(philo->data));
		return (-1);
	}
	return (0);
}
