/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:44:26 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/23 13:05:49 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_philo)
	{
		pthread_mutex_destroy(philos[i].dead_lock);
		pthread_mutex_destroy(philos[i].write_lock);
		pthread_mutex_destroy(philos[i].eat_lock);
		if (i != philos->data->nb_philo - 1)
			pthread_mutex_destroy(&philos[i].l_fork);
		pthread_mutex_destroy(&philos[i].r_fork);
		i++;
	}
	pthread_mutex_destroy(&philos->data->dead_lock);
	pthread_mutex_destroy(&philos->data->eat_lock);
	pthread_mutex_destroy(&philos->data->write_lock);
	pthread_mutex_destroy(philos->data->forks);
}

void	error(int code_error)
{
	if (code_error == ERROR_ARG)
		write(2, "Error Argument\n", 15);
}