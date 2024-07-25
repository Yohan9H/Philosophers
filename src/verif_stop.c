/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/25 13:35:49 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
//"valgrind --tool=helgrind ./philosophers 5 800 200 200"

void	if_stop(t_data *data, t_philo *philos)
{
	int 	i;

	i = 0;
	while (1)
	{
		while(i < data->nb_philo)
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
				if (philos[i].eating >= data->nb_eat)
				{
					data->philo_eat_max++;
					if (data->philo_eat_max >= data->nb_eat)
					{
						data->eat_flag = 1;
						printf("NB_EAT_MAX : %d\n", data->philo_eat_max);
						pthread_mutex_unlock(&data->eat_lock);
						return ;
					}
				}
			pthread_mutex_unlock(&data->eat_lock);
			i++;
		}
		i = 0;
	}
	return ;
}
