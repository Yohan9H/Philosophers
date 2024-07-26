/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:04:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/26 17:31:05 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
//"valgrind --tool=helgrind ./philosophers 5 800 200 200"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philos[MAX_PHILO];
	t_mutex	forks[MAX_PHILO];

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
