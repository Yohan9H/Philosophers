/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:36:01 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 15:12:04 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	give_time(t_data *data)
{
	timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec - data->start.tv_sec) * 1000) 
		+ ((time.tv_usec - data->start.tv_usec) / 1000));
}

int	ptc_dead_flag(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	if (data->dead_flag == 0)
	{
		pthread_mutex_unlock(&data->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (1);
}

int	ft_usleep(size_t mseconds, t_data *data)
{
	size_t	start;

	start = give_time(data);
	while (ptc_dead_flag(data) == 0 && (give_time(data) - start) < mseconds)
	{
		usleep(50);
	}
	return (0);
}
