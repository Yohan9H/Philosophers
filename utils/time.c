/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:36:01 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 09:40:57 by yohan.h          ###   ########.fr       */
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

int	ft_usleep(size_t milliseconds, t_data *data)
{
	size_t	start;

	start = give_time(data);
	pthread_mutex_lock(&data->dead_lock);
	while (data->dead_flag == 0 && (give_time(data) - start) < milliseconds)
	{
		pthread_mutex_unlock(&data->dead_lock);
		usleep(50);
	}
	pthread_mutex_unlock(&data->dead_lock);
	return (0);
}
