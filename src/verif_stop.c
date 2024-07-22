/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/22 16:53:10 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	if_stop(t_data *data, t_philo *philos)
{
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->dead_flag == 1)
		{
			pthread_mutex_unlock(&data->dead_lock);
			return ;
		}
		pthread_mutex_unlock(&data->dead_lock);
		pthread_mutex_lock(&data->eat_lock);
		if (data->nb_eat > 0)
			if (data->nb_eat == philos[0].eating)
			{
				pthread_mutex_unlock(&data->eat_lock);
				return ;
			}
		pthread_mutex_unlock(&data->eat_lock);
	}
	return ;
}
