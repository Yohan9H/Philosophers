/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/23 19:42:44 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	if_stop(t_data *data, t_philo *philos)
{
	int 	i;
	long	current_time;

	i = 0;
	while (1)
	{
		while(i < data->nb_philo)
		{
			current_time = give_time(data);
			pthread_mutex_lock(&data->dead_lock);
			if (current_time - philos[i].last_eat > data->set_t_die)
			{
				data->dead_flag = 1;
				pthread_mutex_unlock(&data->dead_lock);
				print_status(&philos[i], "died", give_time(data));
				return ;
			}
			pthread_mutex_unlock(&data->dead_lock);
			pthread_mutex_lock(&data->eat_lock);
			if (data->nb_eat > 0)
				if (philos[0].eating > data->nb_eat) // ne fonctionne pas
				{
					pthread_mutex_unlock(&data->eat_lock);
					return ;
				}
			pthread_mutex_unlock(&data->eat_lock);
			i++;
		}
		i = 0;
	}
	return ;
}
