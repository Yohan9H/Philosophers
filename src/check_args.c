/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:25:36 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/23 11:37:59 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_nb(int ac, char **av, t_data *data)
{
	if (ft_atoi(av[1]) == -1 || ft_atoi(av[2]) == -1 || ft_atoi(av[3]) == -1 
		|| ft_atoi(av[4]) == -1 || ft_atoi(av[1]) > 200)
		return (-1);
	data->nb_philo = ft_atoi(av[1]);
	data->set_t_die = ft_atoi(av[2]);
	data->set_t_eat = ft_atoi(av[3]);
	data->set_t_sleep = ft_atoi(av[4]);
	if (ac ==  6)
	{
		if (ft_atoi(av[5]) == -1)
			return (-1);
		data->nb_eat = ft_atoi(av[5]);
	}
	else
		data->nb_eat = 0;
	return (0);
}

int	check_args(int ac, char **av, t_data *data)
{
	if (ac == 5 || ac == 6)
	{
		if (check_nb(ac, av, data) == -1)
			return (1);
	}
	else
		return (1);
	return (0);
}
