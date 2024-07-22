/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/22 16:47:28 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	make_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->nb_philo)
	{
		if (pthread_create(philos[i].thread, NULL, &routine, &philos[i]) 
			!= 0);
			return (free_all(data), -1);
		i++;
	}
	if_stop(data, philos);
	while (i >= 0)
	{
		pthread_join(philos[i].thread, NULL);
		i--;
	}
	free_all(philos);
	return (0);
}
