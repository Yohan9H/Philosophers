/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:36:01 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/25 11:22:43 by yohurteb         ###   ########.fr       */
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
	while ((give_time(data) - start) < milliseconds)
		usleep(50);
	return (0);
}