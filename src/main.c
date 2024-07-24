/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:04:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/24 18:01:31 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philos[MAX_PHILO];
	mutex	forks[MAX_PHILO];

	gettimeofday(&data.start, NULL);
	if (check_args(ac, av, &data) == 1)
	{
		error(ERROR_ARG);
		return (1);
	}
	init_data(&data, forks);
	init_forks(&data);
	init_philo(philos, &data);
	make_threads(philos, &data);
}

// Tout delete, mon if_stop juste faire en sorte qu'il check si le
// dead_flag est egale a 1, et mettre mon calcul de verif de mort dans 
// une mini fonction que j'apellerais a chaque fois avant de faire 
// une action importtante du genre take a fork 