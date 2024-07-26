/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:53:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 11:35:20 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	verif_all_philo_eat(t_data *data)
{
	pthread_mutex_lock(&data->eat_lock);
	if (data->philo_eat_max >= data->nb_philo)
	{
		data->eat_flag = 1;
		pthread_mutex_unlock(&data->eat_lock);
		return (-1);
	}
	pthread_mutex_unlock(&data->eat_lock);
	return (0);
}

void	verif_philo_eat(t_data *data, t_philo *philos, int i)
{
	pthread_mutex_lock(&data->eat_lock);
	if (data->nb_eat > 0 && philos[i].eating >= data->nb_eat)
	{
		data->philo_eat_max++;
	}
	pthread_mutex_unlock(&data->eat_lock);
}

int	if_one_philo(t_data *data)
{
	pthread_mutex_lock(&data->write_lock);
	if (data->nb_philo == 1)
	{
		pthread_mutex_unlock(&data->write_lock);
		return (-1);
	}
	pthread_mutex_unlock(&data->write_lock);
	return (0);
}

void	if_stop(t_data *data, t_philo *philos)
{
	int 	i;

	i = 0;
	if (if_one_philo(data) == -1)
		return ;
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
			verif_philo_eat(data, philos, i);
			i++;
		}
		if (verif_all_philo_eat(data) == -1)
			return ;
		data->philo_eat_max = 0;
		i = 0;
	}
	return ;
}
