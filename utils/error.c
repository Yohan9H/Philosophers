/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:44:26 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/25 16:39:39 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nb_philo)
	{
		pthread_mutex_destroy(&(philos[i].data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&philos->data->dead_lock);
	pthread_mutex_destroy(&philos->data->eat_lock);
	pthread_mutex_destroy(&philos->data->write_lock);
}

void	error(int code_error)
{
	if (code_error == ERROR_ARG)
		write(2, "Error Argument\n", 15);
}
