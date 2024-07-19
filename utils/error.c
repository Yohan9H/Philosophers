/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:44:26 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/19 10:35:36 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(data->philos[i].dead_lock);
		pthread_mutex_destroy(data->philos[i].write_lock);
		pthread_mutex_destroy(data->philos[i].eat_lock);
		if (i != data->nb_philo - 1)
			pthread_mutex_destroy(&data->philos[i].l_fork);
		pthread_mutex_destroy(&data->philos[i].r_fork);
		i++;
	}
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->eat_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->forks);
}

void	error(int code_error)
{
	if (code_error == ERROR_ARG)
		write(2, "Error Argument\n", 15);
}