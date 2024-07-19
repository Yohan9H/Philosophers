/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:47:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/19 12:00:35 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	make_threads(t_data *data)
{
	pthread_t	verif_stop;
	int			i;

	i = 0;
	if (pthread_create(&verif_stop, NULL, &if_stop, data->philos) == 0)
		return (free_all(data), -1);
	while (i <= data->nb_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data) 
			!= 0);
			return (free_all(data), -1);
		i++;
	}
	// Si ici = philo mort donc :
	// join le thread verif_stop;
	// join tous les threads des philos
}