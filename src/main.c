/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:04:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/25 15:33:38 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av) // gerer les impairs et le 1 et 2 philo 
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
