/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:04:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/22 16:29:56 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philos[MAX_PHILO];
	mutex	forks[MAX_PHILO];
	int		i;

	if (check_args(ac, av, &data) == 1)
	{
		error(ERROR_ARG);
		return (1);
	}
	init_data(&data, philos, forks);
	init_forks(&data);
	init_philo(philos, &data);
	make_threads(philos, &data);
}
