/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/19 11:27:52 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	if_stop(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->dead_flag == 1)
		{
			pthread_mutex_unlock(&data->dead_lock);
			break;
		}
		pthread_mutex_unlock(&data->dead_lock);
		pthread_mutex_lock(&data->eat_lock);
		if (data->nb_eat > 0)
			if (data->nb_eat == data->philos[0].eating)
			{
				pthread_mutex_unlock(&data->eat_lock);
				break;
			}
		pthread_mutex_unlock(&data->eat_lock);
	}
	return (0);
}
